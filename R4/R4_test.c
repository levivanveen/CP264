#include <stdio.h>
#include "R4.h"

void test_pointers1();
void test_pointers2();
void test_swap();
void test_reverse_array();
void test_swap4();
void test_find_max_min();

int main() {
	setbuf(stdout, NULL);
	test_pointers1();
	test_pointers2();
	test_swap();
	test_reverse_array();
	test_swap4();
	test_find_max_min();
	return 0;
}

void test_pointers1() {
	printf("------------------------------\n");
	printf("Start: Testing learn_pointers1:\n\n");

	learn_pointers1();
	printf("\n");

	printf("End: Testing learn_pointers1\n");
	printf("------------------------------\n\n");
	return;
}

void test_pointers2() {
	printf("------------------------------\n");
	printf("Start: Testing learn_pointers2:\n\n");

	learn_pointers2();
	printf("\n");

	printf("End: Testing learn_pointers2\n");
	printf("------------------------------\n\n");
	return;
}

void test_swap() {
	int n1, n2, *p1, *p2, **pp1, **pp2;
	printf("------------------------------\n");
	printf("Start: Testing swap functions:\n\n");

	n1 = 10;
	n2 = 20;
	printf("Case 1: swap1(n1,n2):\n");
	printf("Before swap: n1 = %d, n2 = %d\n", n1, n2);
	swap1(n1, n2);
	printf("After swap: n1 = %d, n2 = %d\n", n1, n2);
	printf("\n");

	p1 = &n1;
	p2 = &n2;
	printf("Case 2: swap2(p1,p2):\n");
	printf("Before swap: n1 = %d, n2 = %d\n", n1, n2);
	swap2(p1, p2);
	printf("After swap: n1 = %d, n2 = %d\n", n1, n2);
	printf("\n");

	printf("Case 3: swap2(&n1,&n2):\n");
	printf("Before swap: n1 = %d, n2 = %d\n", n1, n2);
	swap2(&n1, &n2);
	printf("After swap: n1 = %d, n2 = %d\n", n1, n2);
	printf("\n");

	printf("Case 4: swap3(&p1,&p2):\n");
	printf("Before swap: n1 = %d, n2 = %d\n", n1, n2);
	printf("Before swap: p1 = %p, p2 = %p\n", p1, p2);
	swap3(&p1, &p2);
	printf("After swap: n1 = %d, n2 = %d\n", n1, n2);
	printf("After swap: p1 = %p, p2 = %p\n", p1, p2);
	printf("\n");

	printf("Case 5: swap3(pp1,pp2):\n");
	pp1 = &p1;
	pp2 = &p2;
	printf("Before swap: n1 = %d, n2 = %d\n", n1, n2);
	printf("Before swap: p1 = %p, p2 = %p\n", p1, p2);
	swap3(pp1, pp2);
	printf("After swap: n1 = %d, n2 = %d\n", n1, n2);
	printf("After swap: p1 = %p, p2 = %p\n", p1, p2);
	printf("\n");

	printf("End: Testing swap\n");
	printf("------------------------------\n\n");

	return;
}

void test_reverse_array() {
	printf("------------------------------\n");
	printf("Start: Testing reverse_array:\n\n");

	int nums[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, *ptr = NULL;

	printf("reversing [1,2,3,4,5,6,7,8,9,10]\n");
	reverse_array(nums, MAX);
	printf("After reverse: [");
	for (int i = 0; i < MAX - 1; i++)
		printf("%d,", nums[i]);
	printf("%d]\n\n", nums[MAX - 1]);

	printf("reversing [10,9,8,7,6]\n");
	reverse_array(nums, 5);
	printf("After reverse: [");
	for (int i = 0; i < 4; i++)
		printf("%d,", nums[i]);
	printf("%d]\n\n", nums[4]);

	printf("Calling function on NULL pointer:\n");
	reverse_array(ptr, MAX);
	printf("\n");

	printf("Calling function on negative size:\n");
	reverse_array(nums, -5);
	printf("\n");

	printf("End: Testing swap\n");
	printf("------------------------------\n\n");
	return;
}

void test_swap4() {
	int n1 = 10, n2 = 20;
	char c1 = 'a', c2 = 'b';
	float f1 = 5.0, f2 = 6.0;
	double d1 = 5.0, d2 = 6.0;

	printf("------------------------------\n");
	printf("Start: Testing swap4:\n\n");

	printf("Case 1: int swap:\n");
	printf("Before swap: n1 = %d, n2 = %d\n", n1, n2);
	swap4(&n1, &n2, 'i');
	printf("After swap: n1 = %d, n2 = %d\n", n1, n2);
	printf("\n");

	printf("Case 2: char swap:\n");
	printf("Before swap: c1 = %c, c2 = %c\n", c1, c2);
	swap4(&c1, &c2, 'c');
	printf("After swap: c1 = %c, c2 = %c\n", c1, c2);
	printf("\n");

	printf("Case 3: float swap:\n");
	printf("Before swap: f1 = %.1f, f2 = %.1f\n", f1, f2);
	swap4(&f1, &f2, 'f');
	printf("After swap: f1 = %.1f, c2 = %.1f\n", f1, f2);
	printf("\n");

	printf("Case 4: double swap:\n");
	printf("Before swap: d1 = %.1lf, d2 = %.1lf\n", d1, d2);
	swap4(&d1, &d2, 'd');
	printf("\n");

	printf("End: Testing swap4\n");
	printf("------------------------------\n\n");
	return;
}

void test_find_max_min() {
	printf("------------------------------\n");
	printf("Start: Testing find_max_min:\n\n");

	int array[MAX] = { 40, 100, 30, 90, 20, 60, 10, 80, 50, 70 };
	int *ptr[2] = { NULL, NULL };
	printf("Array: [");
	for (int i = 0; i < MAX - 1; i++)
		printf("%d,", array[i]);
	printf("%d]\n", array[MAX - 1]);

	find_max_min(array, 10, ptr);
	printf("Max = %d at index = %d\n", *ptr[0], (ptr[0] - array));
	printf("Min = %d at index = %d\n", *ptr[1], (ptr[1] - array));
	printf("\n");

	printf("End: Testing find_max_min\n");
	printf("------------------------------\n\n");
	return;
}
