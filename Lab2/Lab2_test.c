#include <stdio.h>
#include <stdlib.h>
# include <time.h>
#include "Lab2.h"

void test_rand_int();
void test_solve2();

int main() {
	setbuf(stdout, NULL);
	srand(time(0));
	test_solve2();
	test_rand_int();
	return 0;
}

void test_solve2() {
	printf("Start: Testing solve2\n");
	solve2(5, 4, 10.0, 2.5);
	printf("\n");
	solve2(0, 20, 6.71, 70.33);
	printf("End: Testing solve2\n");
	printf("------------------------------\n");
	return;
}

void test_rand_int() {
	printf("Start: Testing rand_int\n\n");
	printf("Testing mode '1':");
	printf("int_rand(2,10,'1') --> %u\n", rand_int(2, 10, '1'));
	printf("int_rand(5,7,'1') --> %u\n", rand_int(5, 7, '1'));
	printf("\n");

	printf("Testing mode '2':");
	printf("int_rand(2,10,'2') --> %u\n", rand_int(2, 10, '2'));
	printf("int_rand(5,7,'2') --> %u\n", rand_int(5, 7, '2'));
	printf("\n");

	printf("Testing mode 'i':");
	printf("int_rand(2,10,'i') --> %u\n", rand_int(2, 10, 'i'));
	printf("int_rand(5,7,'i') --> %u\n", rand_int(5, 7, 'i'));
	printf("\n");

	printf("Testing mode 'x':");
	printf("int_rand(2,10,'x') --> %u\n", rand_int(2, 10, 'x'));
	printf("int_rand(5,7,'x') --> %u\n", rand_int(5, 7, 'x'));
	printf("\n");

	printf("Testing mode 'L':");
	printf("int_rand(2,10,'L') --> %u\n", rand_int(2, 10, 'L'));
	printf("int_rand(5,7,'L') --> %u\n", rand_int(5, 7, 'L'));
	printf("\n");

	printf("Testing mode 'R':");
	printf("int_rand(2,10,'R') --> %u\n", rand_int(2, 10, 'R'));
	printf("int_rand(5,7,'R') --> %u\n", rand_int(5, 7, 'R'));
	printf("\n");

	printf("Testing mode 'M':");
	printf("int_rand(2,10,'M') --> %u\n", rand_int(2, 10, 'M'));
	printf("int_rand(5,7,'M') --> %u\n", rand_int(5, 7, 'M'));
	printf("\n");

	printf("End: Testing rand_int\n");
	printf("------------------------------\n");
	return;
}
