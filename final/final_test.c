#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "final.h"

void test_sort_stacks();
void test_delete_mid();
void test_mdata();

void print_doubles(double *array, const int size, FILE *fptr);
void print_floats(float *array, const int size, FILE *fptr);

int main() {
	setbuf(stdout, NULL);
	test_sort_stacks();
	test_delete_mid();
	test_mdata();
	return 0;
}

void test_sort_stacks() {
	printf("------------------------------\n");
	printf("Start testing: sort_stacks:\n\n");

	Data array[50];
	Stack *s1 = NULL, *s2 = NULL, *s3 = NULL, *s4 = NULL, *s5 = NULL, *output =
	NULL;
	Stack *ptr[5];
	ptr[0] = s1;
	ptr[1] = s2;
	ptr[2] = s3, ptr[3] = s4;
	ptr[4] = s5;
	int i;

	for (i = 0; i < 50; i++)
		array[i] = (Data) i;

	printf("Case 1:\n");
	s1 = create_stack(2);
	for (i = 0; i < 4; i = i + 2)
		push_stack(s1, &array[i + 10]);
	print_stack(s1);
	s2 = create_stack(2);
	for (i = 1; i < 5; i = i + 2)
		push_stack(s2, &array[i + 10]);
	print_stack(s2);
	ptr[0] = s1;
	ptr[1] = s2;
	ptr[2] = NULL;
	ptr[3] = NULL;
	ptr[4] = NULL;
	output = sort_stacks(ptr, 2);
	printf("output:\n");
	print_stack(output);
	destroy_stack(&s1);
	destroy_stack(&s2);
	destroy_stack(&output);
	printf("\n");

	printf("Case 2:\n");
	s1 = create_stack(5);
	for (i = 0; i < 5; i++)
		push_stack(s1, &array[i + 10]);
	print_stack(s1);
	s2 = create_stack(3);
	for (i = 0; i < 3; i++)
		push_stack(s2, &array[i + 13]);
	print_stack(s2);
	ptr[0] = s1;
	ptr[1] = s2;
	ptr[2] = NULL;
	ptr[3] = NULL;
	ptr[4] = NULL;
	output = sort_stacks(ptr, 2);
	printf("output:\n");
	print_stack(output);
	destroy_stack(&s1);
	destroy_stack(&s2);
	destroy_stack(&output);
	printf("\n");

	printf("Case 3:\n");
	s1 = create_stack(4);
	for (i = 0; i < 4; i++)
		push_stack(s1, &array[i + 10]);
	print_stack(s1);
	s2 = create_stack(6);
	for (i = 0; i < 6; i++)
		push_stack(s2, &array[i + 5]);
	print_stack(s2);
	s3 = create_stack(5);
	for (i = 0; i < 10; i = i + 2)
		push_stack(s3, &array[i + 7]);
	print_stack(s3);
	ptr[0] = s1;
	ptr[1] = s2;
	ptr[2] = s3;
	ptr[3] = NULL;
	ptr[4] = NULL;
	output = sort_stacks(ptr, 3);
	printf("output:\n");
	print_stack(output);
	destroy_stack(&s1);
	destroy_stack(&s2);
	destroy_stack(&output);
	printf("\n");

	printf("End Testing: sort_stacks\n");
	printf("------------------------------\n\n");

	return;
}

//------------- Task 2: delete_mid -----------------
void test_delete_mid() {
	printf("------------------------------\n");
	printf("Start testing: delete_mid:\n\n");

	int i, index;
	Data *d;
	List *list = create_list();
	printf("Create Linked list with 5 elements\n");
	for (i = 0; i < 5; i++) {
		d = create_data((i + 1) * 10);
		append_list(list, d);
	}
	print_list(list);
	printf("\n");

	printf("calling delete_mid_list:\n"); //size = 5
	index = delete_mid_list(list);
	printf("Index of deleted item = %d, list after deletion:\n", index);
	print_list(list);
	printf("\n");

	printf("calling delete_mid_list:\n"); //size = 4
	index = delete_mid_list(list);
	printf("Index of deleted item = %d, list after deletion:\n", index);
	print_list(list);
	printf("\n");

	printf("calling delete_mid_list:\n"); //size = 3
	index = delete_mid_list(list);
	printf("Index of deleted item = %d, list after deletion:\n", index);
	print_list(list);
	printf("\n");

	printf("calling delete_mid_list:\n"); //size = 2
	index = delete_mid_list(list);
	printf("Index of deleted item = %d, list after deletion:\n", index);
	print_list(list);
	printf("\n");

	printf("calling delete_mid_list:\n"); //size = 1
	index = delete_mid_list(list);
	printf("Index of deleted item = %d, list after deletion:\n", index);
	print_list(list);
	printf("\n");

	printf("calling delete_mid_list:\n"); //size = 0
	index = delete_mid_list(list);
	printf("Index of deleted item = %d, list after deletion:\n", index);
	print_list(list);
	printf("\n");

	printf("destroy linked list\n");
	destroy_list(&list);

	printf("End Testing: delete_mid\n");
	printf("------------------------------\n\n");
	return;
}

//-------------- Task 3: mdata -------------------------------
void test_mdata() {
	printf("------------------------------\n");
	printf("Start: Testing MData:\n\n");

	printf("Testing create_mdata:\n");
	int pid = 1000010000, arrival = 30, time = 1;
	Process *p = create_process(pid++, time++, arrival++);
	MData *d1 = create_mdata(p, 'p');
	if (d1 && d1->type == 'p')
		printf("MData of type p created successfully\n");

	int *num1 = (int*) malloc(sizeof(int));
	*num1 = 10;
	MData *d2 = create_mdata(num1, 'i');
	if (d2 && d2->type == 'i')
		printf("MData of type i created successfully\n");

	MData *d3 = create_mdata(num1, 'f');
	MData *d4 = create_mdata(NULL, 'i');
	printf("\n");

	printf("Testing print_mdata:\n");
	print_mdata(d1);
	print_mdata(d2);
	d2->type = 'f';
	print_mdata(d2);
	d2->type = 'i';
	print_mdata(d3);
	printf("\n");

	printf("Testing copy_mdata:\n");
	d3 = copy_mdata(d1);
	printf("Copy data of type p: ");
	print_mdata(d3);
	printf("Copy data of type i: ");
	d4 = copy_mdata(d2);
	print_mdata(d4);
	d2->type = 'f';
	printf("Copy data of type f: ");
	MData *d5 = copy_mdata(d2);
	print_mdata(d5);
	printf("\n");
	printf("Testing destroy_mdata:\n");
	destroy_mdata(&d1);
	printf("mdata of type p successfully destroyed\n");
	destroy_mdata(&d2);
	printf("mdata of type i successfully destroyed\n");
	printf("\n");

	printf("End: Testing MData\n");
	printf("------------------------------\n\n");
	return;
}
//------------- utility functions --------------------
void print_floats(float *array, const int size, FILE *fptr) {
	int i;
	fprintf(fptr, "[ ");
	for (i = 0; i < size - 1; i++)
		fprintf(fptr, "%.2f , ", array[i]);
	fprintf(fptr, "%.2f ]\n", array[i]);
	return;
}

void print_doubles(double *array, const int size, FILE *fptr) {
	if (array == NULL) {
		printf("Error(print_doubles): invalid array\n");
		return;
	}
	int i;
	fprintf(fptr, "[ ");
	for (i = 0; i < size - 1; i++)
		fprintf(fptr, "%.2lf , ", array[i]);
	fprintf(fptr, "%.2lf ]\n", array[i]);
	return;
}
