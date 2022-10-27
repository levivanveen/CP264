/*
 * ---------------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student Email: vanv2490@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <stdlib.h>
# include "A4.h"

//-------------------------Task 1 ----------------------------
void update_array(int **array, const int size, int multiplier) {
	if (multiplier <= 0) {
		printf("Error (update_array): invalid multiplier\n");
		return;
	}
	if (multiplier == 1)
		return;

	int temp = 0, j = size;

	*array = (int*) realloc(*array, (sizeof(**array) * size * multiplier) + 1);

	for (int i = 0; i < size * multiplier + 1; i++) {
		*(*array + j) = *(*array + i);
		j++;
	}
	j = 0;

	for (int i = 0; i < size * multiplier + 1; i++) {
		if (i % multiplier == 0) {
			temp = *(*array + ((size * multiplier) - size + j));
			j++;
		}
		*(*array + i) = temp;
	}
	return;
}

//-------------------------Task 2 ----------------------------
void format_city(char *city) {
	int i = 1, space = False;
	if (islower(city[0]))
		city[0] = toupper(city[0]);
	for (i = 1; i < MAX; i++) {
		if (isspace(city[i])) {
			city[i] = toupper(city[i + 1]);
			i++;
			space = True;
			break;
		}
	}
	while (space && i < MAX) {
		if (isalpha(city[i + 1])) {
			city[i] = city[i + 1];
		} else
			city[i] = '\0';
		i++;
	}

	return;
}

void format_cities(char city_array[][MAX], const int size) {
	if (size < 1) {
		printf("Error(format_cities): invalid size\n");
		return;
	}
	if (!city_array) {
		printf("Error(format_cities): array is NULL\n");
		return;
	}
	int i = 0;

	for (i = 0; i < size; i++) {
		format_city(city_array[i]);
	}
	return;
}

//-------------------------Task 3 ----------------------------

void format_str(const char *inStr, char *outStr) {
	/*
	 * String Length = 0
	 After middle caps =
	 After split =
	 After First half reverse =
	 After Second half reverse =
	 */
//Finding string length
	int i = 0, length = strlen(inStr);
	printf("        String Length = %d\n", length);

//Middle Caps
	for (i = 0; i < length; i++) {
		outStr[i] = toupper(inStr[i]);
	}
	outStr[0] = tolower(inStr[0]);
	outStr[length - 1] = tolower(inStr[length - 1]);

	printf("        After middle caps = ");
	for (i = 0; i < length; i++)
		printf("%c", outStr[i]);
	printf("\n");

//Split
	for (i = length + 1; i > (length / 2); i--) {
		outStr[i] = outStr[i - 1];
	}
	outStr[i] = ' ';

	printf("        After split = ");
	for (i = 0; i < length + 1; i++)
		printf("%c", outStr[i]);
	printf("\n");

//Reverse Left Side
	char temp;
	for (i = 0; i < (length / 4); i++) {
		temp = outStr[i];
		outStr[i] = outStr[(length / 2) - i - 1];
		outStr[(length / 2) - i - 1] = temp;
	}

	printf("        After First half reverse = ");
	for (i = 0; i < length + 1; i++)
		printf("%c", outStr[i]);
	printf("\n");

//Reverse Right Side
	length++;
	int j = 0, mid = length / 2;

	if (length % 2 == 0) {
		for (i = mid + (length % 2); i < mid + (length / 4); i++) {
			temp = outStr[i];
			outStr[i] = outStr[length - 1 - j];
			outStr[length - 1 - j] = temp;
			j++;
		}
	} else {
		for (i = mid + (length % 2); i <= mid + (length / 4); i++) {
			temp = outStr[i];
			outStr[i] = outStr[length - 1 - j];
			outStr[length - 1 - j] = temp;
			j++;
		}
	}

	printf("        After Second half reverse = ");
	for (i = 0; i < length; i++)
		printf("%c", outStr[i]);
	printf("\n");
	return;
}

//-------------------------Task 4 ----------------------------

int* get_multiples_array1(int *multiples, const int size) {
	if (!multiples) {
		printf("Error(get_multiples_array1): invalid array\n");
		return NULL;
	}
	if (size <= 0) {
		printf("Error(get_multiples_array1): invalid size\n");
		return NULL;
	}

	int i = 0, temp, column = 10, j = 0, count = 1;
	int *multArry;
	multArry = (int*) malloc(size * column * sizeof(int));

	for (i = 0; i < size * column; i++) {
		if (i % 10 == 0) {
			temp = multiples[j];
			j++;
			count = 1;
		}
		if (temp * count < 1000) {
			multArry[i] = temp * count;
		} else
			multArry[i] = 0;
		count++;
	}
	return multArry;
}

void print_multiples1(int *array, const int size) {
	if (!array) {
		printf("Error(print_multiples1): invalid array\n");
		return;
	}
	if (size <= 0) {
		printf("Error(print_multiples1): invalid size\n");
		return;
	}
	for (int i = 0; i < size * 10; i++) {
		if ((i + 1) % 10 == 0)
			printf("%3d", array[i]);
		else
			printf("%3d ", array[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	return;
}

//-------------------------Task 5 ----------------------------
int** get_multiples_array2(int *multiples, const int size) {
	if (!multiples) {
		printf("Error(get_multiples_array2): invalid array\n");
		return NULL;
	}
	if (size <= 0) {
		printf("Error(get_multiples_array2): invalid size\n");
		return NULL;
	}

	int col = 10, i = 0, j = 0, temp = 1;
	int **multArr = (int**) malloc(size * sizeof(int*));

	for (i = 0; i < size; i++)
		multArr[i] = (int*) malloc(col * sizeof(int));

	for (i = 0; i < size; i++) {
		for (j = 0; j < col; j++) {
			if (temp * multiples[i] < 1000)
				multArr[i][j] = temp * multiples[i];
			else
				multArr[i][j] = 0;
			temp++;
		}
		temp = 1;
	}

	return multArr;
}

void print_multiples2(int **array, const int size) {
	if (!array) {
		printf("Error(print_multiples2): invalid array\n");
		return;
	}
	if (size <= 0) {
		printf("Error(print_multiples2): invalid size\n");
		return;
	}
	int i = 0, j = 0;

	for (i = 0; i < size; i++) {
		for (j = 0; j < 10; j++) {
			if (j == 9)
				printf("%3d", array[i][j]);
			else
				printf("%3d ", array[i][j]);
		}
		printf("\n");
	}

	return;
}
