#ifndef R6_H_
#define R6_H_

# include <stdio.h>
# define MAX 100

void write_nums(const char *filename, int start, int end);
int read_nums(const char *filename, int *array);
int extract_minutes(char *filename, unsigned int *minutes_array, const int size);
void modify_grades(char *filename, int bonus);

void print_record_info1(char *record);
void print_record_info2(char *record);
void print_record_info3(char *record);

#endif /* R6_H_ */
