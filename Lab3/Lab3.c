/*
 * ---------------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student Email: vanv2490@mylaurier.ca
 * ---------------------------------
 */

# include <stdio.h>
# define True 1
# define False 0
# define SIZE 11
# define ERROR_CODE -99

int list[SIZE] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; //Global list

//---------------------------------------------------------
/**
 * Parameters:
 * 		size: number of elements to fill in the list (int)
 * returns:
 * 		None
 * Description:
 *    Initialize global list by filling items from 0 up to size
 *    with integer values starting from 0. All other elements set to -1
 *    If given size is negative or more than 10, print error msg and return
 */
void init(int size) {
	if (size < 0 || size >= SIZE) {
		printf("Error(init): invalid size\n");
		return;
	}

	int i;
	for (i = 0; i < size; i++)
		list[i] = i;
	for (i = size; i < SIZE; i++)
		list[i] = -1;
	return;

}

//---------------------------------------------------------
/**
 * Parameters:
 * 		None
 * returns:
 * 		length of global vector (int)
 * Description:
 *    Finds the length of the global vector, i.e. number of elements
 *    length is defined as number of elements until -1 is found
 *    Sample output1: list = {-1} --> 0
 *    Sample output2: list = {1,2,3,-1}--> 3
 */
int len() {
	int length = 0, i;
	for (i = 0; i < SIZE; i++) {
		if (list[i] != -1)
			length++;
		else
			break;
	}

	return length;
}

//----------------------------------------------------
/**
 * Parameters:
 * 		None
 * returns:
 * 		None
 * Description:
 *    prints the contents of the global list
 *    The contents of the list up to (exclusive) of -1 should be printed
 *    Sample output1: vector = {-1} --> []
 *    Sample output2: vector = {1,2,3,-1}--> [1,2,3]
 */
void print() {
	int i, size = len();
	printf("[");
	for (i = 0; i < size; i++) {
		printf("%d", list[i]);
		if (i != size - 1)
			printf(",");
	}
	printf("]\n");
	return;
}

//----------------------------------------------------
/**
 * Parameters:
 * 		value: an integer to be added to list (int)
 * returns:
 * 		None
 * Description:
 *    Appends the given value to the list
 *    if list is full print an error message and return
 */
void append(int value) {
	if (len() == SIZE - 1)
		printf("Error(append): Overflow\n");
	else
		list[len()] = value;
	return;
}

//----------------------------------------------------
/**
 * Parameters:
 * 		pos: list index to insert new value at (int)
 * 		value: an integer to be added to list (int)
 * returns:
 * 		None
 * Description:
 *    Inserts the given value at the given position in the list
 *    if list is full or index out of range, print an error msg and return
 */
void insert(int pos, int value) {
	int size = len(), i;
	if (size == SIZE - 1) {
		printf("Error(insert): overflow\n");
		return;
	}
	if (pos >= SIZE - 1 || pos < 0) {
		printf("Error(insert): invalid position\n");
		return;
	}
	for (i = size - 1; i >= pos; i--)
		list[i + 1] = list[i];
	list[pos] = value;
	return;
}

//---------------------------------------------------------
/**
 * Parameters:
 * 		None
 * returns:
 * 		None
 * Description:
 *    Reverse the contents of the global list
 *    The function changes the contents of vector
 *    Sample outputs:
 *        vector = {1,2,-1} --> {2,1,-1}
 *        vector = {1,2,5,10,-1} --> {10,5,2,1,-1}
 *        vector = {-1} --> {-1}
 */
void reverse() {
	int temp[SIZE], j, size = len(), i = 0;

	temp[size] = -1;
	for (j = size - 1; j >= 0; j--)
		temp[i++] = list[j];
	for (j = 0; j < size; j++)
		list[j] = temp[j];
	return;
}

//---------------------------------------------------------
/**
 * Parameters:
 * 		None
 * returns:
 * 		None
 * Description:
 *    Sets all values in the global list into -1
 */
void clear() {
	int length = len();
	for (int i = 0; i < length; i++) {
		list[i] = -1;
	}
	return;
}

//---------------------------------------------------------
/**
 * Parameters:
 * 		value - a value to search for in the list
 * returns:
 * 		pos: the position of the given value in the list
 * Description:
 *    Finds the position of the given value in the list
 *    If the item is found, the position is returned.
 *    Otherwise, the function returns -1
 */
int indx(int value) {
	int pos = -1, length = len(), i = 0;
	while (i < length && pos == -1) {
		if (list[i] == value) {
			pos = i;
		} else
			i++;
	}

	return pos;
}

//---------------------------------------------------------
/**
 * Parameters:
 * 		value - an item to be removed from the list
 * returns:
 * 		None
 * Description:
 *    removes the first occurrence of the given value in the list
 *    if value not found print an error message and return
 */
void remove_item(int value) {
	int length = len(), pos, i = 0;
	pos = indx(value);
	if (pos == -1) {
		printf("Error(remove):item not found\n");
		return;
	}
	if (pos == length - 1) {
		list[pos] = -1;
		return;
	}
	for (i = pos; i < length; i++) {
		if (list[i] != -1) {
			list[i] = list[i + 1];
		}
	}
	return;
}

/**
 * Parameters:
 * 		pos - position of an item to be removed
 * returns:
 * 		None
 * Description:
 *    removes the list item at the given position
 *    If position is out of range: print an error message and return
 */
void del(int pos) {
	int i = 0, size = len();
	if (pos > size - 1 || pos < 0) {
		printf("Error(del):index out of range\n");
		return;
	}
	for (i = pos; i < size; i++) {
		if (list[i] != -1) {
			list[i] = list[i + 1];
		}
	}
	return;
}

/**
 * Parameters:
 * 		pos - position of an item to be removed
 * returns:
 * 		value - copy of item removed from the list
 * Description:
 *    removes the list item at the given position and returns a copy of it
 *    If position is out of range: print an error message and return ERROR_CODE
 */
int pop(int pos) {
	int value, size = len(), i = 0;
	if (pos > size - 1 || pos < 0) {
		printf("Error(pop):index out of range\n");
		return ERROR_CODE;
	}
	value = list[pos];
	for (i = pos; i < size; i++) {
		if (list[i] != -1) {
			list[i] = list[i + 1];
		}
	}
	return value;
}

