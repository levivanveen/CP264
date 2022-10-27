#ifndef R9_H_
#define R9_H_

#include "data.h"

void bubble_sort(Data *array, const int size);
void insertion_sort(Data *array, const int size);
void selection_sort(Data *array, const int size);
void quick_sort(Data *array, const int size);
void merge_sort(Data *array, const int size);

int linear_search(Data *array, const int size, Data item);
int linear_search_r(Data *array, const int size, Data item);
int binary_search(Data *array, const int size, Data item);
int binary_search_r(Data *array, const int size, Data item);

#endif /* R9_H_ */
