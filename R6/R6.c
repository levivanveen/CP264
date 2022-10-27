/*
 * ---------------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student Email: vanv2490@mylaurier.ca
 * ---------------------------------
 */

# include<stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

void write_nums(const char *filename, int start, int end) {
	FILE *out_file = NULL;
	out_file = fopen(filename, "w");
	if (!out_file) {
		printf("Error(write_nums): Could not open file %s\n", filename);
		return;
	}
	for (int i = start; i <= end; i++) {
		fprintf(out_file, "%d\n", i);
	}
	fclose(out_file);
	return;
}

int read_nums(const char *filename, int *array) {
	FILE *in_file = NULL;
	in_file = fopen(filename, "r");

	if (!in_file) {
		printf("Error(read_nums): Could not open file %s\n", filename);
		return 0;
	}
	int temp, i = 0;
	fscanf(in_file, "%d", &temp);
	while (!feof(in_file)) {
		array[i++] = temp;
		fscanf(in_file, "%d", &temp);
	}

	fclose(in_file);
	return i - 1;
}

int extract_minutes(char *filename, unsigned int *minutes_array, const int size) {
	FILE *in_file = NULL;
	in_file = fopen(filename, "r");
	if (!in_file) {
		printf("Error(extract_minutes): Could not open file %s\n", filename);
		return -1;
	}
	char line[11], mm[3];
	mm[2] = '\0';
	char *dummy = NULL;
	int counter = 0;
	while (fgets(line, sizeof(line), in_file) != NULL && counter < size) {
		mm[0] = line[3];
		mm[1] = line[4];
		minutes_array[counter++] = (unsigned int) strtol(mm, &dummy, 10);
	}

	fclose(in_file);
	return counter;
}

void print_record_info1(char *record) {
	char *token = NULL, *results[5];
	int i = 0, length = 0;

	record++;
	token = strtok(record, "-");
	results[i++] = token;
	while (token) {
		token = strtok(NULL, "-");
		results[i++] = token;
	}
	length = strlen(results[4]);
	results[4][length - 1] = '\0';

	printf("Registration year = %s\n", results[0]);
	printf("Birthday = %s %s, %s\n", results[1], results[2], results[3]);
	printf("Name = %s\n", results[4]);

	return;
}

void print_record_info2(char *record) {
	int reg_year, day, year;
	char month[13], first[22], last[22];

	record++;
	sscanf(record, "%d %s %d %d %s %s", &reg_year, month, &day, &year, first,
			last);

	last[strlen(last - 1)] = '\0';
	printf("Registration year = %d\n", reg_year);
	printf("Birthday = %s %d, %d\n", month, day, year);
	printf("Name = %s %s\n", first, last);

	return;
}

void print_record_info3(char *record) {
	int reg_year, day, year;
	char month[13], first[22], last[22];
	char *buffer1 = NULL, *buffer2 = NULL, *buffer3 = NULL;

	buffer1 = strtok(record, ":"); //Dummy to get rid of record
	buffer1 = strtok(NULL, "-");
	sscanf(buffer1, "%d", &reg_year);

	buffer1 = strtok(NULL, "-"); //Fetching complete nirthday
	buffer3 = strtok(NULL, "-"); //Stores complete name

	buffer2 = strtok(buffer1, ",");
	strcpy(month, buffer2);
	buffer2 = strtok(NULL, ",");
	sscanf(buffer2, "%d", &day);
	buffer2 = strtok(NULL, ",");
	sscanf(buffer2, "%d", &year);

	sscanf(++buffer3, "%s %s", first, last);
	last[strlen(last) - 1] = '\0';

	printf("Registration year = %d\n", reg_year);
	printf("Birthday = %s %d, %d\n", month, day, year);
	printf("Name = %s %s\n", first, last);
	return;
}

void modify_grades(char *filename, int bonus) {
	FILE *in_file;
	in_file = fopen(filename, "r+");
	if (!in_file) {
		printf("Could not open file %s for reading\n", filename);
		return;
	}
	char record[20], *grade_str, *end_ptr;
	int grade, record_num = 0;

	while (fgets(record, 15, in_file) != NULL) {
		grade_str = strtok(record, ",");
		grade_str = strtok(NULL, "]");
		grade = (int) strtol(grade_str, &end_ptr, 10) + bonus;
		fseek(in_file, 11 + (14 * record_num), SEEK_SET);
		fprintf(in_file, "%d", grade);
		fseek(in_file, 1, SEEK_CUR); //Switching from writing to reading
		record_num++;
	}
	fclose(in_file);
	return;
}

int replace_char(char *filename, char letter1, char letter2) {
	FILE *in_file = NULL;
	in_file = fopen(filename, "r+");
	if (!in_file) {
		printf("Error(replace_char): Could not open file %s\n", filename);
		return -1;
	}
	if (!isalpha(letter1) || !isalpha(letter2)) {
		printf("Error(replace_char): Invalid input characters\n");
		fclose(in_file);
		return -1;
	}
	int counter = 0;

	char c = fgetc(in_file);
	while (c != EOF) {
		if (isalpha(c) && tolower(c) == tolower(letter1)) {
			fseek(in_file, -1, SEEK_CUR);
			fputc(letter2, in_file);
			counter++;
			fseek(in_file, 0, SEEK_CUR);
		}
		c = fgetc(in_file);
	}

	fclose(in_file);
	return counter;
}

