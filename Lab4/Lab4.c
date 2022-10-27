# include <stdio.h>
# define MAX 12
# define True 1
# define False 0

//---------------------------------------------------------
/**
 * Parameters:
 * 		array: a pointer to an integer array (int*)
 * 		size: size of given array (const int)
 * 		value: integer to be searched in the array (int)
 * 		last: a double pointer to reference a pointer to last element (int**)
 * returns:
 * 		first: a pointer to reference to first element (int*)
 * Description:
 *    	Searches given array for the occurrence of value
 *    	A pointer to the first occurrence of value in the array is returned
 *    	A pointer to the last occurrence of value in the array is assigned to the last double pointer
 *    	If given array is NULL, prints an error message and returns NULL pointer
 *    	If given size is invalid, prints an error message and returns NULL pointer
 *    	If item is not found, returns NULL pointer.
 */
int* find_match(int *array, const int size, int value, int **last) {
	int *first = NULL, found = False, i = 0, recent;
	if (size < 0) {
		printf("Error(find_match): invalid size");
		first = NULL;
		last = NULL;
		return first;
	}
	if (array == NULL) {
		printf("Error(find_match): NULL pointer");
		first = NULL;
		last = NULL;
		return first;
	}
	for (i = 0; i < size; i++) {
		if (array[i] == value) {
			if (first == NULL)
				first = &array[i];
			found = True;
		}
		if (found == True)
			recent = i;
		found = False;
	}

	if (first == NULL) {
		first = NULL;
		last = NULL;
		return first;
	}

	*last = &array[recent];

	return first;
}

/**
 * Parameters:
 * 		array: a pointer to an integer array (int*)
 * 		size: size of given array (const int)
 * 		value: integer to be searched in the array (int)
 * returns:
 * 		None
 * Description:
 *    	Function to test find_match function
 *    	1- Prints contents of array
 *    	2- Print memory addresses of first and last item in array
 *    	3- Print values dereferenced by first and last pointers
 *    	4- Print memory addresses of first and last match
 *    	5- Print index of first and last match
 *    	6- Print value after first match
 *    	7- Print value before last match
 */
void test_find_match(int *array, const int size, int value) {
	//Do not change this block
	//-----------------------------------------
	int *first = NULL, *last = NULL;
	first = find_match(array, size, value, &last);

	if (first == NULL && last == NULL) {
		printf("first = NULL and last = NULL\n\n");
		return;
	}
	//-----------------------------------------
	int i = 0;
	printf("Looking for %d in the array: {", value);
	for (i = 0; i < size - 1; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d}\n\n", array[size - 1]);

	//Edit the two lines to print the address of the start and end of the array
	printf("First item in the array starts at memory address: %p\n",
			&(array[0]));
	printf("Last item in the array starts at memory address: %p\n\n",
			&(array[size - 1]));

	//Edit these two lines
	printf("The first pointer points to value: %d \n", *first);	//edit this line
	printf("The last pointer points to value: %d\n", *last);	//edit this line
	printf("\n");

	//Edit these two lines
	printf("First match is located at memory address: %p\n", &first);
	printf("Last match is located at memory address %p\n", &last);
	printf("\n");

	//Edit these two lines:
	printf("Index of first match is %d\n", first - array);
	printf("Index of last match is %d\n", last - array);
	printf("\n");

	//Edit these two lines:
	printf("Value after first match is %d\n", *(first + 1));
	printf("Value before last match is %d\n", *(last - 1));
	printf("\n");

	return;
}

//Do not edit main function
int main() {
	setbuf(stdout, NULL);
	int nums[MAX] = { 22, 25, 20, 27, 22, 20, 24, 19, 28, 26, 23, 24 }, size =
	MAX;

	printf("Case 1: Invalid array pointer:\n");
	test_find_match(NULL, size, 12);
	printf("------------------------\n");

	printf("Case 2: Invalid array size\n");
	test_find_match(nums, -2, 16);
	printf("------------------------\n");

	printf("Case 3: Item not found\n");
	test_find_match(nums + 3, size - 3, 1);
	printf("------------------------\n");

	printf("Case 4: First item at start and last at the middle\n");
	test_find_match(nums, size - 1, 22);
	printf("------------------------\n");

	printf("Case 5: First and last item at the middle\n");
	test_find_match(nums, size, 19);
	printf("------------------------\n");

	printf("Case 6: First and last item is the same\n");
	test_find_match(nums, size, 28);
	printf("------------------------\n");

	printf("Case 7: First item at the middle and last at the end\n");
	test_find_match((nums + 2), size - 2, 24);
	printf("------------------------\n");

	return 0;
}
