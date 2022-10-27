/*
 * ---------------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student Email: vanv2490@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void count_letters(const char *filename, int counters[26]);
void write_results(const char *filename, int counters[26]);
void append_sum(const char *filename, int counters[26]);

int main() {
	setbuf(stdout, NULL);

	char filename[20] = "text1.txt";
	int counters[26] = { 0 };

	count_letters(filename, counters);

	filename[4] = '2';
	write_results(filename, counters);

	append_sum(filename, counters);

	printf("Check text2.txt for output\n");

	return 0;
}

void count_letters(const char *filename, int counters[26]) {
	FILE *in_file = NULL;
	in_file = fopen(filename, "r");
	if (!in_file) {
		printf("Error(count_letters): Could not open file %s\n", filename);
		return;
	}
	int charRead, index;
	char letter;

	charRead = fscanf(in_file, "%c", &letter);

	while (!feof(in_file)) {
		if (charRead == 1) {
			if (islower(letter)) {
				index = letter - 97;
				counters[index]++;
			} else if (isupper(letter)) {
				index = letter - 65;
				counters[index]++;
			}
			charRead = fscanf(in_file, "%c", &letter);
		}
	}
	fclose(in_file);
	return;
}

void write_results(const char *filename, int counters[26]) {
	FILE *out_file = NULL;
	out_file = fopen(filename, "w");

	if (!out_file) {
		printf("Error(count_letters): Could not open file %s\n", filename);
		return;
	}
	char letter = 'a';

	for (int i = 0; i < 26; i++) {
		fprintf(out_file, "count(%c) = %d\n", letter++, counters[i]);
	}

	fclose(out_file);
	return;

}

void append_sum(const char *filename, int counters[26]) {
	FILE *out_file = NULL;
	out_file = fopen(filename, "a+");

	if (!out_file) {
		printf("Error(count_letters): Could not open file %s\n", filename);
		return;
	}
	int counter = 0;

	for (int i = 0; i < 26; i++) {
		counter = counter + counters[i];
	}
	fprintf(out_file, "Total = %d\n", counter);

	fclose(out_file);
	return;
}

