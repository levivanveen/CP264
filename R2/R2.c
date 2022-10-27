/**
 * -------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student email: vanv2490@mylaurier.ca
 * -------------------------
 */
#include <stdio.h>
#include <math.h>
# define True 1
# define False 0

/**
 * --------------------------------------------------------
 * Finds the factorial of a given number using recursion
 * The input is an integer and the return value is of type unsigned long
 * If the given input is less than 0, the function prints the following error msg:
 * 		Error(factorial): Invalid input
 * and returns 0
 * ----------------------------------------------------------
 */
unsigned long factorial(int n) {
	if (n < 0) {
		printf("Error(factorial): Invalid input\n");
		return 0;
	}

	if (n == 0 || n == 1)
		return 1;
	return n * factorial(n - 1);
}

/**
 * --------------------------------------------------------
 * Computes the value of a using the four integer input parameters: r,y,x and b.
 * The value of a is computed according to the following equation:
 *		a = floor((cube(3)-y)/x) - square_root(b to power 4))
 * The function prints the output in a format similar to the following
 *		[r = 2, y = 3, x = 2, b = 2] --> a = -2.0
 * The function also returns the value of a, which is of type double
 * ----------------------------------------------------------
 */
double solve(int r, int y, int x, int b) {

	double a, expr1, expr2;
	expr1 = (pow(r, 3) - y) / x;
	expr2 = sqrt(pow(b, 4));
	a = floor(expr1 - expr2);
	printf("[r = %d, y = %d, x = %d, b = %d]--> a = %.1f\n", r, y, x, b, a);
	return a;
}

/**
 * --------------------------------------------------------
 * Checks if a given number is a whole number or not.
 * If the number is whole, e.g. 1.0 or 200.00, the function returns 0
 * If the number is not whole (double), the function returns 1.
 * Note that double here does not mean the data type double,
 * it simply means non-whole numbers.
 * ----------------------------------------------------------
 */
int is_double(double x) {
	return !(x - (int) x == 0);;
}

/**
 * --------------------------------------------------------
 * Checks if a given number is a fraction in the range (-1,1), excluding 0
 * Examples of fractions: 0.34, -0.69, 0.9999
 * Invalid fractions include -1, 1 ,2.3 ,1.4 ,0
 * If the given number is a fraction the function returns true
 * Otherwise, returns false
 * ----------------------------------------------------------
 */
int is_fraction(double x) {
	if (x > -1.0 && x < 1.0 && x != 0.0)
		return True;
	return False;
}

/**
 * --------------------------------------------------------
 * Finds the number of days in a given month
 * The function asks the user to enter a number, and the uses switch statement
 * to print one of the following outputs:
 * 		31 days
 * 		30 days
 * 		28/29 days
 * 		Invalid input
 * The function receives no parameters and makes no returns
 * ----------------------------------------------------------
 */
void get_month() {
	int month;
	printf("Enter month number(1-12): ");
	scanf("%d", &month);

	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		printf("31 days\n");
		break;
	case 2:
		printf("28/29 days\n");
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		printf("30 days\n");
		break;
	default:
		printf("Invalid input!\n");
	}
	return;
}

/**
 * --------------------------------------------------------
 * Classify an input integer in terms of being even/odd and positive/negative
 * The function is implemented using the ternary operator
 * The function prints one of the following outputs:
 * 		This is an even positive number
 * 		This is an even negative number
 * 		This is an odd positive number
 * 		This is an odd negative number
 * The function does not provide a proper classification for the number 0
 * The function does not return any value.
 * ----------------------------------------------------------
 */
void classify_num1(int num) {
	(num % 2 == 0) ? printf("This is an even ") : printf("This is an odd ");
	(num > 0) ? printf("positive number\n") : printf("negative number\n");
	return;
}

/**
 * --------------------------------------------------------
 * Classify an input integer in terms of being even/odd and positive/negative
 * The function is implemented using goto commands
 * The function prints one of the following outputs:
 * 		This is an even positive number
 * 		This is an even negative number
 * 		This is an odd positive number
 * 		This is an odd negative number
 * 		This is a zero!
 * The function does not return any value.
 * ----------------------------------------------------------
 */
void classify_num2(int num) {
	if (num == 0)
		goto Zero;
	else
		goto Nonzero;
	Zero: printf("This is a zero!\n");
	goto Finish;

	Nonzero: if (num % 2 == 0)
		goto Even;
	else
		goto Odd;

	Even: printf("This is an even ");
	goto NextCheck;

	Odd: printf("This is an odd");

	NextCheck: if (num > 0)
		printf("positive number\n");
	else
		printf("negative number\n");

	Finish: return;
}

void count_odds_evens(short rounds) {
	short finished, odds, evens, counter;
	int num;
	finished = 0;
	odds = 0;
	evens = 0;
	counter = 0;

	while (!finished) {
		printf("Enter a number: ");
		scanf("%d", &num);
		if (num == -1)
			finished = 1;
		else {
			if (num % 2 == 0)
				evens += 1;
			else
				odds += 1;
			counter += 1;
			if (counter == rounds)
				finished = 2;
			if (odds == 10 || evens == 10)
				finished = 3;
		}
	}
	printf("#odds = %hd, #evens = %hd , ", odds, evens);
	if (finished == 1)
		printf("Program aborted\n");
	else if (finished == 2)
		printf("Reached Maximum Rounds\n");
	else
		printf("Odds/Evens Reached Maximum Count\n");
	return;
}
