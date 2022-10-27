/*
 -------------------------------------
 File:    queue_array.h
 Project: R8
 file description
 -------------------------------------
 Author:  Levi Van Veen
 ID:      200852490
 Email:   vanv2490@mylaurier.ca
 Version  2021-11-08
 -------------------------------------
 */

#ifndef QUEUE_ARRAY_H_
#define QUEUE_ARRAY_H_

#include "data.h"

#define True 1
#define False 0

typedef struct {
	Data *array; //array containing data
	int front;	//index of first item
	int rear;	//index of last item
	int capacity;	//Maximum queue length
} Queue;

Queue* create_queue(int capacity);
int is_empty_queue(Queue *q);
int len_queue(Queue *q);
int is_full_queue(Queue *q);
int insert_queue(Queue *q, Data *d);
Data* peek_queue(Queue *q);
Data* remove_queue(Queue *q);
void destroy_queue(Queue **q);
void print_queue(Queue *q);
int get_capacity_queue(Queue *q);

#endif /* QUEUE_ARRAY_H_ */
