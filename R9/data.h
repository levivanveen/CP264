/*
 -------------------------------------
 File:    data.h
 Project: R7
 file description
 -------------------------------------
 Author:  Levi Van Veen
 ID:      200852490
 Email:   vanv2490@mylaurier.ca
 Version  2021-11-04
 -------------------------------------
 */

#ifndef DATA_H_
#define DATA_H_

typedef int Data;

void print_data(Data *d);
void print_data_array(Data *d, const int size);
void destroy_data(Data **d);
Data* copy_data(Data *d);
void swap_data(Data *d1, Data *d2);
int compare_data(Data *d1, Data *d2);

#endif /* DATA_H_ */
