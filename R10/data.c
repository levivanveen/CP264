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
	print_process(d);
	return;
}

void destroy_data(Data **d) {
	destroy_process(d);
	return;
}

Data* copy_data(Data *d) {
	return copy_process(d);
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
	if (d1->arrival > d2->arrival) {
		//printf("D1 time: %d\n", d1->time);
		return 1;
	} else if (d1->arrival == d2->arrival) {
		//printf("D1 and D2 time: %d\n", d1->time);
		if (d1->time > d2->time) {
			return 1;
		} else if (d1->time == d2->time) {
			if (d1->PID > d2->PID) {
				return 1;
			} else if (d1->PID == d2->PID) {
				return 0;
			} else
				return 2;
		} else
			return 2;
	}
	return 2;
}

void print_data_array(Data *array, const int size) {
	assert(array != NULL);
	int i;

	int counter = 0;
	for (i = 0; i < size; i++) {
		print_data(&array[i]);
		if (counter != size - 1)
			printf(",");
		counter++;
	}
	return;
}
