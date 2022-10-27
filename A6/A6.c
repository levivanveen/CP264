/*
 * ---------------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student Email: vanv2490@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "A6.h"

int find_capacity(Stack *s) {
	int cap = 0, counter = 0;

	Stack *s2 = copy_stack(s);
	Process *p = create_process(1, 1, 1);

	while (!is_full_stack(s2)) {
		push_stack(s2, p);
		counter++;
	}
	destroy_stack(&s2);
	cap = counter + len_stack(s);
	return cap;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	process_array: A pointer to an array of Processes (Process*)
 *	 	 	 		size: Size of processes array (const int)
 * Returns: none
 * Description:	Finds the largest process and remove it from array
 *		Details of the largest process are printed to console
 *		Size of the array is reallocated to be less by 1
 *		The largest process is the one with the longest service time
 *		If more than one process have the same service time
 *			pick the one with earlier arrival
 *		If both service and arrival times are equal, pick smaller PID
 *		If the array contains only a single process:
 *			Do not free the array or realloc.
 * 			Set contents the process contents to 0.
 *		Print an error message if array is NULL or size is invalid
 * ------------------------------------------------------------
 */
void remove_largest(Process *process_array, const int size) {
	if (!process_array) {
		printf("Error(remove_largest): given pointer is NULL\n");
		return;
	}
	if (size < 1) {
		printf("Error(remove_largest): invalid array size\n");
		return;
	}
	if (size == 1) {
		printf("Largest Process is : %lu\n", process_array[0].PID);
		process_array[0].PID = 0;
		process_array[0].time = 0;
		process_array[0].arrival = 0;
		return;
	}
	int i = 0, index;

	index = 0;

	for (i = 1; i < size; i++) {

		if (process_array[i].time > process_array[index].time) {
			index = i;
		} else if (process_array[i].time == process_array[index].time) {

			if (process_array[i].arrival < process_array[index].arrival) {
				index = i;
			} else if (process_array[i].arrival
					== process_array[index].arrival) {
				if (process_array[i].PID < process_array[index].PID) {
					index = i;
				}
			}
		}
	}
	printf("Largest Process is : %lu\n", process_array[index].PID);

	Process *ptr;
	ptr = &process_array[index];
	destroy_process(&ptr);

	for (i = index; i < size; i++)
		process_array[index] = process_array[size - 1];
	process_array = (Process*) realloc(process_array,
			size - 1 * sizeof(Process));
	return;
}

void reverse_stack(Stack *s) {
	assert(s != NULL);

	int i = 0;
	int length = (int) len_stack(s);

	Data *array = (Data*) malloc(sizeof(Data) * length);

	while (i < length) {
		array[i] = *pop_stack(s);
		i++;
	}
	i = 0;
	while (i < length) {
		push_stack(s, &array[i]);
		i++;
	}
	Data *ptr;

	for (i = 0; i < length; i++) {
		ptr = &array[i];
		destroy_data(&ptr);
	}
	free(array);
	return;
}

Stack* slice_stack(Stack *s1, int index) {
	assert(s1 != NULL);

	int i = 0, length = len_stack(s1), num = length - index;
	if (length == 0)
		length = 10;
	Stack *s2 = create_stack(length);

	if (len_stack(s1) < 1) {
		printf("Error(slice_stack): cannot slice an empty stack\n");
		return s2;
	}
	if (index < 0) {
		printf("Error(slice_stack): invalid index\n");
		return s2;
	}

	if (length == index) {
		return s2;
	}

	if (index > length) {
		num = length;
	}

	while (i < num) {
		push_stack(s2, pop_stack(s1));
		i++;
	}
	reverse_stack(s2);
	return s2;
}

int resize_stack(Stack *s, int new_capacity) {
	if (new_capacity <= 0) {
		printf("Error(resize_stack): invalid capacity\n");
		return False;
	}
	if (new_capacity == 0) {
		return False;
	}
	if (new_capacity > s->capacity || len_stack(s) < new_capacity) {
		s->capacity = new_capacity;
		return True;
	}
	s->capacity = new_capacity;
	Data *d = NULL;
	int amount = 0;
	amount = len_stack(s) - new_capacity;
	for (int i = 0; i < amount; i++) {
		d = pop_stack(s);
	}

	return True;
}
Stack* concat_stack(Stack *s1, Stack *s2) {
	int length = find_capacity(s1) + find_capacity(s2), empty = 0;
	if (length == 0) {
		empty = 1;
		length = 10;
	}
	Stack *s3 = create_stack(length);
	if (empty) {
		return s3;
	}
	Stack *s1_copy = copy_stack(s1);
	Stack *s2_copy = copy_stack(s2);
	reverse_stack(s1_copy);
	reverse_stack(s2_copy);

	while (!is_empty_stack(s1_copy)) {
		push_stack(s3, pop_stack(s1_copy));
	}
	destroy_stack(&s1_copy);

	while (!is_empty_stack(s2_copy)) {
		push_stack(s3, pop_stack(s2_copy));
	}
	destroy_stack(&s2_copy);

	return s3;
}
