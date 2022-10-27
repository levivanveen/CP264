#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "midterm.h"

void test_replace_most_freq(FILE *fptr);
void test_remove_nums(FILE *fptr);
void test_square_series(FILE *fptr);

void copy_file(const char *in_file, FILE *destination);
void copy_file2(const char *in_file, const char *out_file);
void wipe_files();
void print_doubles(double *array, const int size, FILE *fptr);
void print_floats(float *array, const int size, FILE *fptr);

int main() {
	setbuf(stdout, NULL);

	wipe_files();

	char out_file[] = "my_output.txt";
	FILE *destination = NULL;
	destination = fopen(out_file, "w");
	if (out_file == NULL) {
		printf("Error(main): Could not open file %s\n", out_file);
		return 0;
	}
	test_replace_most_freq(destination);
	test_remove_nums(destination);
	test_square_series(destination);

	fclose(destination);

	printf("See file: \"my_output.txt\"");
	return 0;
}

void test_replace_most_freq(FILE *fptr) {
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: replace_most_freq:\n\n");

	//create a copy of "ontario.txt" and "Quebec.txt" in order not to destroy original files
	char file1[] = "input1.txt", file2[] = "input2.txt";
	char file11[] = "input11.txt", file22[] = "input22.txt";
	copy_file2(file1, file11);
	copy_file2(file2, file22);

	fprintf(fptr, "*************\nAnalyzing file %s:\n", file11);
	replace_most_freq(file11, '*', fptr);
	copy_file(file11, fptr);
	fprintf(fptr, "\n");

	fprintf(fptr, "*************\nAnalyzing file %s:\n", file11);
	replace_most_freq(file22, '_', fptr);
	copy_file(file22, fptr);
	fprintf(fptr, "\n");

	fprintf(fptr, "*************\nAnalyzing file %s:\n", "nothing.txt");
	replace_most_freq("nothing.txt", '*', fptr);
	fprintf(fptr, "\n");

	fprintf(fptr, "End Testing: replace_most_freq\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}
void test_remove_nums(FILE *fptr) {
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: remove_nums:\n\n");

	double values[10] = { 9.35, 43.12, 17.283, 28.669, 5.313, 26.74, 18.01,
			6.97, 2.538, 9.45 };

	fprintf(fptr, "Case 1:\n");
	double *array1 = (double*) malloc(sizeof(double) * 10);
	for (int i = 0; i < 10; i++)
		array1[i] = values[i];
	fprintf(fptr, "input array = ");
	print_doubles(array1, 10, fptr);
	float *result = remove_nums(&array1, 10, 12.5, fptr);
	fprintf(fptr, "returned array = ");
	print_floats(result, 5, fptr);
	fprintf(fptr, "modified input array = ");
	print_doubles(array1, 5, fptr);
	fprintf(fptr, "\n");
	free(array1);
	array1 = NULL;
	free(result);
	result = NULL;

	fprintf(fptr, "Case 2:\n");
	double *array2 = (double*) malloc(sizeof(double) * 8);
	for (int i = 0; i < 8; i++)
		array2[i] = values[i];
	fprintf(fptr, "input array = ");
	print_doubles(array2, 8, fptr);
	float *result2 = remove_nums(&array2, 8, 9, fptr);
	fprintf(fptr, "returned array = ");
	print_floats(result2, 2, fptr);
	fprintf(fptr, "modified input array = ");
	print_doubles(array2, 6, fptr);
	fprintf(fptr, "\n");
	free(array2);
	array2 = NULL;
	free(result2);
	result2 = NULL;

	fprintf(fptr, "Case 3: Error cases:\n");
	double *array3 = (double*) malloc(sizeof(double) * 6);
	for (int i = 0; i < 6; i++)
		array3[i] = values[i];
	float *result3 = remove_nums(&array3, -1, 13.6, fptr);
	if (result3 == NULL)
		fprintf(fptr, "result = NULL\n");
	result3 = remove_nums(NULL, 5, 13.6, fptr);
	if (result3 == NULL)
		fprintf(fptr, "result = NULL\n");
	result3 = remove_nums(&array2, 5, 13.6, fptr);
	if (result3 == NULL)
		fprintf(fptr, "result = NULL\n");

	fprintf(fptr, "\nEnd Testing: remove_nums\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}

void test_square_series(FILE *fptr) {
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: format_square_series:\n\n");

	fprintf(fptr, "Case 1:\n");
	double *p = NULL;
	double *series = square_series(4.0, 0.12, &p, fptr);
	if (p != NULL) {
		fprintf(fptr, "Breaking point is at: %.4lf\n", *p);
		fprintf(fptr, "previous value = %.4lf\n", *(p - 1));
		fprintf(fptr, "first item in the series = %.4lf\n", series[0]);
	}
	fprintf(fptr, "\n");
	free(series);
	series = NULL;

	fprintf(fptr, "Case 2:\n");
	p = NULL;
	series = square_series(6.156, 0.3600, &p, fptr);
	if (p != NULL) {
		fprintf(fptr, "Breaking point is at: %.4lf\n", *p);
		fprintf(fptr, "previous value = %.4lf\n", *(p - 1));
		fprintf(fptr, "first item in the series = %.4lf\n", series[0]);
	}
	fprintf(fptr, "\n");
	free(series);
	series = NULL;

	fprintf(fptr, "Case 3:\n");
	p = NULL;
	series = square_series(8.0, 0.36, &p, fptr);
	if (p != NULL) {
		fprintf(fptr, "Breaking point is at: %.4lf\n", *p);
		fprintf(fptr, "first item in the series = %.4lf\n", series[0]);
	}
	fprintf(fptr, "\n");
	free(series);
	series = NULL;

	fprintf(fptr, "Case 4:\n");
	p = NULL;
	series = square_series(-1.0, 0.36, &p, fptr);
	if (series == NULL)
		fprintf(fptr, "first item in the series = NULL\n");

	series = square_series(3, 0.41, NULL, fptr);
	if (series == NULL)
		fprintf(fptr, "first item in the series = NULL\n");
	fprintf(fptr, "\n");

	fprintf(fptr, "End Testing: format_square_series\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}

//------------- utility functions --------------------
void copy_file(const char *in_file, FILE *destination) {
	FILE *source = NULL;
	source = fopen(in_file, "r");
	if (source == NULL) {
		printf("Error(copy_file): Could not open file %s\n", in_file);
		return;
	}
	char character = fgetc(source);
	while (character != EOF) {
		fprintf(destination, "%c", character);
		character = fgetc(source);
	}
	fclose(source);
	return;
}

void copy_file2(const char *in_file, const char *out_file) {
	FILE *source = NULL, *destination = NULL;
	source = fopen(in_file, "r");
	if (source == NULL) {
		printf("Error(copy_file2): Could not open file %s\n", in_file);
		return;
	}

	destination = fopen(out_file, "w");
	if (destination == NULL) {
		printf("Error (copy_file2): Could not open file %s\n", out_file);
		return;
	}

	char line[MAX];
	while (fgets(line, sizeof(line), source) != NULL)
		fprintf(destination, "%s", line);

	fclose(source);
	fclose(destination);
	return;
}
void wipe_files() {
	char filename[3][30] = { "my_output.txt", "input11.txt", "input22.txt" };
	FILE *fptr = NULL;
	for (int i = 0; i < 3; i++) {
		fptr = fopen(filename[i], "w");
		if (fptr == NULL) {
			printf("Error(wipe_files): Could not open file %s\n", filename[i]);
			return;
		}
		fclose(fptr);
		fptr = NULL;
	}
	return;
}

void print_floats(float *array, const int size, FILE *fptr) {
	int i;
	fprintf(fptr, "[ ");
	for (i = 0; i < size - 1; i++)
		fprintf(fptr, "%.2f , ", array[i]);
	fprintf(fptr, "%.2f ]\n", array[i]);
	return;
}

void print_doubles(double *array, const int size, FILE *fptr) {
	if (array == NULL) {
		printf("Error(print_doubles): invalid array\n");
		return;
	}
	int i;
	fprintf(fptr, "[ ");
	for (i = 0; i < size - 1; i++)
		fprintf(fptr, "%.2lf , ", array[i]);
	fprintf(fptr, "%.2lf ]\n", array[i]);
	return;
}
