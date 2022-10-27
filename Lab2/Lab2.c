/**
 -------------------------
 Student Name: Levi Van Veen
 Student ID: 200852490
 Student email: vanv2490@mylaurier.ca
 -------------------------
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
void solve2(short w, int x, float y, double z) {
	double r, temp1, temp2, temp3;

	temp1 = (log(y) * fabs((pow(w, 2)) - x));
	temp2 = (exp(5)) * fabs(y * pow(z, 3));
	temp3 = pow(pow(x, y) - y, (double) 1 / 3);

	r = temp1 + temp2 - temp3;

	printf("\n");
	printf("w = %10hd x = %10d\n", w, x);
	printf("\n");
	printf("y = %10.2f z = %10.4lf\n", y, z);
	printf("\n");
	printf("r = %10.4f\n", r);

	return;
}

/**
 * --------------------------------------------------------
 * Generates and returns a random integer.
 * the mode input parameter controls how the random number is generated, as follows:
 * 1-	If mode is �1�: The function generates a random number in the range [0,x1], i.e. inclusive both ends.
 * 2-	If mode is �2�: The function generates a random number in the range (0,x2), i.e. exclusive both ends.
 * 3-	If mode is �i�: The function generates a random number in the range [x1,x2], i.e. inclusive both ends.
 * 4-	If mode is �x�: The function generates a random number in the range (x1,x2), i.e. exclusive both ends.
 * 5-	If mode is �L�: The function generates a random number in the range [x1,x2), i.e. inclusive only from the left which is x1.
 * 6-	If mode is �R�: The function generates a random number in the range (x1,x2], i.e. inclusive only from the right which is x2.
 * 7-	For any other mode value, the function generates a random number between 0 and RAND_MAX.
 * The function is implemented using switch-case statement.
 * Assume that x1 is always less than x2 by at least 2.
 * ----------------------------------------------------------
 */
unsigned int rand_int(unsigned int x1, unsigned int x2, char mode) {
	unsigned int randomInt;

	switch (mode) {
	case 1:
		randomInt = (rand() % (x1 - 0 + 1)) + 0;
		break;
	case 2:
		randomInt = (rand() % (x2 - 0 + 1)) + 0;
		break;
	case 'i':
		randomInt = (rand() % (x2 - x1 + 1)) + 0;
		break;
	case 'x':
		randomInt = (rand() % (x2 - x1 + 1)) + 0;
		break;
	case 'L':
		randomInt = (rand() % (x2 - x1 + 1)) + 0;
		break;
	case 'R':
		randomInt = (rand() % (x2 - x1 + 1)) + 0;
		break;
	default:
		randomInt = (rand() % (RAND_MAX - 0 + 1)) + 0;
		break;
	}

	return 0;
}
