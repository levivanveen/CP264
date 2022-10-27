# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#include "heap.h"

void test_max_min();
void test_heapify_up();
void test_get_leaves();
void test_heap_sort2();

int main() {
	setbuf(stdout, NULL);
	test_max_min();
	test_heapify_up();
	test_get_leaves();
	test_heap_sort2();
	return 0;
}

void test_get_leaves() {
	printf("------------------------------\n");
	printf("Start: Testing get_leaves:\n\n");

	int i, capacity = 20, size = 13;
	Heap *h = create_heap(capacity);
	printf("Creating a heap with capacity = %d\n", capacity);

	int values[13] =
			{ 60, 70, 40, 90, 100, 30, 110, 80, 120, 160, 20, 130, 140 };
	Data *array = (Data*) malloc(sizeof(Data) * size);
	for (i = 0; i < size; i++)
		array[i] = values[i];

	int *leaves_array = (int*) malloc(sizeof(int) * size);
	int num_of_leaves = 0;

	num_of_leaves = get_leaves(h, leaves_array);
	printf("number of leaves = %d, leaves = ", num_of_leaves);
	for (i = 0; i < num_of_leaves; i++)
		printf("%d ", leaves_array[i]);
	printf("\n\n");

	for (i = 0; i < size; i++) {
		insert_heap(h, &array[i]);
		print_heap(h);
		num_of_leaves = get_leaves(h, leaves_array);
		printf("number of leaves = %d, leaves = ", num_of_leaves);
		for (int j = 0; j < num_of_leaves; j++)
			printf("%d ", leaves_array[j]);
		printf("\n\n");
	}

	destroy_heap(&h);
	printf("heap destroyed successfully\n\n");

	free(array);
	array = NULL;

	printf("End: Testing get_leaves\n");
	printf("------------------------------\n\n");

	return;
}

void test_max_min() {
	printf("------------------------------\n");
	printf("Start: Testing find_max_heap & find_min_heap:\n\n");

	int i, capacity = 20;
	Heap *h = create_heap(capacity);
	printf("Creating a heap with capacity = 20\n\n");

	int values[13] =
			{ 60, 70, 40, 90, 100, 30, 110, 80, 120, 160, 20, 130, 140 };
	Data *array = (Data*) malloc(sizeof(Data) * 13);
	for (i = 0; i < 13; i++)
		array[i] = values[i];

	Data *max_data = NULL, *min_data = NULL;

	max_data = find_max_heap(h);
	min_data = find_min_heap(h);
	printf("\n");

	for (i = 0; i < 13; i++) {
		insert_heap(h, &array[i]);
		print_heap(h);
		printf("max = ");
		max_data = find_max_heap(h);
		print_data(max_data);
		printf("\nmin = ");
		min_data = find_min_heap(h);
		print_data(min_data);
		printf("\n\n");
	}

	destroy_heap(&h);
	printf("heap destroyed successfully\n\n");

	free(array);
	array = NULL;

	printf("End: Testing find_max_heap & find_min_heap\n");
	printf("------------------------------\n\n");

	return;
}

void test_heapify_up() {
	printf("------------------------------\n");
	printf("Start: Testing heapify_up:\n\n");

	printf("Create a heap with capacity = 5\n");
	Heap *h = create_heap(5);
	print_heap(h);
	printf("\n");

	int values[10] = { 40, 70, 10, 30, 90, 50, 100, 20, 60, 80 };
	int i;
	Data *array = NULL;
	array = (int*) malloc(sizeof(int) * 10);
	for (i = 0; i < 10; i++)
		array[i] = values[i];

	for (i = 0; i < 10; i++) {
		printf("insert %d:\n", array[i]);
		insert_heap(h, &array[i]);
		print_heap(h);
		printf("\n");
	}

	destroy_heap(&h);
	printf("heap successfully destroyed\n\n");

	free(array);
	array = NULL;
	printf("End: Testing heapify_up\n");
	printf("------------------------------\n\n");
	return;
}

void test_heap_sort2() {
	printf("------------------------------\n");
	printf("Start: Testing heap_sort:\n\n");

	int i, size = 20;
	int values[20] = { 130, 40, 70, 120, 10, 30, 110, 180, 90, 170, 140, 190,
			50, 100, 20, 60, 200, 150, 80, 160 };
	Data *array = (Data*) malloc(sizeof(Data) * 20);
	for (i = 0; i < 20; i++)
		array[i] = values[i];

	printf("Printing array before sorting: \n");
	print_data_array(array, size);
	printf("\n");

	heap_sort2(array, size);
	printf("Printing array after sorting: \n");
	print_data_array(array, size);
	printf("\n");

	free(array);
	array = NULL;
	printf("End: Testing heap_sort\n");
	printf("------------------------------\n\n");

	return;
}
