/**
 * -------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student email: vanv2490@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include "A3.h"
# include <math.h>

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of integers (int*)
 * 	  size: size of an array (const int)
 * 	  value: some value to search for in the array (int)
 * returns:
 * 	  ptr: pointer to some element in the array (int*)
 * Description:
 *    Searches for the "value" in the array and identifies the first occurrence
 *    There are four scenarios:
 *    	1- if value is found at the last element --> ptr should point to last element
 *    	2- if value is found at any other location --> ptr should point to the next element
 *    	3- if value is not found --> ptr should point to the first element
 *      4- if the array pointer is NULL or the size is invalid --> ptr point to NULL
 * -------------------------------------------------------------------
 */
int* find_next(int *array, const int size, int value) {
	int *ptr;
	int i = 0, found = 0;
	if (array == NULL || size < 1) {
		return ptr = NULL;
	}
	ptr = &array[0];
	while (i < size && !found) {
		if (array[i] == value) {
			if (i == size - 1)
				ptr = &array[i];
			else
				ptr = &array[i + 1];
			found = 1;
		}
		i++;
	}
	return ptr;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of unknown data type (void*)
 * 	  size: size of the array (const int)
 * 	  indx: array index of the element to increment (int)
 * 	  char: array mode which controls the data type of the array. Defined types:
 * 	  		'i': integer
 * 	  		'l': long
 * 	  		'f': float
 * 	  		'd': double
 * returns: no returns
 * Description:
 *    Increments the value of the element at array[indx]
 *    Prints the value before increment
 *    The function should handle arrays of types: integer, long, float and double
 *    Before incrementing the function should print the current value at array[indx]
 *    There are four error scenarios:
 *    	1- array pointer is NULL
 *    	2- invalid array size
 *    	3- invalid value for indx
 *      4- invalid mode
 *    Whenever an error is detected, an error msg is printed
 * -------------------------------------------------------------------
 */
void increment_element(void *array, const int size, int indx, char mode) {
	if (array == NULL) {
		printf("Error(increment_element): NULL array\n");
		return;
	}
	if (size < 0) {
		printf("Error(increment_element): invalid size\n");
		return;
	}
	if (indx < 0 || indx >= size) {
		printf("Error(increment_element): invalid indx\n");
		return;
	}

	if (mode == 'l') {
		long *ptr;
		ptr = array;
		printf("Value before increment = %ld\n", ptr[indx]);
		ptr[indx] = ptr[indx] + 1;

	} else if (mode == 'd') {
		double *ptr;
		ptr = array;
		printf("Value before increment = %.2lf\n", ptr[indx]);
		ptr[indx] = ptr[indx] + 1;

	} else if (mode == 'f') {
		float *ptr;
		ptr = array;
		printf("Value before increment = %.2f\n", ptr[indx]);
		ptr[indx] = ptr[indx] + 1;

	} else if (mode == 'i') {
		int *ptr;
		ptr = array;
		printf("Value before increment = %d\n", ptr[indx]);
		ptr[indx] = ptr[indx] + 1;

	} else {
		printf("Error(increment_element): invalid mode\n");
		return;
	}
	return;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of integers (int*)
 * 	  size: size of an array (const int)
 * 	  ptr:  double pointer to store location of average element
 * returns:
 * 	  no returns
 * Description:
 *    1- Finds the average of the values within the array and print it to the console.
 *    	Use 1 decimal point.
 *    2- The average is "ceiled", i.e. rounded to the upper integer value.
 *    3- Search the array for an element that is equal to the average,
 *      	and sets avg_pointer to that element
 *    	If there are multiple values equal to the average, a pointer to the
 *      	first element that equals to average is used
 *    	If no value is equal to the average, a pointer to the value
 *      	closest to the average is returned.
 *    4- prints an error message if
 *    		array pointer is NULL, invalid size or avg_ptr is NULL
 * -------------------------------------------------------------------
 */
void find_avg_element(int *array, const int size, int **avg_ptr) {
	if (size <= 0) {
		printf("Error(find_avg_element): invalid array size\n");
		return;
	}
	if (array == NULL) {
		printf("Error(find_avg_element): NULL pointer\n");
		return;
	}
	if (avg_ptr == NULL) {
		printf("Error(find_avg_element): invalid pointer\n");
		return;
	}
	double average = 0;
	int i = 0, closest = 0, gap = 0;

	for (i = 0; i < size; i++) {
		average = average + array[i];
	}
	average = average / size;
	average = ceil(average);

	for (i = 0; i < size; i++) {
		if (array[i] == average) {
			*avg_ptr = &array[i];
			return;
		} else {
			int new_gap = fabs(average - array[i]);
			if (new_gap < gap) {
				closest = i;
			}
			gap = new_gap;
		}

	}
	*avg_ptr = &array[closest];
	return;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of floats (float*)
 * 	  ptrs: an array of float pointers (float* [])
 * returns:
 * 	  No returns
 * Description:
 * 	  An array of float items is passed. The size of the array is unknown
 *    The pointer array stores some pointers to elements in the array
 *	  The size of the pointer array is unknown, but the maximum possible size is MAX
 *	  When iterating through the pointer array, if you encounter a NULL, then this is the end
 *    Access the pointer array to print the following:
 *    1-	The value of the element it points to
 *    2-	The index of that element in the array
 *    3-	The value of the previous element
 *    			If the pointer points to the first element, previous value is 0
 *    Assume that both array and ptrs are not NULL
 *    All printing follow a format space of 13 digits, and 2 decimal places
 * -------------------------------------------------------------------
 */
void print_ptr_array(double *array, double *ptrs[]) {
	int i = 0, index = 0, found = 0;
	double *ptr;
	double previous = 0;

	printf("Value        Index        Previous    \n");

	while (ptrs[i] != NULL) {
		ptr = ptrs[i];
		index = 0;
		found = 0;
		while (&array[index] != NULL && !found) {
			if (&array[index] == ptr) {
				found = 1;
			} else
				index++;
		}
		if (index == 0)
			previous = 0;
		else
			previous = array[index - 1];
		printf("%-13.2lf%-13d%-13.2lf\n", *ptr, index, previous);
		i++;
	}

	return;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of shorts (short*)
 * 	  ptr: a pointer to an item in the array (short*)
 * returns:
 * 	  No returns
 * Description:
 * 	  An array of shorts is given, and you do not know its size
 * 	  However, you know the following about the array:
 * 	  	1- the minimum length is 3 items
 * 	  	2- The first element has a value of 1
 * 	  	3- The last element has a value of 1
 *    You are given some pointer to an element in the array.
 *    The pointer points to some item other than the first and last items
 *	  Your job is to print all the items in the array in the following format:
 *	  	[items before pointer]-->[items after pointer]
 *	  The printing ignores the first and last items which have the value of 1
 *    The function should print an error message if the array or the pointer is NULL
 * -------------------------------------------------------------------
 */
void special_array_print(short *array, short *ptr) {
	if (array == NULL) {
		printf("Error(special_array_print): NULL pointer\n");
		return;
	}
	if (ptr == NULL) {
		printf("Error(special_array_print): invalid pointer\n");
		return;
	}
	int i = 0;

	while (array[i] != 1)
		i++;
	i++;

	printf("[");
	while (array[i] != *ptr) {
		printf("%d", array[i]);
		i++;
		if (array[i] != *ptr)
			printf(", ");
	}
	printf("]-->[");
	i++;
	while (array[i] != 1) {
		printf("%d", array[i]);
		i++;
		if (array[i] != 1)
			printf(", ");
	}
	printf("]\n");

	return;
}

