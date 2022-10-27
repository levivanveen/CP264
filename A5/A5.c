/*
 * ---------------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student Email: vanv2490@mylaurier.ca
 * ---------------------------------
 */
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "A5.h"

//---------------------- Task 1 ---------------------------------
void get_file_stats(const char *filename, const char *filename2) {
	FILE *in_file = NULL;
	FILE *out_file = NULL;

	out_file = fopen(filename2, "a");

	if (!out_file) {
		printf("Error(get_file_stats): Could not open file %s", filename2);
		return;
	}

	in_file = fopen(filename, "r");

	if (!in_file) {
		fprintf(out_file, "Error(get_file_stats): Could not open file %s\n",
				filename);
		fclose(out_file);
		return;
	}

	int paras = 0, lines = 0, words = 0, whites = 0, chars = 0, uppers = 0,
			lowers = 0, others = 0;
	char c = fgetc(in_file);
	char str[MAX];

	while (c != EOF) {
		if (c == '\n') {
			lines++;
		} else if (isspace(c)) {
			whites++;
		} else {
			chars++;
			if (isupper(c))
				uppers++;
			else if (islower(c))
				lowers++;
			else
				others++;
		}
		c = fgetc(in_file);
	}

	fseek(in_file, 0, SEEK_SET);

	while (fgets(str, sizeof(str), in_file) != NULL) {
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == ' ' && str[i + 1] != ' ') {
				words++;
			} else if (i > 1 && str[i] == '\n' && str[i + 1] == '\0') {
				words++;
			}
			if (i < 3 && str[i] == '\n')
				paras++;
		}
	}
	paras++;

	fprintf(out_file, "Analyzing file %s:\n", filename);
	fprintf(out_file, "#Paragraphs = %d\n", paras);
	fprintf(out_file, "#lines = %d\n", lines);
	fprintf(out_file, "#words = %d\n", words);
	fprintf(out_file, "#characters = %d\n", chars);
	fprintf(out_file, "	#uppers = %d\n", uppers);
	fprintf(out_file, "	#lowers = %d\n", lowers);
	fprintf(out_file, "	#others = %d\n", others);
	fprintf(out_file, "#spaces = %d\n", whites);
	fprintf(out_file, "\n");

	fclose(in_file);
	fclose(out_file);
	return;
}

//---------------------- Task 2 ---------------------------------
void format_file1(const char *in_file, const char *out_file) {
	FILE *input = NULL;
	FILE *output = NULL;

	output = fopen(out_file, "w");

	if (!output) {
		printf("Error(format_file1): Could not open file %s", out_file);
		return;
	}

	input = fopen(in_file, "r");

	if (!input) {
		fprintf(output, "Error(format_file1): Could not open file %s\n",
				in_file);
		fclose(output);
		return;
	}
	char line[MAX];

	while (fgets(line, sizeof(line), input) != NULL) {
		int temp = strlen(line);
		if (temp <= 2)
			continue;
		else {
			if (line[temp - 3] == '.') {
				fprintf(output, "%s", line);
				continue;
			} else {
				line[temp - 2] = '\0';
				fprintf(output, "%s", line);
				fprintf(output, " ");
			}
		}
	}
	fclose(input);
	fclose(output);
	return;
}

//---------------------- Task 3 ---------------------------------
void format_file2(const char *in_file, const char *out_file) {
	FILE *input = NULL;
	FILE *output = NULL;

	output = fopen(out_file, "w");

	if (!output) {
		printf("Error(format_file2): Could not open file %s", out_file);
		return;
	}
	input = fopen(in_file, "r");

	if (!input) {
		fprintf(output, "Error(format_file2): Could not open file %s\n",
				in_file);
		fclose(output);
		return;
	}
	int num_line = 1, new_ln = False;
	char c = fgetc(input);

	fprintf(output, "%d ", num_line);

	while (c != EOF) {
		if (c == '\n')
			new_ln = True;
		if (isalpha(c) || isspace(c))
			fprintf(output, "%c", c);
		c = fgetc(input);
		if (c != EOF && new_ln == True)
			fprintf(output, "%d ", ++num_line);
		new_ln = False;
	}
	return;
}

//---------------------- Task 4 ---------------------------------
void filter_by_area(const char *in_file, const char *out_file,
		float area_threshold) {
	FILE *input = NULL;
	FILE *output = NULL;

	output = fopen(out_file, "a");

	if (!output) {
		printf("Error(filter_by_area): Could not open file %s", out_file);
		return;
	}
	input = fopen(in_file, "r");

	if (!input) {
		fprintf(output, "Error(filter_by_area): Could not open file %s\n",
				in_file);
		fclose(output);
		return;
	}
	fprintf(output, "Cities with area >= %.2f:\n", area_threshold);

	char line[MAX];
	char *ptr;
	char *name;
	int area, found = 0;

	while (fgets(line, sizeof(line), input) != NULL) {
		char *word = strtok(line, " ");
		int counter = 1;
		while (counter < 10) {
			word = strtok(NULL, " ");
			counter++;
			if (counter == 3)
				name = word;
			if (counter == 10) {
				area = (int) strtol(word, &ptr, 10);
				if (area >= area_threshold) {
					fprintf(output, "%s = %d\n", name, area);
					found++;
				}
			}
		}
	}
	if (found == 0) {
		fprintf(output, "No cities were found\n");
	}
	fprintf(output, "\n");
	return;
}

//---------------------- Task 5 ---------------------------------
void replace_two_chars(const char *filename, char *str1, char *str2) {
	FILE *in_file = NULL;
	in_file = fopen(filename, "r+");

	if (!in_file) {
		printf("Error(replace_two_chars): Could not open file %s\n", filename);
		return;
	}
	char c = fgetc(in_file);
	char prev;

	while (c != EOF) {
		if (prev == str1[0] && c == str1[1]) {
			fseek(in_file, -2, SEEK_CUR);
			fputc(str2[0], in_file);
			fputc(str2[1], in_file);
			fseek(in_file, 0, SEEK_CUR);
		}
		prev = c;
		c = fgetc(in_file);
	}

	return;
}

