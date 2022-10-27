/**
 * -------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student email: vanv2490@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# define True 1
# define False 0
# define SIZE 11

int list[SIZE] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; //Global list

/**
 * --------------------------------------------------------
 * Parameters:
 * 		number of rounds (int)
 * returns:
 * 		total cost (double)
 * Description:
 * 		(for loop implementation)
 * 		computes the total cost of purchses
 * 		The function asks the user to enter number of items and unit price
 * 		The above is repeated as many as "rounds" or if the user enters -1
 * 		The total cost of all purchases is returned
 * ----------------------------------------------------------
 */

double calc_price1(int rounds) {
	double total = 0.0, item_total;
	int num_items, i;
	float unit_price;
	const float TAX = 1.13;

	for (i = 0; i < rounds; i++) {
		item_total = 0.0;
		printf("Enter unit price for item %d: ", i + 1);
		scanf("%f", &unit_price);

		if (unit_price == -1.0) {
			printf("\n");
			break;
		}

		printf("Enter number of units: ");
		scanf("%d", &num_items);

		item_total = (num_items * unit_price) * TAX;
		printf("Item total = %.2lf\n", item_total);

		total += item_total;
		printf("\n");
	}
	printf("Total Cost = %.3lf\n", total);

	return total;
}
/**
 * --------------------------------------------------------
 * Same as calc_price1 but with while loop implementation
 * ----------------------------------------------------------
 */

double calc_price2(int rounds) {
	double total = 0.0, item_total;
	int num_items, i = 0;
	;
	float unit_price;
	const float TAX = 1.13;

	printf("Enter unit price for item %d: ", i + 1);
	scanf("%f", &unit_price);

	while (unit_price != -1 && i < rounds) {
		item_total = 0.0;

		printf("Enter number of units: ");
		scanf("%d", &num_items);

		item_total = (num_items * unit_price) * TAX;
		printf("Item total = %.2lf\n", item_total);

		total += item_total;
		printf("\n");

		i++;
		if (i == rounds)
			break;
		printf("Enter unit price for item %d: ", i + 1);
		scanf("%f", &unit_price);
	}
	if (unit_price == -1)
		printf("\n");
	printf("Total Cost = %.3lf\n", total);

	return total;
}

/**
 * --------------------------------------------------------
 * Same as calc_price1 but with do-while loop implementation
 * ----------------------------------------------------------
 */

double calc_price3(int rounds) {
	int i = 0, num_items;
	float unit_price;
	double total = 0.0, item_total;
	const float TAX = 1.13;

	do {
		printf("Enter unit price for item %d: ", i + 1);
		scanf("%f", &unit_price);

		if (unit_price != -1) {

			printf("Enter number of units: ");
			scanf("%d", &num_items);

			item_total = (num_items * unit_price) * TAX;
			printf("Item total = %.2lf\n", item_total);

			total += item_total;
			i++;
		} else {
			i = rounds;
		}
		printf("\n");
	} while (i < rounds);

	printf("Total Cost = %.3lf\n", total);
	return total;
}

/**
 * --------------------------------------------------------
 * Parameters:
 * 		height and length of base (int)
 * 		direction (char)
 * 		drawing symbol (char)
 * returns:
 * 		None
 * Description:
 * 		Draws a triangle with equal height and base length
 * 		Direction is either L or R
 * 		The function uses given drawing symbol to draw triangle
 * 		If direction is other than L or R, print error msg and return
 * 		If length is negative, print error msg and return
 * ----------------------------------------------------------
 */
void draw_triangle(int height, char direction, char symbol) {
	int i, j;

	if (height < 0) {
		printf("Error(draw_triangle): invalid height\n");
		return;
	}
	if (direction == 'L') {
		for (i = 0; i < height; i++) {
			for (j = 0; j <= i; j++)
				printf("%c", symbol);
			printf("\n");
		}
	} else if (direction == 'R') {
		for (i = 0; i < height; i++) {
			for (j = 0; j < height - i - 1; j++)
				printf(" ");
			for (j = 0; j <= i; j++)
				printf("%c", symbol);
			printf("\n");
		}
	} else
		printf("Error(draw_triangle): invalid direction\n");
	return;
}

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

void swap_mid() {
	int length = len();
	if (length % 2 == 0) {
		printf("Error(swap_mid): invalid length\n");
		return;
	}
	int mid_indx = length / 2;
	int temp[SIZE / 2];
	int i;

	for (i = 0; i < mid_indx; i++)
		temp[i] = list[i];

	for (i = mid_indx; i < length; i++)
		list[i - mid_indx - 1] = list[i];

	for (i = 0; i < mid_indx; i++)
		list[mid_indx + i + 1] = temp[i];
	return;
}

