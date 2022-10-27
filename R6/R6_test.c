#include "R6.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_write_nums();
void test_read_nums();
void test_extract_minutes();
void test_print_record();
void test_modify_grades();

//-------------------------------------
int main() {
	setbuf(stdout, NULL);
	test_write_nums();
	test_read_nums();
	test_extract_minutes();
	test_print_record();
	test_modify_grades();

	char str1[20], *dummy;
	long result;
	strcpy(str1, "16423");
	printf("%s", str1);
	result = strtol(str1, &dummy, 10);
	printf("%ld", result);

	return 0;
}

void test_write_nums() {
	printf("------------------------------\n");
	printf("Start: Testing write_nums:\n\n");

	const char *name = "nums.txt";
	write_nums(name, 5, 12);

	printf("check file %s for output\n", name);

	printf("End: Testing write_nums\n");
	printf("------------------------------\n\n");
	return;
}

void test_read_nums() {
	printf("------------------------------\n");
	printf("Start: Testing read_nums:\n\n");

	const char *filename = "nums.txt";

	int nums[MAX];
	int counter = read_nums(filename, nums);

	for (int i = 0; i < counter; i++) {
		if (i % 10 == 0 && i != 0)
			printf("\n");
		printf("%2d ", nums[i]);
	}
	printf("\n\nnumber of items = %d\n\n", counter);

	printf("End: Testing read_nums\n");
	printf("------------------------------\n\n");
	return;
}

void test_extract_minutes() {
	printf("------------------------------\n");
	printf("Start: Testing extract_minutes:\n\n");

	unsigned int minutes[MAX];
	char *filename = "time.txt";
	int count = extract_minutes(filename, minutes, MAX);
	for (int i = 0; i < count; i++)
		printf("Minutes of line %d = %u\n", (i + 1), minutes[i]);
	printf("\n");

	printf("End: Testing extract_minutes\n");
	printf("------------------------------\n\n");
	return;
}

void test_print_record() {
	printf("------------------------------\n");
	printf("Start: Testing print_record_info:\n\n");

	char record1[50];
	strcpy(record1, "[2018-June-14-1994-David Smith]");

	printf("Testing print_record_info1:\n");
	print_record_info1(record1);
	printf("\n");
	char *record2 = "[2018 June 14 1994 David Smith]";

	/*	printf("Testing print_record_info2:\n");
	 print_record_info2(record2);
	 printf("\n");

	 char record3[60];
	 strcpy(record3, "record:2018-June,14,1994-(David Smith)");
	 print_record_info3(record3);
	 printf("\n");
	 */
	printf("End: Testing print_record_info\n");
	printf("------------------------------\n\n");
	return;
}

void test_modify_grades() {
	printf("------------------------------\n");
	printf("Start: Testing modify_grades:\n\n");

	char *filename = "grades.txt";
	int bonus = 2;
	modify_grades(filename, bonus);

	printf("check file %s for output\n\n", filename);

	printf("End: Testing modify_grades\n");
	printf("------------------------------\n\n");
	return;
}

