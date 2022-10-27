/*
 -------------------------------------
 File:    cqueue_array.h
 Project: R8
 file description
 -------------------------------------
 Author:  Levi Van Veen
 ID:      200852490
 Email:   vanv2490@mylaurier.ca
 Version  2021-11-08
 -------------------------------------
 */

#ifndef CQUEUE_H_
#define CQUEUE_H_

# include "data.h"

#define True 1
#define False 0

typedef struct {
	Data *array; //array containing data
	int front;	//index of first item
	int rear;	//index of last item
	int capacity;	//Maximum queue length
	int size;		//number of elements
} cQueue;

cQueue* create_cqueue(int capacity);
int is_empty_cqueue(cQueue *q);
int len_cqueue(cQueue *q);
int is_full_cqueue(cQueue *q);
int insert_cqueue(cQueue *q, Data *d);
Data* peek_cqueue(cQueue *q);
Data* remove_cqueue(cQueue *q);
void destroy_cqueue(cQueue **q);
void print_cqueue(cQueue *q);
int get_capacity_cqueue(cQueue *q);

#endif /* CQUEUE_H_ */
