# include <stdio.h>
# include "R2.h"

void test_factorial();
void test_solve();
void test_is_double();
void test_is_fraction();
void test_get_month();
void test_classify_num1();
void test_classify_num2();
void test_count_odds_evens();

int main() {
	setbuf(stdout, NULL);
	test_factorial();
	test_solve();
	test_is_double();
	test_is_fraction();
	test_get_month();
	test_classify_num1();
	test_classify_num2();
	test_count_odds_evens();
	return 0;
}

void test_factorial() {
	int cases[6] = { -1, 0, 1, 2, 3, 14 };
	int i;
	unsigned long result;

	printf("Start: Testing factorial\n");
	for (i = 0; i < 6; i++) {
		result = factorial(cases[i]);
		printf("Factorial(%d) = %lu\n", cases[i], result);
	}
	printf("End: Testing factorial\n");
	printf("------------------------------\n");
	return;
}

void test_solve() {
	printf("Start: Testing solve\n");
	solve(5, 4, 10, 2);
	solve(0, 1, 2, 3);
	printf("End: Testing solve\n");
	printf("------------------------------\n");
	return;
}

void test_is_double() {
	float cases[4] = { 1.2, 1.0, 5.5, 6.0 };
	int i;

	printf("Start: Testing is_double\n");
	for (i = 0; i < 4; i++)
		printf("is_double(%.2f) --> %d\n", cases[i], is_double(cases[i]));
	printf("End: Testing is_double\n");

	printf("------------------------------\n");
}

void test_is_fraction() {
	float cases[4] = { 1.0 / 5, 6.0 / 2, 3.0 / 9, 8.2 / 4 };
	int i;

	printf("Start: Testing is_fraction\n");
	for (i = 0; i < 4; i++)
		printf("is_fraction(%.2f) --> %d\n", cases[i], is_fraction(cases[i]));

	printf("End: Testing is_fraction\n");
	printf("------------------------------\n");
}

void test_get_month() {
	printf("Start: Testing get_month\n");
	for (int i = 0; i < 4; i++)
		get_month();
	printf("End: Testing get_month\n");
	printf("------------------------------\n");
	return;
}

void test_classify_num1() {
	printf("Start: Testing classify_num1\n");
	int cases[5] = { 18, 17, -11, -12, 0 };
	for (int i = 0; i < 5; i++) {
		printf("%d -->", cases[i]);
		classify_num1(cases[i]);
	}
	printf("End: Testing classify_num1\n");
	printf("------------------------------\n");
	return;
}

void test_classify_num2() {
	printf("Start: Testing classify_num2\n");
	int cases[5] = { 18, 17, -11, -12, 0 };
	for (int i = 0; i < 5; i++) {
		printf("%d -->", cases[i]);
		classify_num2(cases[i]);
	}
	printf("End: Testing classify_num2\n");
	printf("------------------------------\n");
	return;
}

void test_count_odds_evens() {
	printf("Start: Testing count_odds_evens:\n");

	short cases[4] = { 4, 5, 12, 12 };
	for (int i = 0; i < 4; i++) {
		printf("Starting new game:\n");
		count_odds_evens(cases[i]);
		printf("\n");
	}

	printf("End: Testing count_odds_evens\n");
	printf("------------------------------\n");
	return;
}
