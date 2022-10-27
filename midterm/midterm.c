/* CP264 Fall 2021 Midterm */

/*
 * ---------------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student Email: vanv2490@mylaurier.ca
 * ---------------------------------
 */

/**
 * ---------------------------------
 * I certify that i completed this midterm according to academic honesty guidelines.
 * I attest that i did not use any external help, neither in person nor virtually. I
 * understand that plagiarizing will lead to my failure in the course, in addition to
 *other penalties according to the University policies.
 * ---------------------------------
 */

/**
 * ---------------------------------
 *	I was getting warnings from the midterm_test.c file but my midterm.c file still
 *	gives the correct output.
 * ---------------------------------
 */

//---- Do not change imports -----------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "midterm.h"
//---------------------------------------------

//----------------- Task 1 ---------------------
void replace_most_freq(const char *filename, char c, FILE *destination) {
	//Open file and check if opened
	FILE *in_file = NULL;
	in_file = fopen(filename, "r+");

	if (!in_file) {
		fprintf(destination,
				"Error(replace_most_freq): Could not open file %s\n", filename);
		return;
	}

	int counters[27];
	char letter = fgetc(in_file), most, prev;
	int index;

	for (int j = 0; j < 26; j++) {
		counters[j] = 0;
	}

	//Count each letter
	while (letter != EOF) {
		if (isalpha(letter)) {
			index = tolower(letter) - 'a';
			counters[index]++;
		}
		letter = fgetc(in_file);
	}

	//Find letter with highest count
	int largest = counters[0], largest_index = 0;
	for (int i = 0; i < 26; i++) {
		if (counters[i] > largest) {
			largest = counters[i];
			largest_index = i;
		}
	}
	most = largest_index + 97;

	fseek(in_file, 1, SEEK_SET);
	letter = fgetc(in_file);
	while (letter != EOF) {
		if (letter == most && prev == most) {
			fseek(in_file, -2, SEEK_CUR);
			fputc(c, in_file);
			fputc(c, in_file);
			fseek(in_file, 0, SEEK_CUR);
		}
		prev = letter;
		letter = fgetc(in_file);
	}
//Printing most frequent char
	fprintf(in_file, "\n");
	fprintf(in_file, "Most frequent char = %c\n", largest_index + 97);
	fclose(in_file);
	return;
}

//----------------- Task 2 ---------------------
float* remove_nums(double **array, const int size, int value, FILE *fptr) {

	if (!array || !*array) {
		fprintf(fptr, "Error(remove_nums): invalid array\n");
		return NULL;
	}
	if (size <= 0) {
		fprintf(fptr, "Error(remove_nums): invalid size\n");
		return NULL;
	}
//Counting the number of values in array below value
	int count = 0, j = 0;
	for (int i = 0; i < size; i++) {
		if (*(*array + i) < value) {
			count++;
		}
	}
//creating sub array
	float *sub_array = (float*) malloc(sizeof(float) * count + 1);

//Moving values from array to sub array
	int i = 0, len = size;
	while (i < len) {
		if (*(*array + i) < value) {
			sub_array[j] = (float) *(*array + i);
			j++;
			i++;
		} else
			i++;
	}
	float temp;
	int counter = 0;
	i = 0, j = 0;
	while (i < size) {			//Loop through array
		if (*(*array + i) < value) {	//check if loweer than value
			j = 0;
			while (j < size - i) {
				if (*(*array + j + i) > value) {
					temp = *(*array + i);
					*(*array + i) = *(*array + i + j);
					*(*array + i + j) = temp;
					counter++;
					break;
				} else
					j++;
			}
		}
		i++;
	}
	*array = (double*) realloc(*array, sizeof(double) * (size - count + 1));
	return sub_array;
}

//----------------- Task 3 ---------------------
double* square_series(double a, double break_value, double **break_ptr,
		FILE *fptr) {

	if (!break_ptr) {
		fprintf(fptr, "Error(square_series): invalid pointer\n");
		return NULL;
	}
	if (a <= 0) {
		fprintf(fptr, "Error(square_series): invalid value of a\n");
		return NULL;
	}

	int i = 2, size = 10, even = 1, j = 0;
	double sum = 1 / sqrt(a);

//Finding the length that the array should be
	while (i < 11 && sum > break_value) {
		if (even % 2 == 0) {
			sum = sum + (1 / sqrt(i * a));
			even = 1;
		} else {
			sum = sum - (1 / sqrt(i * a));
			even = 0;
		}
		i++;
	}
	size = i - 1;
	double *new_array = (double*) malloc(sizeof(double) * size);

	i = 0, j = 1;
	while (i < size) {
		new_array[i] = 1 / sqrt(j * a);
		i++;
		j++;
	}

	*break_ptr = &new_array[size - 1];

	fprintf(fptr, "square_series(%.4lf,%.4lf):\n", a, break_value);

	even = 0;
	i = 0;
	while (i < size - 1) {
		if (even % 2 == 0) {
			fprintf(fptr, "%.4lf - ", new_array[i]);
			even = 1;
		} else {
			fprintf(fptr, "%.4lf + ", new_array[i]);
			even = 0;
		}
		i++;
	}
	fprintf(fptr, "%.4lf\n", new_array[size - 1]);
	fprintf(fptr, "sum = %.4lf\n", sum);
	return new_array;
}
