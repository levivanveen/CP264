/**
 * -------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student email: vanv2490@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include <math.h>

double compute(double n, double p, double q) {
	double r, temp1, temp2, temp3;
	const float PI = 3.14159274;

	temp1 = fabs(n + p) / ceil(p - q);
	temp2 = floor(n * q) / pow(p * q, (double) 1 / 2);
	temp3 = pow(PI, 6) / log2(q - n);
	r = temp1 + temp2 - temp3;

	printf("n = %.4lf\n", n);
	printf("p = %.4lf\n", p);
	printf("q = %.4lf\n", q);
	printf("r = %.4lf + %.4lf - %.4lf\n", temp1, temp2, temp3);

	return r;
}

int print_country(short code) {
	int success = 1;

	if (code == 1)
		printf("USA");
	else if (code == 2)
		printf("Canada");
	else {
		printf("Undefined");
		success = 0;
	}
	return success;
}

int print_color(short code) {
	int success = 1;

	switch (code) {
	case 0:
		printf("Black");
		break;
	case 1:
		printf("Grey");
		break;
	case 2:
		printf("Brown");
		break;
	case 3:
		printf("Purple");
		break;
	case 4:
		printf("Blue");
		break;
	case 5:
		printf("Green");
		break;
	default:
		printf("Undefined");
		success = 0;
		break;
	}
	return success;
}

int print_size(short code) {
	int success = 1;

	switch (code) {
	case 0:
		printf("Tiny");
		break;
	case 1:
		printf("Small");
		break;
	case 2:
		printf("Medium");
		break;
	case 3:
		printf("Large");
		break;
	case 4:
		printf("Huge");
		break;
	default:
		printf("Undefined");
		success = 0;
		break;
	}
	return success;
}

short get_code(long serial_number, char type) {
	short code;

	if (serial_number < 99999 || serial_number > 1000000)
		code = -99;
	else {
		switch (type) {
		case 'y':
			code = serial_number / 100000;
			break;
		case 'r':
			code = (serial_number / 10000) % 10;
			break;
		case 's':
			code = (serial_number / 1000) % 10;
			break;
		case 'i':
			code = (serial_number % 1000);
			break;
		default:
			code = -99;
		}
	}
	return code;
}

void print_description(long serial_number) {
	short country_code, color_code, size_code, success1, success2, success3;
	int item_code, valid;

	country_code = get_code(serial_number, 'y');
	color_code = get_code(serial_number, 'r');
	size_code = get_code(serial_number, 's');
	item_code = get_code(serial_number, 'i');
	if (serial_number > 99999 && serial_number < 1000000)
		valid = 1;
	else
		valid = 0;

	printf("country = ");
	success1 = print_country(country_code);
	printf("\n");

	printf("color = ");
	success2 = print_color(color_code);
	printf("\n");

	printf("size = ");
	success3 = print_size(size_code);
	printf("\n");

	printf("item = %d\n", item_code);

	if (valid == 1) {
		printf("A Beautiful");
		if (success3 == 1) {
			printf(" ");
			success3 = print_size(size_code);
		}
		if (success2 == 1) {
			printf(" ");
			success2 = print_color(color_code);
		}
		printf(" Box item# %d", item_code);
		if (success1 == 1) {
			printf(" made in ");
			success1 = print_country(country_code);
		}
		printf("\n");
	} else
		printf("Description not found\n");

	return;
}

char math_game(long lv, int lmf, int lsf, int lrf, long rv, int rmf, int rsf,
		int rrf) {
	int counter, lcounter, rcounter;
	char winner;

	printf("Starting Math Game:\n");
	printf("[%ld,%d,%d,%d] vs [%ld,%d,%d,%d]\n", lv, lmf, lsf, lrf, rv, rmf,
			rsf, rrf);

	counter = 0;
	while (counter < 5 && lv < rv) {
		printf("Round = %d\n", (counter + 1));
		lcounter = 0;
		while (lcounter < lrf) {
			lv = lv * lmf - lsf;
			printf("L = %ld\n", lv);
			lcounter += 1;
		}
		rcounter = 0;
		while (rcounter < rrf) {
			rv = rv * rmf - rsf;
			printf("R = %ld\n", rv);
			rcounter += 1;
		}
		counter += 1;
	}
	printf("Closing Math Game\n");
	if (counter == 5)
		winner = 'R';
	else
		winner = 'L';

	return winner;
}
