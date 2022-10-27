#ifndef FINAL_H_
#define FINAL_H_

#include "data_structures.h"

Stack* sort_stacks(Stack* stacks[COUNT],const int size);
int delete_mid_list(List* list);

typedef struct {
	void *item; 	//pointer to data item
	char type;		//'i' = integer, 'p' = process
} MData;

MData* create_mdata(void *item, char type);
void destroy_mdata(MData **d);
void print_mdata(MData *d);
MData* copy_mdata(MData *d);

#endif /* FINAL_H_ */
