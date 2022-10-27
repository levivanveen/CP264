#include <stdio.h>
#include "R3.h"

void test_calc_price();
void test_draw();
void test_init_len_print();
void test_append_insert_reverse();
void test_swap_mid();

int main() {
	setbuf(stdout, NULL);
	test_calc_price();
	test_draw();
	test_init_len_print();
	test_append_insert_reverse();
	test_swap_mid();
	return 0;
}

void test_calc_price() {
	printf("Start: Testing calc_price:\n\n");

	printf("Case 1: For loop:\n");
	calc_price1(2);
	printf("\n");
	calc_price1(2);
	printf("\n");

	printf("Case 2: while loop:\n");
	calc_price2(2);
	printf("\n");
	calc_price2(2);
	printf("\n");

	printf("Case 3: do-while loop:\n");
	calc_price3(2);
	printf("\n");
	calc_price3(2);
	printf("\n");

	printf("End: Testing calc_price\n");
	printf("------------------------------\n");
	return;
}

void test_draw() {
	printf("Start: Testing draw_triangle\n\n");

	printf("draw_triangle(-1,L,*):\n");
	draw_triangle(-1, 'L', '*');
	printf("\n");

	printf("draw_triangle(5,S,*):\n");
	draw_triangle(5, 'S', '*');
	printf("\n");

	printf("draw_triangle(0,R,*):\n");
	draw_triangle(0, 'R', '*');
	printf("\n");

	printf("draw_triangle(1,R,*):\n");
	draw_triangle(1, 'R', '*');
	printf("\n");

	printf("draw_triangle(1,L,*):\n");
	draw_triangle(1, 'L', '*');
	printf("\n");

	printf("draw_triangle(2,R,#):\n");
	draw_triangle(2, 'R', '#');
	printf("\n");

	printf("draw_triangle(2,L,#):\n");
	draw_triangle(2, 'L', '#');
	printf("\n");

	printf("draw_triangle(5,R,$):\n");
	draw_triangle(5, 'R', '$');
	printf("\n");

	printf("draw_triangle(5,L,$):\n");
	draw_triangle(5, 'L', '$');
	printf("\n");

	printf("End: Testing draw_triangle\n");
	printf("------------------------------\n");
	return;
}

void test_init_len_print() {
	printf("Start: Testing init, len and print functions\n\n");
	int j;

	printf("Before initialization: \n");
	printf("len() = %d\n", len());
	print();
	printf("\n");

	for (j = -2; j <= 12; j = j + 2) {
		printf("init(%d)\n", j);
		init(j);
		printf("len() = %d\n", len());
		print();
		printf("\n");
	}

	printf("End: Testing init, len and print functions\n");
	printf("------------------------------\n");
	return;
}

void test_append_insert_reverse() {
	printf("Start: Testing append, insert, reverse\n");

	printf("Initialize:");
	init(0);
	print();
	reverse();
	printf("After reverse:");
	print();
	printf("\n");

	printf("insert(0,10): ");
	insert(0, 10);
	print();
	printf("After reverse:");
	reverse();
	print();
	printf("\n");

	printf("append(20): ");
	append(20);
	print();
	printf("insert(2,30): ");
	insert(2, 30);
	print();
	printf("After reverse:");
	reverse();
	print();
	printf("\n");

	printf("append(40): ");
	append(40);
	print();
	printf("insert(1,15): ");
	insert(1, 15);
	print();
	printf("After reverse:");
	reverse();
	print();
	printf("\n");

	printf("insert(-1,25): ");
	insert(-1, 25);
	print();
	printf("\n");

	printf("append(50): ");
	append(50);
	print();
	printf("append(60): ");
	append(60);
	print();
	printf("append(70): ");
	append(70);
	print();
	printf("append(80): ");
	append(80);
	print();
	printf("append(90): ");
	append(90);
	print();
	printf("append(100): ");
	append(100);
	print();
	printf("insert(0,100): ");
	insert(0, 100);
	print();
	printf("\n");

	printf("End: Testing append, insert, reverse\n");
	printf("------------------------------\n");
	return;
}

void test_swap_mid() {
	printf("Start: Testing swap_mid:\n\n");
	int i, j;

	for (j = 0; j < 10; j++) {
		printf("array before swap_mid: ");
		init(0);
		for (i = 10; i <= j * 10; i = i + 10)
			append(i);
		print();
		swap_mid();
		printf("array after swap_mid: ");
		print();
		printf("\n");
	}

	printf("End: Testing swap_mid\n");
	printf("------------------------------\n");
	return;
}
