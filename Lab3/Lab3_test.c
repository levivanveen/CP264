#include <stdio.h>
#include "Lab3.h"

void test_clear();
void test_indx();
void test_remove_item();
void test_del();
void test_pop();

int main() {
	setbuf(stdout, NULL);
	test_clear();
	test_indx();
	test_remove_item();
	test_del();
	test_pop();
	return 0;
}

void test_clear() {
	printf("Start: Testing clear\n\n");
	printf("Case 1:");
	init(1);
	print();
	printf("After clear: ");
	clear();
	print();
	printf("\n");

	printf("Case 2:");
	init(10);
	print();
	printf("After clear: ");
	clear();
	print();
	printf("\n");

	printf("End: Testing clear\n");
	printf("------------------------------\n");
	return;
}

void test_indx() {
	printf("Start: Testing indx\n\n");
	clear();

	printf("Case 1:");
	init(1);
	print();
	printf("indx(0) =  %d\n", indx(0));
	printf("indx(1) =  %d\n", indx(1));
	printf("\n");

	printf("Case 2:");
	init(10);
	print();
	printf("indx(5) =  %d\n", indx(5));
	printf("indx(9) =  %d\n", indx(9));
	printf("indx(10) =  %d\n", indx(10));
	printf("\n");

	printf("End: Testing indx\n");
	printf("------------------------------\n");
	return;
}

void test_remove_item() {
	printf("Start: Testing remove_item\n\n");
	clear();

	printf("Case 1:");
	init(1);
	print();
	printf("remove_item(0) = ");
	remove_item(0);
	print();
	printf("remove_item(1) = ");
	remove_item(1);
	print();
	printf("\n");

	printf("Case 2:");
	init(10);
	print();
	printf("remove_item(6) = ");
	remove_item(6);
	print();
	printf("remove_item(9) = ");
	remove_item(9);
	print();
	printf("remove_item(0) = ");
	remove_item(0);
	print();
	printf("remove_item(9) = ");
	remove_item(9);
	print();
	printf("\n");

	printf("End: Testing remove_item\n");
	printf("------------------------------\n");
	return;
}

void test_del() {
	printf("Start: Testing del\n\n");
	clear();

	printf("Case 1:");
	list[0] = 10;
	print();
	printf("del(0) = ");
	del(0);
	print();
	printf("del(1) = ");
	del(1);
	print();
	printf("\n");

	printf("Case 2:");
	for (int i = 0; i < 10; i++)
		list[i] = (i + 1) * 10;
	print();
	printf("del(6) = ");
	del(6);
	print();
	printf("del(8) = ");
	del(8);
	print();
	printf("del(0) = ");
	del(0);
	print();
	printf("del(9) = ");
	del(9);
	print();
	printf("\n");

	printf("End: Testing del\n");
	printf("------------------------------\n");
	return;
}

void test_pop() {
	int value;

	printf("Start: Testing pop\n\n");
	clear();

	printf("Case 1:");
	list[0] = 10;
	print();
	printf("pop(0) = ");
	value = pop(0);
	print();
	printf("popped value = %d\n", value);
	printf("pop(1) = ");
	value = pop(1);
	print();
	printf("popped value = %d\n", value);
	printf("\n");

	printf("Case 2:");
	for (int i = 0; i < 10; i++)
		list[i] = (i + 1) * 10;
	printf("pop(6) = ");
	value = pop(6);
	print();
	printf("popped value = %d\n", value);
	printf("pop(8) = ");
	value = pop(8);
	print();
	printf("popped value = %d\n", value);
	printf("pop(0) = ");
	value = pop(0);
	print();
	printf("popped value = %d\n", value);
	printf("pop(9) = ");
	value = pop(9);
	print();
	printf("popped value = %d\n", value);
	printf("\n");

	printf("End: Testing pop\n");
	printf("------------------------------\n");
	return;
}
