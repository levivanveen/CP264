/*
 * ---------------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student Email: vanv2490@mylaurier.ca
 * ---------------------------------
 */

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include "A8.h"

/*---------------------Task 1 -----------------------------*/
void schedule(char *type, Data *processes, const int size) {
	int func = 0, period = 0;
	char *ptr;

	if (strcmp(type, "FIFO") == 0)
		func = 1;
	else if (strcmp(type, "SJF") == 0)
		func = 2;
	else if (strncmp(type, "RR", 2) == 0)
		func = 3;

	else if (strncmp(type, "DRR", 3) == 0)
		func = 4;

	if (func == 3 || func == 4) {
		for (int i = 0; i < strlen(type); i++) {
			if (isdigit(type[i]) != 0) {
				period = (period * 10) + (int) strtol(&type[i], &ptr, 10);
			}
		}
	}

	if (func == 0) {
		printf("Error(schedule): Unsupported scheduler type");
		return;
	}

	pQueue *pq = create_pqueue(size + 1, 'L');
	for (int i = 0; i < size; i++) {
		insert_pqueue2(pq, &processes[i]);
	}

	switch (func) {
	case 1:
		schedule_FIFO(pq);
		break;
	case 2:
		schedule_SJF(pq);
		break;
	case 3:
		schedule_RR(pq, period);
		break;
	case 4:
		schedule_DRR(pq, period);
		break;
	default:
		printf("Error(schedule): Unsupported scheduler type");
		break;
	}
	return;
}

/*---------------------Task 2 -----------------------------*/
void schedule_FIFO(pQueue *q) {
	int timer = 0;
	printf("[Timer:%d]: Starting FIFO Scheduler\n", timer++);

	Data *d = NULL;

	while (!is_empty_pqueue(q)) {
		d = peek_pqueue2(q);
		if (timer >= d->arrival) {
			d = remove_pqueue2(q);
			printf("Fetching Process: ");
			print_data(d);
			printf("\n");
			for (int i = 0; i < d->time; i++) {
				printf("[Timer:%d]: ", timer++);
				print_data(d);
				printf("\n");
			}
		} else
			printf("[Timer:%d]: Idle\n", timer++);
	}

	printf("[Timer:%d]: Closing FIFO Scheduler\n", timer++);
	return;
}

/*---------------------Task 3 -----------------------------*/
void schedule_SJF(pQueue *q) {
	int timer = 0;
	printf("[Timer:%d]: Starting SJF Scheduler\n", timer++);

	Data *d = NULL, cache[len_pqueue(q)];

	while (!is_empty_pqueue(q)) { //Pqueue still has processes
		if (timer >= peek_pqueue2(q)->arrival) { //Timer has reached the arrival time of the next process

			int length = 0;
			while (!is_empty_pqueue(q) && timer >= peek_pqueue2(q)->arrival) { //Keep adding processes to cache while arrival < timer
				cache[length++] = *remove_pqueue2(q);
			}
			int smallest = 0;
			for (int i = 0; i < length; i++) {
				if (cache[i].time < cache[smallest].time) //Get index of smallest time in cache
					smallest = i;
			}
			d = &cache[smallest]; //D is smallest time in cache
			Data *ptr = NULL;

			for (int i = 0; i < length; i++) {
				if (i != smallest) {
					ptr = &cache[i];
					insert_pqueue2(q, ptr);
					destroy_data(&ptr);
				}
			}

			printf("Fetching Process: ");
			print_data(d);
			printf("\n");
			for (int i = 0; i < d->time; i++) {
				printf("[Timer:%d]: ", timer++);
				print_data(d);
				printf("\n");
			}
		} else
			printf("[Timer:%d]: Idle\n", timer++);
	}

	printf("[Timer:%d]: Closing SJF Scheduler\n", timer++);
	return;
}

/*---------------------Task 4 -----------------------------*/
void schedule_RR(pQueue *q, int period) {
	int timer = 0, length, insert = 0;
	printf("[Timer:%d]: Starting RR%d Scheduler\n", timer++, period);

	Data *d = NULL;

	while (!is_empty_pqueue(q)) {
		insert = 0;
		d = peek_pqueue2(q);
		if (timer >= d->arrival) {
			d = remove_pqueue2(q);
			printf("Fetching Process: ");
			print_data(d);
			printf("\n");

			if (period > d->time)
				length = d->time;
			else
				length = period;
			for (int i = 0; i < length; i++) {
				printf("[Timer:%d]: ", timer++);
				print_data(d);
				printf("\n");
			}
			if (d->time > period)
				insert = 1;
			d->time = d->time - period;
			d->arrival = timer;

			if (insert == 1) {
				insert_pqueue2(q, d);
			}
		} else
			printf("[Timer:%d]: Idle\n", timer++);
	}

	printf("[Timer:%d]: Closing RR%d Scheduler\n", timer++, period);
	return;
}

/*---------------------Task 5 -----------------------------*/
void schedule_DRR(pQueue *q, int period) {
	int timer = 0, length, insert = 0, array_index = 0, found, array_len =
			len_pqueue(q);
	printf("[Timer:%d]: Starting DRR%d Scheduler\n", timer++, period);

	Data *d = NULL;
	Data *array = NULL;	//Array to hold values that have been processed
	array = (Data*) malloc(sizeof(Data) * array_len);
	while (!is_empty_pqueue(q)) {
		insert = 0;
		found = 1;

		d = peek_pqueue2(q);
		if (timer >= d->arrival) {
			d = remove_pqueue2(q);
			for (int i = 0; i < array_index; i++) { //Check how many times process has been processed
				if (compare_data(d, &array[i]) == 0) {
					found++;

				}
			}

			printf("Fetching Process: ");
			print_data(d);
			printf("\n");

			if (period * found > d->time)
				length = d->time;
			else
				length = period * found;

			for (int i = 0; i < length; i++) {
				printf("[Timer:%d]: ", timer++);
				print_data(d);
				printf("\n");
			}
			if (d->time > period * found)
				insert = 1;
			d->time = d->time - (period * found);
			d->arrival = timer;

			if ((array_index + 1) >= array_len) { //If array is too small double it's size
				array = (Data*) realloc(array, sizeof(Data) * array_len * 2);
				array_len = array_len * 2;
			}

			if (insert == 1) { //Insert array and pqueue if more time is left
				insert_pqueue2(q, d);
				array[array_index++] = *d;
			}
		} else
			printf("[Timer:%d]: Idle\n", timer++);
	}
	free(array);
	array = NULL;
	printf("[Timer:%d]: Closing DRR%d Scheduler\n", timer++, period);
	return;
}

