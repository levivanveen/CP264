#include "R5.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_get_array();
void test_insert_remove();
void test_init_str();
void test_reverse_str();
void test_swap_str();
void test_has_double();
void test_plural_to_singular();

int main() {
	setbuf(stdout, NULL);
	test_get_array();
	test_insert_remove();
	test_init_str();
	test_reverse_str();
	test_swap_str();
	test_has_double();
	test_plural_to_singular();
	return 0;
}

void test_get_array() {
	printf("------------------------------\n");
	printf("Start: Testing get_array:\n\n");

	int *array = NULL, start = 10, end = 20;
	printf("Testing malloc:\n");
	array = get_array1(start, end);
	printf("array[0] = %d and array[%d] = %d\n", array[0], end - start,
			array[end - start]);
	//printf("Printing value outside array = %d\n", array[end - start + 1]);
	free(array);
	array = NULL;
	printf("\n");

	printf("Testing calloc:\n");
	start = 13;
	end = 28;
	long *array2 = NULL;
	array2 = get_array2((long) start, (long) end);
	printf("array[0] = %ld and array[%d] = %ld\n", array2[0], end - start,
			array2[end - start]);
	printf("Printing value outside array = %ld\n", array2[end - start + 1]);
	free(array2);
	array2 = NULL;
	printf("\n");

	printf("End: Testing get_array\n");
	printf("------------------------------\n\n");
	return;
}

void test_insert_remove() {
	printf("------------------------------\n");
	printf("Start: Testing insert/remove:\n\n");

	int i, size = 10;
	int *array = (int*) malloc(sizeof(int) * size);
	for (i = 0; i < 10; i++)
		array[i] = i;
	printf("Before insert/remove\n");
	print_array(array, size);
	printf("After inserting 100 at position 3:\n");
	insert_item(array, size, 100, 3);
	size++;
	print_array(array, size);
	printf("After deleting value 8:\n");
	remove_item(array, size, 8);
	size--;
	print_array(array, size);
	printf("\n");

	printf("End: Testing insert/remove\n");
	printf("------------------------------\n\n");
	return;
}

void test_init_str() {
	printf("------------------------------\n");
	printf("Start: Testing init_str:\n\n");

	init_str();

	printf("\n");
	printf("End: Testing init_str\n");
	printf("------------------------------\n\n");
	return;
}

void test_reverse_str() {
	printf("------------------------------\n");
	printf("Start: Testing reverse_str:\n\n");

	char s1[MAX], *s2;

	printf("Method 1:\n");
	strcpy(s1, "abcdefg");
	printf("Before: %s\n", s1);
	reverse_str1(s1);
	printf("After: %s\n", s1);
	strcpy(s1, "Good morning");
	printf("Before: %s\n", s1);
	reverse_str1(s1);
	printf("After: %s\n", s1);
	strcpy(s1, "");
	printf("Before: %s\n", s1);
	reverse_str1(s1);
	printf("After: %s\n", s1);
	printf("\n");

	printf("Method 2:\n");
	strcpy(s1, "abcdefg");
	printf("Before: %s\n", s1);
	reverse_str2(s1);
	printf("After: %s\n", s1);
	strcpy(s1, "Good morning");
	printf("Before: %s\n", s1);
	reverse_str2(s1);
	printf("After: %s\n", s1);
	strcpy(s1, "");
	printf("Before: %s\n", s1);
	reverse_str2(s1);
	printf("After: %s\n", s1);
	printf("\n");

	printf("Method 3:\n");
	strcpy(s1, "abcdefg");
	printf("Before: %s\n", s1);
	s2 = reverse_str3(s1);
	printf("After: original = %s, new = %s\n", s1, s2);
	strcpy(s1, "Good morning");
	printf("Before: %s\n", s1);
	s2 = reverse_str3(s1);
	printf("After: original = %s, new = %s\n", s1, s2);
	strcpy(s1, "");
	printf("Before: %s\n", s1);
	s2 = reverse_str3(s1);
	printf("After: original = %s, new = %s\n", s1, s2);
	printf("\n");

	printf("Method 4:\n");
	char *s3;
	strcpy(s1, "abcdefg");
	printf("Before: %s\n", s1);
	s3 = reverse_str4(s1);
	printf("After: original = %s, new = %s\n", s1, s3);
	strcpy(s1, "Good morning");
	printf("Before: %s\n", s1);
	s3 = reverse_str4(s1);
	printf("After: original = %s, new = %s\n", s1, s3);
	strcpy(s1, "");
	printf("Before: %s\n", s1);
	s3 = reverse_str4(s1);
	printf("After: original = %s, new = %s\n", s1, s3);
	printf("\n");
	free(s3);

	printf("End: Testing reverse_str\n");
	printf("------------------------------\n\n");
	return;
}

void test_swap_str() {
	printf("------------------------------\n");
	printf("Start: Testing swap_str:\n\n");

	char s1[] = "Day", s2[] = "Night";
	printf("Method 1:\n");
	printf("Before swap: s1 = %s , s2 = %s\n", s1, s2);
	swap_str1(s1, s2);
	printf("After swap: s1 = %s , s2 = %s\n", s1, s2);
	printf("\n");

	char *s3 = "Day", *s4 = "Night";
	printf("Method 2:\n");
	printf("Before swap: s1 = %s , s2 = %s\n", s3, s4);
	swap_str2(&s3, &s4);
	printf("After swap: s1 = %s , s2 = %s\n", s3, s4);
	printf("\n");

	printf("End: Testing swap_str\n");
	printf("------------------------------\n\n");
	return;
}

void test_has_double() {
	printf("------------------------------\n");
	printf("Start: Testing has_double:\n\n");

	printf("has_double(\"\") = %d\n", has_double(""));
	printf("has_double(\"cat\") = %d\n", has_double("cat"));
	printf("has_double(\"seed\") = %d\n", has_double("seed"));
	printf("has_double(\"responsible\") = %d\n", has_double("responsible"));
	printf("has_double(\"$a$\") = %d\n", has_double("$a$"));
	printf("has_double(\"roar\") = %d\n", has_double("roar"));
	printf("has_double(\"Clock\") = %d\n", has_double("Clock"));
	printf("\n");

	printf("End: Testing has_double\n");
	printf("------------------------------\n\n");
	return;
}
void test_plural_to_singular() {
	printf("------------------------------\n");
	printf("Start: Testing plural to singular:\n\n");

	char word[] = "books";
	char *word1 = (char*) malloc(sizeof(char) * (strlen(word) + 1));
	strcpy(word1, word);
	printf("Plural = %s\n", word1);
	plural_to_singular(word1);
	printf("Singular = %s\n", word1);
	free(word1);
	word1 = NULL;

	char word0[] = "Strawberries";
	word1 = (char*) malloc(sizeof(char) * (strlen(word0) + 1));
	strcpy(word1, word0);
	printf("Plural = %s\n", word1);
	plural_to_singular(word1);
	printf("Singular = %s\n", word1);
	free(word1);
	word1 = NULL;

	printf("End: Testing plural to singular\n");
	printf("------------------------------\n\n");
	return;
}

