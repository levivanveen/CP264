/**
 -------------------------
 Student Name: Levi Van Veen
 Student ID: 200852490
 Student email: vanv2490@mylaurier.ca
 -------------------------
 **/
#include <stdio.h>;

int main(void) {
	t1();
	printf("\n");
	t2();
	printf("\n");
	t3();
	return 0;
}

int t1() {
	int tall, small, total;
	double avg_height;
	int symbol = 84;
	const int VAL = 43;

	printf("Enter number of tall trees: ");
	scanf("%d", &tall);
	printf("Enter number of short trees: ");
	scanf("%d", &small);
	total = tall + small;
	//printing report
	printf("Number of %c trees = %d\n", symbol, tall);
	printf("Number of %c trees = %d\n", (symbol - 1), small);
	printf("Average height = %.2lf\n", (VAL / (double) total));
	return 0;
}

int t2() {
	unsigned int year;
	short month;
	int day;
	char university[30];

	printf("Enter year: ");
	scanf("%u", &year);
	printf("Enter month: ");
	scanf("%hd", &month);
	printf("Enter day: ");
	scanf("%d", &day);
	printf("Enter university: ");
	scanf("%s", &university);

	printf("This is %s\n", university);
	printf("Today is: %d/%hd/%u\n", day, month, year);

	return 0;
}

int t3() {
	printf("Hints for C Language:\n");
	printf("Insert '\\n' at end of printf for newline.\n");
	printf("Use \"double quote\" not 'single quotes' for stings.\n");
	printf("Use %%d for integer, %%f for float and %%lf for double.\n");
	return 0;
}
