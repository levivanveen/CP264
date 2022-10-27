#include "R9.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_bubble_sort();
void test_insertion_sort();
void test_selection_sort();
void test_quick_sort();
void test_merge_sort();
void test_search();

int* get_array(int);
int sizes[3] = { 1, 5, 10 };

int main() {
	setbuf(stdout, NULL);
	test_search();
	test_bubble_sort();
	test_insertion_sort();
	test_selection_sort();
	test_quick_sort();
	test_merge_sort();
	return 0;
}

void test_search() {
	printf("------------------------------\n");
	printf("Start: Testing Linear and Binary Search:\n\n");

	int *array = NULL;
	int values[6] = { 19, 37, 21, 69, 54, 51 };
	for (int i = 0; i < 3; i++) {
		array = get_array(i);
		printf("Searching the array: ");
		print_data_array(array, sizes[i]);
		for (int j = 0; j < 6; j++) {
			printf("linear_search(%d) = %4d\n", values[j],
					linear_search(array, sizes[i], values[j]));
			printf("linear_search_r(%d) = %2d\n", values[j],
					linear_search_r(array, sizes[i], values[j]));
			printf("binary_search(%d) = %4d\n", values[j],
					binary_search(array, sizes[i], values[j]));
			printf("binary_search_r(%d) = %2d\n", values[j],
					binary_search_r(array, sizes[i], values[j]));
			printf("\n");
		}
		free(array);
		array = NULL;
	}
	printf("End: Testing Linear and Binary Search\n");
	printf("------------------------------\n\n");
	return;
}

void test_bubble_sort() {
	printf("------------------------------\n");
	printf("Start: Testing Bubble Sort:\n\n");

	int *array = NULL;
	for (int i = 0; i < 3; i++) {
		array = get_array(i + 3);
		printf("Sorting array %d:\n", i);
		bubble_sort(array, sizes[i]);
		print_data_array(array, sizes[i]);
		free(array);
		array = NULL;
		printf("\n");
	}
	printf("End: Testing Bubble Sort\n");
	printf("------------------------------\n\n");
	return;
}

void test_selection_sort() {
	printf("------------------------------\n");
	printf("Start: Testing Selection Sort:\n\n");

	int *array = NULL;
	for (int i = 0; i < 3; i++) {
		array = get_array(i + 3);
		printf("Sorting array %d:\n", i);
		selection_sort(array, sizes[i]);
		print_data_array(array, sizes[i]);
		free(array);
		array = NULL;
		printf("\n");
	}
	printf("End: Testing Selection Sort\n");
	printf("------------------------------\n\n");
	return;
}

void test_insertion_sort() {
	printf("------------------------------\n");
	printf("Start: Testing Insertion Sort:\n\n");

	int *array = NULL;
	for (int i = 0; i < 3; i++) {
		array = get_array(i + 3);
		printf("Sorting array %d:\n", i);
		insertion_sort(array, sizes[i]);
		print_data_array(array, sizes[i]);
		free(array);
		array = NULL;
		printf("\n");
	}
	printf("End: Testing Insertion Sort\n");
	printf("------------------------------\n\n");
	return;
}

void test_quick_sort() {
	printf("------------------------------\n");
	printf("Start: Testing Quick Sort:\n\n");

	int *array = NULL;
	for (int i = 0; i < 3; i++) {
		array = get_array(i + 3);
		printf("Sorting array %d:\n", i);
		quick_sort(array, sizes[i]);
		print_data_array(array, sizes[i]);
		free(array);
		array = NULL;
		printf("\n");
	}
	printf("End: Testing Quick Sort\n");
	printf("------------------------------\n\n");
	return;
}

void test_merge_sort() {
	printf("------------------------------\n");
	printf("Start: Testing Merge Sort:\n\n");

	int *array = NULL;
	for (int i = 0; i < 3; i++) {
		array = get_array(i + 3);
		printf("Sorting array %d:\n", i);
		merge_sort(array, sizes[i]);
		print_data_array(array, sizes[i]);
		free(array);
		array = NULL;
		printf("\n");
	}
	printf("End: Testing Merge Sort\n");
	printf("------------------------------\n\n");
	return;
}
int* get_array(int num) {
	int *array = NULL;

	switch (num) {
	case 0:
		array = (int*) malloc(sizeof(int));
		*array = 19;
		break;
	case 1:
		array = (int*) malloc(sizeof(int) * 5);
		array[0] = 19;
		array[1] = 21;
		array[2] = 37;
		array[3] = 54;
		array[4] = 69;
		break;
	case 2:
		array = (int*) malloc(sizeof(int) * 10);
		array[0] = 19;
		array[1] = 21;
		array[2] = 21;
		array[3] = 37;
		array[4] = 54;
		array[5] = 69;
		array[6] = 77;
		array[7] = 82;
		array[8] = 91;
		array[9] = 97;
		break;
	case 3:
		array = (int*) malloc(sizeof(int));
		*array = 19;
		break;
	case 4:
		array = (int*) malloc(sizeof(int) * 5);
		array[0] = 54;
		array[1] = 21;
		array[2] = 69;
		array[3] = 33;
		array[4] = 19;
		break;
	case 5:
		array = (int*) malloc(sizeof(int) * 10);
		array[0] = 54;
		array[1] = 21;
		array[2] = 15;
		array[3] = 37;
		array[4] = 97;
		array[5] = 69;
		array[6] = 77;
		array[7] = 68;
		array[8] = 51;
		array[9] = 41;
		break;
	}
	return array;
}
