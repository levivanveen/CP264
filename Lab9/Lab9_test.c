/*
 * -----------------------------------------------------
 * Course: 		CP264: Fall 2018
 * Author: 		Qutaiba Albluwi
 * Category: 	Linked List (Testing File)
 * -----------------------------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include "data.h"
#include "list.h"
# include "process.h"

void test_peek();
void test_remove_front_list();
void test_min_list();
void test_copy_list();

int main() {
	setbuf(stdout, NULL);

	test_peek();
	test_remove_front_list();
	test_min_list();
	test_copy_list();

	return 0;
}

void test_peek() {
	printf("------------------------------\n");
	printf("Start: Testing Linked List peek_list function:\n\n");

	List *list = create_list();
	int i = 0, arrival = 10, time = 1;
	long long pid = 1000010000;

	do {
		i++;
		printf("List = ");
		print_list(list);
		printf("peek = ");
		Data *item = peek_list(list);
		if (item) {
			print_data(item);
			printf("\n");
			destroy_data(&item);
		}
		insert_front_list(list, create_process(pid++, time++, arrival++));
		printf("\n");
	} while (i < 8);

	printf("destroy linked list\n");
	destroy_list(&list);
	printf("\n");

	printf("End: Testing Linked List peek_list function\n");
	printf("------------------------------\n\n");
	return;
}

void test_remove_front_list() {
	printf("------------------------------\n");
	printf("Start: Testing Linked List remove_front_list function:\n\n");

	List *list = create_list();
	int arrival = 10, time = 1;
	long long pid = 1000010000;

	printf("Create a linked list with 10 random processes:\n");
	for (int i = 0; i < 5; i++)
		append_list(list, create_process(pid++, time++, arrival++));
	print_list(list);
	printf("\n");

	printf("Call remove_front 6 times:\n");
	for (int i = 0; i < 6; i++) {
		Data *removed_item = remove_front_list(list);
		if (removed_item) {
			printf("Removed_item = ");
			print_data(removed_item);
			printf("\n");
			destroy_data(&removed_item);
		} else
			printf("Removed_item = NULL\n");
		printf("Linked List after removed:\n");
		print_list(list);
		printf("\n");
	}

	printf("destroy linked list\n");
	destroy_list(&list);
	printf("\n");

	printf("End: Testing List cut function\n");
	printf("------------------------------\n\n");
	return;
}

void test_min_list() {
	printf("------------------------------\n");
	printf("Start: Testing Linked List min_list function:\n\n");

	List *list = create_list();
	int i = 0, arrival = 80, time = 107;
	long long pid = 1000010000;

	do {
		i++;
		printf("List = ");
		print_list(list);
		printf("min = ");
		Data *item = min_list(list);
		if (item) {
			print_data(item);
			printf("\n");
			destroy_data(&item);
		}
		pid = pid + 5;
		arrival = (arrival % 19 + 37) % 29;
		time = time % 11 + 9;
		insert_front_list(list, create_process(pid, time, arrival));
		printf("\n");
	} while (i < 10);

	printf("destroy linked list\n");
	destroy_list(&list);
	printf("\n");

	printf("End: Testing min_list function\n");
	printf("------------------------------\n\n");
	return;
}

void test_copy_list() {
	printf("------------------------------\n");
	printf("Start: Testing Linked List copy_list function:\n\n");

	int arrival = 10, time = 1;
	long long pid = 1000010000;

	List *list1 = NULL, *list2 = NULL;

	list1 = create_list();
	printf("(Before): list1 = ");
	print_list(list1);
	printf("(After): list1 = ");
	list2 = copy_list(list1);
	print_list(list1);
	printf("list2 = ");
	print_list(list2);
	destroy_list(&list1);
	destroy_list(&list2);
	printf("\n");

	list1 = create_list();
	append_list(list1, create_process(pid++, time++, arrival++));
	printf("(Before): list1 = \n");
	print_list(list1);
	printf("(After): list1 = \n");
	list2 = copy_list(list1);
	print_list(list1);
	printf("list2 = \n");
	print_list(list2);
	destroy_list(&list1);
	destroy_list(&list2);
	printf("\n");

	list1 = create_list();
	for (int i = 0; i < 5; i++)
		append_list(list1, create_process(pid++, time++, arrival++));
	printf("(Before): list1 = \n");
	print_list(list1);
	printf("(After): list1 = \n");
	list2 = copy_list(list1);
	print_list(list1);
	printf("list2 = \n");
	print_list(list2);
	destroy_list(&list1);
	destroy_list(&list2);
	printf("\n");

	printf("End: Testing copy_list function\n");
	printf("------------------------------\n\n");
	return;
}
