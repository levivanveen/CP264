# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#include "heap.h"

void test_basic_heap();
void test_insert_remove_heap();
void test_contains();
void test_RLP();
void test_heap_sort();

int main() {
	setbuf(stdout, NULL);
	test_basic_heap();
	test_RLP();
	test_contains();
	test_insert_remove_heap();
	test_heap_sort();
	return 0;
}

void test_RLP() {
	printf("------------------------------\n");
	printf("Start: Testing Right(i), Left(i), Parent(i):\n\n");

	int i, capacity = 20;
	Heap *h = create_heap(capacity);
	printf("Creating a heap with capacity = 20\n");

	int values[20] = { 130, 40, 70, 120, 10, 30, 110, 180, 90, 170, 140, 190,
			50, 100, 20, 60, 200, 150, 80, 160 };
	Data *array = (Data*) malloc(sizeof(Data) * 20);
	for (i = 0; i < 20; i++)
		array[i] = values[i];

	printf("Inserting 20 integers\n");
	for (i = 0; i < 20; i++) {
		insert_heap(h, &array[i]);
	}
	print_heap(h);
	printf("\n");

	for (i = 0; i < h->size; i++)
		printf("i = %d\t Parent(i) = %d\t Left(i) = %d\t Right(i) = %d\n", i,
				Parent(i), Left(i), Right(i));
	printf("\n");

	destroy_heap(&h);
	printf("heap destroyed successfully\n\n");

	free(array);
	array = NULL;

	printf("End: Testing Right(i), Left(i), Parent(i)\n");
	printf("------------------------------\n\n");

	return;
}

void test_basic_heap() {
	printf("------------------------------\n");
	printf("Start: Testing heap basic functions:\n\n");

	Heap *h = create_heap(20);
	printf("heap created successfully with capacity 20\n\n");

	printf("print contents of heap:\n");
	print_heap(h);
	printf("\n");

	printf("is_empty_heap(h)? %d\n", is_empty_heap(h));
	printf("h->size = %d\n", h->size);
	printf("h->capacity = %d\n", h->capacity);
	printf("\n");

	destroy_heap(&h);
	printf("heap successfully destroyed\n\n");

	printf("End: Testing heap basic functions\n");
	printf("------------------------------\n\n");
}

void test_insert_remove_heap() {
	printf("------------------------------\n");
	printf("Start: Testing insert_heap & remove_heap:\n\n");

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

	printf("peek_heap = ");
	print_data(peek_heap(h));
	printf("\n\n");

	for (i = 0; i < 11; i++) {
		printf("remove heap root:\n");
		remove_heap(h);
		print_heap(h);
		printf("\n");
	}

	destroy_heap(&h);
	printf("heap successfully destroyed\n\n");

	free(array);
	array = NULL;
	printf("End: Testing insert_heap & remove_heap\n");
	printf("------------------------------\n\n");
	return;
}

void test_contains() {
	printf("------------------------------\n");
	printf("Start: Testing contains_heap:\n\n");

	Heap *h = create_heap(20);
	printf("Creating a heap with capacity 20\n");

	printf("inserting 10 integers\n");
	int values[10] = { 40, 70, 10, 30, 90, 50, 100, 20, 60, 80 };
	int i;
	Data *array = NULL;
	array = (int*) malloc(sizeof(int) * 10);
	for (i = 0; i < 10; i++)
		array[i] = values[i];
	for (i = 0; i < 10; i++)
		insert_heap(h, &array[i]);
	print_heap(h);
	printf("\n");

	int num = 300, *ptr = &num;
	printf("contains(%d) = %d\n", array[6], contains_heap(h, &array[6]));
	printf("contains(%d) = %d\n", array[3], contains_heap(h, &array[3]));
	printf("contains(%d) = %d\n", *ptr, contains_heap(h, ptr));
	printf("\n");

	destroy_heap(&h);
	printf("heap destroyed successfully\n");

	free(array);
	array = NULL;
	printf("End: Testing contains_heap\n");
	printf("------------------------------\n\n");

	return;

}

void test_heap_sort() {
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

	heap_sort(array, size);
	printf("Printing array after sorting: \n");
	print_data_array(array, size);
	printf("\n");

	free(array);
	array = NULL;
	printf("End: Testing heap_sort\n");
	printf("------------------------------\n\n");

	return;
}
