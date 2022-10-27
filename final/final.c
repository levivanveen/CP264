/**
 * ---------------------------------
 * Student Name:	Levi Van Veen
 * Student ID:		200852490
 * Student Email:	vanv2490@mylaurier.ca
 * ---------------------------------
 */

/**
 * ---------------------------------
 *I certify that I completed this final
 *I exam according to academic honesty guidelines.
 *I I attest that I did not use any external help,
 *I neither in person nor virtually. I understand
 *I that plagiarizing will lead to my failure in the course,
 *I in addition to other penalties according to
 *I the University policies
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 *
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "final.h"
# include "data_structures.h"

//--------------- Task 1 -----------------------
Stack* sort_stacks(Stack *stacks[5], const int size) {
	if (size == 0) {
		return NULL;
	}
	if (size == 1) {
		Stack *s = create_stack(len_stack(stacks[0]));
		while (!is_empty_stack(stacks[0])) {
			push_stack(s, pop_stack(stacks[0]));
		}
		return s;
	}

	int capacity = 0, entered = 0, i = 0, biggest;
	for (i = 0; i < size; i++)		//find capacity that new stack needs to be
		capacity = capacity + stacks[i]->capacity;
	Stack *s = create_stack(capacity);

	while (entered < capacity) {
		biggest = -1;
		for (i = 0; i < size; i++) {	//finds first non-empty stack
			if (!is_empty_stack(stacks[i])) {
				biggest = i;
				break;
			}
		}
		for (i = 1; i < size; i++) {	//finds biggest top of all the stacks
			if (is_empty_stack(stacks[i])) {//doesnt compare data of stacks that are empty
				continue;
			}
			if (compare_data(peek_stack(stacks[biggest]), peek_stack(stacks[i]))
					== 2)
				biggest = i;
		}
		push_stack(s, pop_stack(stacks[biggest]));
		entered++;
	}
	return s;
}

//--------------- Task 2 -----------------
int delete_mid_list(List *list) {
	if (is_empty_list(list)) {
		printf("Error(delete_mid_list): empty list\n");
		return -1;
	}
	//Find length of list
	Node *curr = list->head;
	int length = 0, index;
	while (curr != NULL) {
		curr = curr->next;
		length++;
	}
	if (length % 2 == 0) 		//find index of node to delete
		index = (length / 2) - 1;
	else
		index = length / 2;

	if (length == 1) {
		destroy_node(&list->head);
		destroy_list(&list);
	} else {
		curr = list->head;
		if (index == 0) {
			list->head = list->head->next;
			destroy_node(&curr);
		} else {
			for (int i = 0; i < index - 1; i++)
				curr = curr->next;
			Node *temp = curr->next;
			curr->next = curr->next->next;
			destroy_node(&temp);
		}
		list->size--;
	}
	return index;
}
//-------------- Task 3 ------------------
MData* create_mdata(void *item, char type) {
	if (item == NULL) {
		printf("Error(create_mdata): invalid pointer\n");
		return NULL;
	}
	if (type != 'p' && type != 'i') {
		printf("Error(create_mdata): invalid data type\n");
		return NULL;
	}
	if (type == 'i') {
		MData *m = (MData*) malloc(sizeof(MData) * sizeof(int));
		m->type = type;
		m->item = item;
		return m;
	} else {
		MData *m = (MData*) malloc(sizeof(MData) * sizeof(Process));
		m->type = type;
		m->item = (Process*) malloc(sizeof(Process));
		m->item = copy_process(item);
		return m;
	}
	return NULL;
}

void destroy_mdata(MData **d) {
	assert(d && *d);
	if ((*d)->type == 'p') {
		free((*d)->item);
		(*d)->item = NULL;
	} else {
		(*d)->item = 0;
	}
	(*d)->type = '\0';
	free(*d);
	*d = NULL;
	return;
}

void print_mdata(MData *d) {
	if (d == NULL) {
		printf("<NULL MData>\n");
		return;
	}
	if (d->type != 'i' && d->type != 'p') {
		printf("Error(print_mdata): unsupported data\n");
		return;
	}
	if (d->type == 'i') {
		printf("type = integer, ");
		printf("value = %d\n", *(int*) d->item);
	} else {
		printf("type = process, ");
		printf("value = ");
		print_process(d->item);
		printf("\n");
	}

	return;
}

MData* copy_mdata(MData *d) {
	assert(d);
	if (d->type != 'i' && d->type != 'p') {
		printf("Error(copy_mdata): unsupported data\n");
		return NULL;
	}
	MData *m = (MData*) malloc(sizeof(MData));
	if (d->type == 'i') {
		*m = *d;
	} else {
		m->type = 'p';
		m->item = (Process*) malloc(sizeof(Process));
		m->item = copy_process(d->item);
	}
	return m;
}
//----------------------------------
