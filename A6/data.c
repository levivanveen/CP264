/*
 -------------------------------------
 File:    data.c
 Project: R7
 file description
 -------------------------------------
 Author:  Levi Van Veen
 ID:      200852490
 Email:   vanv2490@mylaurier.ca
 Version  2021-11-04
 -------------------------------------
 */
#include "data.h"

void print_data(Data *d) {
	print_process(d);
	return;
}

void destroy_data(Data **d) {
	destroy_process(d);
	return;
}

Data* copy_data(Data *d) {
	return copy_process(d);
}
