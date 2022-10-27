/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

#ifndef CQUEUE_H_
#define CQUEUE_H_

# include "data.h"

# define True 1
# define False 0

typedef struct {
	Data *array; 	//array containing data items
	int front;		//index of first item in Queue
	int rear;		//index of last item in Queue
	int capacity;	//maximum queue length
	int size;		//number of elements in Queue
} cQueue;

cQueue* create_cqueue(int capacity);
int is_empty_cqueue(cQueue *q);
int len_cqueue(cQueue *q);
int is_full_cqueue(cQueue *q);
int insert_cqueue(cQueue *q, Data *d);
Data* peek_cqueue(cQueue *q);
void destroy_cqueue(cQueue **q);
int get_capacity_cqueue(cQueue *q);
Data* remove_cqueue(cQueue *q);
void print_cqueue(cQueue *q);

#endif /* CQUEUE_H_ */
