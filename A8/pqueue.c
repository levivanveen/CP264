/*
 * ---------------------------------
 * Student Name: 	Levi Van Veen
 * Student ID:		200852490
 * Student Email:	vanv2490@mylaurier.ca
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
#include "pqueue.h"

void adjust_pqueue(pQueue *q);
int find_top_priority(pQueue *q);

/**
 * ------------------------------------------------------------
 * Parameters: 	capacity: maximum size of priority queue
 * 				priority: a character describing priority mode
 * Returns: 	q: A pointer to a priority queue
 * Description:	Creates a priority queue
 * 				Dynamically creates an array of size: capacity
 * 				Sets front and rear to -1
 * 				priority is set to either 'H' or 'L'
 * 				if invalid capacity set to 10
 * 				if invalid priority set to 'H'
 * Assert:		None
 * Errors:		if invalid capacity:
 * 					Error(create_pqueue): invalid pqueue capacity, set to 10\n
 * 				if invalid priority:
 * 					"Error(create_pqueue): invalid priority, set to 'H'\n"
 * ------------------------------------------------------------
 */
pQueue* create_pqueue(int capacity, char priority) {
	pQueue *q = (pQueue*) malloc(sizeof(pQueue));
	if (capacity < 1) {
		printf("Error(create_pqueue): invalid pqueue capcity, set to 10\n");
		capacity = 10;
	}
	if (priority != 'H' && priority != 'L') {
		printf("Error(create_pqueue): invalid pqueue priority, set to 'H'\n");
		priority = 'H';
	}
	q->priority = priority;
	q->capacity = capacity;
	q->array = (Data*) malloc(sizeof(Data) * capacity);
	q->front = -1;
	q->rear = -1;
	return q;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority queue (pQueue*)
 * Returns: 	number of items in a pqueue (int)
 * Description:	Returns number of items in a pqueue
 * Assert:		q is not NULL
 * Errors:		None
 * ------------------------------------------------------------
 */
int len_pqueue(pQueue *q) {
	assert(q!= NULL);
	if (q->front == -1)
		return 0;
	return q->rear - q->front + 1;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority queue (pQueue*)
 * Returns: 	pqueue capacity (int)
 * Description:	Returns maximum number of items that can be stored in a pqueue
 * Assert:		q is not NULL
 * Errors:		None
 * ------------------------------------------------------------
 */
int get_capacity_pqueue(pQueue *q) {
	assert(q != NULL);
	return q->capacity;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority queue (pQueue*)
 * Returns: 	True/False (int)
 * Description:	Returns True if pqueue is empty, False otherwise
 * Assert:		q is not NULL
 * Errors:		None
 * ------------------------------------------------------------
 */
int is_empty_pqueue(pQueue *q) {
	assert(q != NULL);
	return (len_pqueue(q) == 0);
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority queue (pQueue*)
 * Returns: 	True/False (int)
 * Description:	Returns True if pqueue is full, False otherwise
 * Assert:		q is not NULL
 * Errors:		None
 * ------------------------------------------------------------
 */
int is_full_pqueue(pQueue *q) {
	assert(q != NULL);
	return (len_pqueue(q) == q->capacity);
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority queue (pQueue*)
 * Returns: 	None
 * Description:	Prints contents of a priority queue
 * 				Starts with:
 * 					Capacity = <int>, Size = <int>, front = <int>, rear = <int>\n
 * 				Then prints queue elements separated by a tab
 * 				Each five elements appear on a separate line
 * 				if empty prints: <empty_pqueue>\n
 * Assert:		q is not NULL
 * Errors:		None
 * ------------------------------------------------------------
 */
void print_pqueue(pQueue *q) {
	assert(q != NULL);
	int i;
	printf("Capacity = %d, Size = %d, front = %d, rear = %d\n", q->capacity,
			len_pqueue(q), q->front, q->rear);
	if (is_empty_pqueue(q)) {
		printf("<empty_pqueue>\n");
	} else {
		int counter = 0;
		for (i = q->front; i <= q->rear; i++) {
			print_data(&q->array[i]);
			if ((counter + 1) % 5 == 0 && counter != len_pqueue(q) - 1) {
				printf("\n");
			} else {
				printf("\t");
			}
			counter++;
		}
		printf("\n");
	}
	return;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority Queue (pQueue*)
 * 				d: A data item to be added (Data*)
 * Returns: 	True/False
 * Description:	Insert an item to the queue (unsorted insertion)
 * 				returns True if insert is successful and False otherwise
 * Assert:		q and d are not NULL
 * Errors:		if full --> Error(insert_pqueue): pqueue is full\n
 * Analysis: 	O(n) if regular queue
 * 				O(1) if circular queue
 * ------------------------------------------------------------
 */
int insert_pqueue(pQueue *q, Data *d) {
	assert(q != NULL && d != NULL);

	if (len_pqueue(q) == q->capacity) {
		printf("Error(insert_pqueue): pqueue is full\n");
		return False;
	}
	if (is_empty_pqueue(q)) {
		q->front = 0;
	} else if (q->rear == (q->capacity - 1)) {
		adjust_pqueue(q);
	}
	q->rear++;
	q->array[q->rear] = *copy_data(d);

	return True;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority Queue (pQueue*)
 * 				d: A data item to be added (Data*)
 * Returns: 	True/False
 * Description:	Insert an item to the queue (sorted insertion)
 * 				returns True if insert is successful and False otherwise
 * Assert:		q and d are not NULL
 * Errors:		if full --> Error(insert_pqueue): pqueue is full\n
 * Analysis: 	O(n)
 * ------------------------------------------------------------
 */
int insert_pqueue2(pQueue *q, Data *d) {
	assert(q != NULL && d != NULL);
	int inserted = False;

	if (is_full_pqueue(q)) {
		printf("Error(insert_pqueue2): pqueue is full\n");
		return False;
	}
	if (is_empty_pqueue(q)) {
		q->front = 0;
		q->array[0] = *copy_data(d);
		q->rear++;
		inserted = True;
		return inserted;
	} else if (q->rear == (q->capacity - 1)) {
		adjust_pqueue(q);
	}

	int i = q->front, index;

	//Finding index to place data
	while (i <= q->rear && !inserted) {
		if (q->priority == 'H') {
			if (compare_data(d, &q->array[i]) == 1) {
				inserted = True;
				break;
			}
		} else if (q->priority == 'L') {
			if (compare_data(d, &q->array[i]) == 2) {
				inserted = True;
				break;
			}
		}
		i++;
	}
	//Making room to insert

	if (!inserted) {
		q->array[q->rear + 1] = *copy_data(d);
	} else {
		index = i;
		i = q->rear;

		while (i >= index) {
			q->array[i + 1] = q->array[i];
			i--;
		}
		q->array[index] = *copy_data(d);
	}

	q->rear++;
	inserted = True;
	return inserted;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority Queue (pQueue*)
 * Returns: 	d: a copy of data item at the front of pqueue
 * Description:	Returns a copy of front of pqueue
 * 				Assumes unsorted insert
 * Assert:		q is not NULL
 * Errors:		if empty --> Error(peek_pqueue): pqueue is empty\n
 * Analysis: 	O(n)
 * ------------------------------------------------------------
 */
Data* peek_pqueue(pQueue *q) {
	assert(q != NULL);
	Data *d = NULL;
	if (is_empty_pqueue(q)) {
		printf("Error(peek_pqueue): pqueue is empty\n");
		return d;
	}
	int index = find_top_priority(q);
	d = &q->array[index];
	return d;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority Queue (pQueue*)
 * Returns: 	d: a copy of data item at the front of pqueue
 * Description:	Returns a copy of front of pqueue
 * 				Assumes sorted insert
 * Assert:		q is not NULL
 * Errors:		if empty --> Error(peek_pqueue): pqueue is empty\n
 * Analysis: 	O(1)
 * ------------------------------------------------------------
 */
Data* peek_pqueue2(pQueue *q) {
	assert(q != NULL);
	if (is_empty_pqueue(q)) {
		printf("Error(peek_pqueue2): pqueue is empty\n");
		return NULL;
	}
	return copy_data(&q->array[q->front]);
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority Queue (pQueue*)
 * Returns: 	d: a copy of data item at the front of pqueue
 * Description:	Returns a copy of front of pqueue
 * 				Assumes unsorted insert
 * Assert:		q is not NULL
 * Errors:		if empty --> Error(remove_pqueue): pqueue is empty\n
 * Analysis: 	O(n)
 * ------------------------------------------------------------
 */
Data* remove_pqueue(pQueue *q) {
	assert(q != NULL);
	Data *d = NULL;
	if (is_empty_pqueue(q)) {
		printf("Error(peek_pqueue): pqueue is empty\n");
		return d;
	}
	int index = find_top_priority(q), i;

	d = copy_data(&q->array[index]);
	Data *temp = &q->array[index];
	destroy_data(&temp);
	if (len_pqueue(q) == 1) {
		q->front = -1;
		q->rear = -1;
		return d;
	}

	i = index;

	if (i == q->front) {
		while (i > q->front) {
			q->array[i] = q->array[i - 1];
			i--;
		}
		q->front++;

	} else {
		while (i < len_pqueue(q)) {
			q->array[i] = q->array[i + 1];
			i++;
		}
		q->rear--;
	}
	return d;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A pointer to a priority Queue (pQueue*)
 * Returns: 	d: a copy of data item at the front of pqueue
 * Description:	Returns a copy of front of pqueue
 * 				Assumes sorted insert
 * Assert:		q is not NULL
 * Errors:		if empty --> Error(remove_pqueue2): pqueue is empty\n
 * Analysis: 	O(1)
 * ------------------------------------------------------------
 */
Data* remove_pqueue2(pQueue *q) {
	assert(q!= NULL);
	Data *d = NULL;
	if (is_empty_pqueue(q)) {
		printf("Error(remove_pqueue2): pqueue is empty\n");
		return d;
	}
	d = copy_data(&q->array[q->front]);
	Data *temp = &q->array[q->front];
	destroy_data(&temp);

	q->front++;

	if (len_pqueue(q) == 0) {
		q->front = -1;
		q->rear = -1;
	}
	return d;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	q: A double pointer to a priority Queue (pQueue**)
 * Returns: 	None
 * Description:	Destroy a queue by:
 * 					removing and destroying all data items
 * 					freeing queue array
 * 					set all other data members to 0
 * 					free queue
 * 				Assumes sorted insert
 * Assert:		q is not NULL
 * Errors:		None
 * ------------------------------------------------------------
 */

void destroy_pqueue(pQueue **q) {
	assert(q!= NULL);
	while (!is_empty_pqueue(*q)) {
		Data *d = remove_pqueue(*q);
		destroy_data(&d);
	}
	free((*q)->array);
	(*q)->array = NULL;
	(*q)->capacity = 0;
	(*q)->front = 0;
	(*q)->rear = 0;
	free(*q);
	*q = NULL;
	return;
}

/**
 * ------------------------------------------------------------
 * Parameters:	q: A pointer to a priority Queue (pQueue*)
 * Returns:		index: index of top priority item
 * Description:	A private helper function mainly for unsorted
 * 						insertion pqueue
 * 					finds index of item with highest priority in pqueue
 * 						if 'H' --> finds largest value
 * 						if 'L' --> finds smallest value
 * Assert:		q is not NULL
 * 					q is not empty
 * Errors:		None
 * Analysis: 	O(n)
 * ------------------------------------------------------------
 */
int find_top_priority(pQueue *q) {
	assert(q != NULL && !is_empty_pqueue(q));

	int largest = q->front, i = (q->front + 1);
	if (q->priority == 'H') {
		while (i <= q->rear) {
			if (compare_data(&(q->array[i]), &(q->array[largest])) == 1) {
				largest = i;
			}
			i++;
		}
	} else if (q->priority == 'L') {
		while (i <= q->rear) {
			if (compare_data(&(q->array[i]), &(q->array[largest])) == 2) {
				largest = i;
			}
			i++;
		}
	}
	return largest;
}

void adjust_pqueue(pQueue *q) {
	assert(q != NULL);
	int length = len_pqueue(q), i;
	for (i = 0; i < length; i++) {
		q->array[i] = q->array[i + q->front];
	}
	q->front = 0;
	q->rear = length - 1;
	return;
}
