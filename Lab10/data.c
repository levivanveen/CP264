/*
 -------------------------------------
 File:    data.c
 Project: R7
 file description
 -------------------------------------
 Author:  Levi Van Veen
 ID:      200852490
 Email:   vanv2490@mylaurier.ca
 Version  2021-11-04
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "data.h"

void print_data(Data *d) {
	assert(d);
	printf("%d", (int) *d);
	return;
}

void print_data_array(Data *array, const int size) {
	assert(array);
	assert(size >= 1);

	int i;
	printf("[");
	for (i = 0; i < size; i++) {
		printf("%d", array[i]);
		if (i != size - 1) {
			printf(",");
		}
	}
	printf("]");
	return;
}

void destroy_data(Data **d) {
	assert(d && *d);
	free(*d);
	*d = NULL;
	return;
}

Data* copy_data(Data *d1) {
	assert(d1);
	int *d2 = (int*) malloc(sizeof(int));
	*d2 = *d1;

	return d2;
}

void swap_data(Data *d1, Data *d2) {
	assert(d1 && d2);
	Data temp = *d1;
	*d1 = *d2;
	*d2 = temp;
	return;
}

// 0 means equal, 1 means d1 > d2, 2 means d1 < d2
int compare_data(Data *d1, Data *d2) {
	assert(d1 && d2);

	if (*d1 > *d2)
		return 1;
	else if (*d1 < *d2)
		return 2;
	return 0;
}

