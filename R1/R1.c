/**
 -------------------------
 Student Name: Levi Van Veen
 Student ID: 200852490
 Student email: vanv2490@mylaurier.ca
 -------------------------
 **/
#include <stdio.h>
#include <math.h>
#include <limits.h>

void welcome();
void get_price();
void formatting();
void data_size();
void circle();

int main() {
	setbuf(stdout, NULL);
	welcome();
	printf("\n");
	get_price();
	printf("\n");
	formatting();
	printf("\n");
	data_size();
	printf("\n");
	circle();
	return 0;
}

void welcome() {
	printf("Hello C World!\n");
	printf("THis is my first program!\n");
	return;
}

void get_price() {
	const int TAX = 13;
	float price, total;
	char name[20];
	int quantity;

	printf("Enter product price: ");
	scanf("%f", &price);

	printf("Enter number of purchased items: ");
	scanf("%d", &quantity);

	printf("Enter product name: ");
	scanf("%s", name);

	total = price * quantity;
	total = total + total * ((double) TAX / 100);

	printf("Total price for buying %d items of %s after tax is $%.2f\n",
			quantity, name, total);
	return;
}

void formatting() {
	char area_code = 'r';
	unsigned int heat_peak = 32;
	char cold_peak = -23;
	char area_name[] = "PiTown";
	short distance = 3430;
	unsigned long phone = 1119994444;
	const float PI = 3.14159274;
	const double PI_PRECISE = 3.1415926535897931;

	printf("I live in %s", area_name);
	printf("in the area code %c", area_code);
	printf("which is %hd yards from the metro station\n\n", distance);

	printf(
			"The first letter of my city is '%c' and the second letter is '%c'.\n",
			area_name[0], area_name[1]);
	printf("This is the same as the mathematical constant ?\"PI\"\n\n");
	printf(
			"In math, the value of PI to seven digits = %f and to 16 digits is %lf\n\n",
			PI, PI_PRECISE);

	printf("The coldest temperature in %s is %c while the hottest is %u\n\n",
			area_name, cold_peak, heat_peak);
	printf("If you ever visit %s call me at my cell number \"%lu\"\n",
			area_name, phone);
	return;
}

void data_size() {
	printf("%-25s%-10s%-25s%-25s\n", "Data Type", "Bytes", "Min", "Max");
	printf(
			"-------------------------------------------------------------------------------\n");
	printf("%-25s%-10d%-25d%-25d\n", "char", sizeof(char), CHAR_MIN, CHAR_MAX);
	printf("%-25s%-10d%-25d%-25d\n", "unsigned char", sizeof(unsigned char), 0,
	UCHAR_MAX);
	printf("\n");
	printf("%-25s%-10d%-25d%-25d\n", "short", sizeof(short), SHRT_MIN,
	SHRT_MAX);
	printf("%-25s%-10d%-25d%-25d\n", "unsigned short", sizeof(unsigned short),
			0,
			USHRT_MAX);
	printf("\n");
	printf("%-25s%-10d%-25d%-25d\n", "int", sizeof(int), INT_MIN, INT_MAX);
	printf("%-25s%-10d%-25d%-25u\n", "unsigned int", sizeof(unsigned), 0,
	UINT_MAX);
	printf("\n");
	printf("%-25s%-10d%-25ld%-25lu\n", "long", sizeof(long), LONG_MIN,
	LONG_MAX);
	printf("%-25s%-10d%-25d%-25lu\n", "unsigned long", sizeof(unsigned long), 0,
	ULONG_MAX);
	printf("\n");
	printf("%-25s%-10d%-25I64d%-25I64d\n", "long long", sizeof(long long),
	LLONG_MIN, LLONG_MAX);
	printf("%-25s%-10d%-25d%-25I64u\n", "unsigned long long",
			sizeof(unsigned long long), 0, (unsigned long long) ULLONG_MAX);
	return;
}

void circle() {
	const double PI = 3.14;
	float r, h;
	double v;

	printf("Enter radius of the base circle: ");
	scanf("%f", &r);
	printf("Enter height of the cone: ");
	scanf("%f", &h);

	v = ((double) 1 / 3) * PI * h * pow(r, 2);
	printf("v = %.2lf", v);
	return;
}
