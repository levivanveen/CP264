/*
 * -----------------------------------------------------
 * Course: 		CP264: Fall 2021
 * Author: 		Qutaiba Albluwi
 * Category: 	Linked List (Testing File)
 * -----------------------------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "data.h"
#include "list.h"
# include "process.h"

void test_node();
void test_append();
void test_arrayToList();
void test_remove_rear();
void test_getNode();
void test_reverse();

int main() {
	setbuf(stdout, NULL);
	srand(time(NULL));

	test_node();
	test_append();
	test_arrayToList();
	test_getNode();
	test_reverse();
	test_remove_rear();
	return 0;
}

void test_node() {
	printf("------------------------------\n");
	printf("Start: Testing Linked List Node:\n\n");

	printf("Create process ");
	Data *d = create_process(1000010000, 20, 40);
	print_process(d);
	printf("\n");
	printf("Create a node with the above process\n");
	Node *n1 = create_node(d, NULL);
	printf("Print node: ");
	print_node(n1);
	printf("\n\n");

	printf("Create another node:\n");
	Node *n2 = create_node(create_process(1000010001, 10, 30), NULL);
	print_node(n2);
	printf("\n\n");
	printf("link two nodes together:\n");
	n1->next = n2;
	printf("Print node 2 through node 1:\n");
	print_node(n1->next);
	printf("\n\n");

	printf("Copy Node 1 to node 3:\n");
	Node *n3 = copy_node(n1);
	printf("Print node 3:\n");
	print_node(n3);
	printf("\n");
	printf("Print node 2 through node 3:\n");
	print_node(n3->next);
	printf("\n\n");

	printf("Destroy node 1\n");
	destroy_node(&n1);
	printf("Destroy node 2\n");
	destroy_node(&n2);
	printf("Destroy node 3\n");
	destroy_node(&n3);
	printf("\n");

	printf("End: Testing Linked List Node\n");
	printf("------------------------------\n\n");
	return;
}

void test_append() {
	printf("------------------------------\n");
	printf("Start: Testing Linked List append:\n\n");

	List *list = create_list();
	printf("Create an empty list:\n");
	print_list(list);
	printf("\n");

	printf("Appending to an empty linked list\n");
	Data *d1 = create_process(1000010000, 20, 40);
	append_list(list, d1);
	print_list(list);
	printf("\n");

	printf("Appending second element\n");
	Data *d2 = create_process(1000010001, 10, 15);
	append_list(list, d2);
	print_list(list);
	printf("\n");

	printf("Appending third element\n");
	Data *d3 = create_process(1000010002, 60, 36);
	append_list(list, d3);
	print_list(list);
	printf("\n");

	printf("destroy linked list\n");
	destroy_list(&list);
	printf("\n");

	printf("End: Testing Linked List append\n");
	printf("------------------------------\n\n");
	return;
}

void test_arrayToList() {
	printf("------------------------------\n");
	printf("Start: Testing array_to_list function:\n\n");

	Data dataList[10];
	int i, size = 10, arrival = 10, time = 1;
	long long pid = 1000010000;

	printf("Creating an array of 10 Data (Process) Objects:\n");
	for (i = 0; i < size; i++) {
		dataList[i] = *create_process(pid++, time++, arrival++);
		print_data(&dataList[i]);
		printf("\n");
	}
	printf("\n");

	printf("Creating an empty linked list:\n");
	List *list = create_list();
	print_list(list);
	printf("\n");

	printf("Contents of the list after invoking array_to_List:\n");
	list = array_to_list(dataList, size);
	print_list(list);
	printf("Number of elements: %d\n", list->size);

	printf("\ndestroy linked list\n");
	destroy_list(&list);
	printf("\n");

	printf("End: Testing aray_to_list function\n");
	printf("------------------------------\n\n");
	return;
}

void test_remove_rear() {
	printf("------------------------------\n");
	printf("Start: Testing list remove_rear function:\n\n");

	List *list = create_list();
	int i, arrival = 10, time = 1;
	long long pid = 1000010001;

	printf("Create a list with 8 items:\n");
	for (i = 0; i < 8; i++)
		append_list(list, create_process(pid++, time++, arrival++));
	print_list(list);
	printf("\n");

	for (i = 0; i < 9; i++) {
		Data *d = remove_rear_list(list);
		printf("Removed item = ");
		if (d)
			print_data(d);
		else
			printf("NULL");
		printf("\n");
		print_list(list);
		printf("\n");
	}

	printf("End: Testing list remove_rear function\n");
	printf("------------------------------\n\n");
	return;
}
void test_getNode() {
	printf("------------------------------\n");
	printf("Start: Testing List get_node function:\n\n");

	Data dataList[10];
	int i, size = 10, arrival = 10, time = 1;
	long long pid = 1000010000;

	printf("Creating a linked list with 10 random process:\n");
	for (i = 0; i < size; i++)
		dataList[i] = *create_process(pid++, time++, arrival++);
	List *list = array_to_list(dataList, size);
	print_list(list);
	printf("\n");

	printf("Get item 0:\n");
	print_node(get_node_list(list, 0));
	printf("\n\n");

	printf("Get item 3:\n");
	print_node(get_node_list(list, 3));
	printf("\n\n");

	printf("Get item 9:\n");
	print_node(get_node_list(list, 9));
	printf("\n\n");

	printf("Get item 10:\n");
	if (get_node_list(list, 10) == NULL)
		printf("NULL\n");

	printf("\ndestroy linked list\n");
	destroy_list(&list);
	printf("\n");

	printf("End: Testing List get_node function\n");
	printf("------------------------------\n\n");
}

void test_reverse() {
	printf("------------------------------\n");
	printf("Start: Testing List reverse function:\n\n");

	int i, arrival = 10, time = 1;
	long long pid = 1000010000;

	printf("Case 1: An Empty List\n");
	List *list = create_list();
	print_list(list);
	printf("After calling reverse function:\n");
	reverse_list(list);
	print_list(list);
	printf("\n");

	printf("Case 1: Single item List\n");
	append_list(list, create_process(pid++, time++, arrival++));
	print_list(list);
	printf("After calling reverse function:\n");
	reverse_list(list);
	print_list(list);
	printf("\n");

	printf("Case 2: List with two items\n");
	append_list(list, create_process(pid++, time++, arrival++));
	print_list(list);
	printf("After calling reverse function:\n");
	reverse_list(list);
	print_list(list);
	printf("\n");

	printf("Case 3: List with 10 items\n");
	for (i = 0; i < 8; i++)
		append_list(list, create_process(pid++, time++, arrival++));
	print_list(list);
	printf("After calling reverse function:\n");
	reverse_list(list);
	print_list(list);
	printf("\n");

	printf("destroy linked list\n");
	destroy_list(&list);
	printf("\n");

	printf("End: Testing List reverse function\n");
	printf("------------------------------\n\n");
	return;
}
