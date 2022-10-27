#ifndef MIDTERM_H_
#define MIDTERM_H_

# define MAX 200

void replace_most_freq(const char *filename, char c, FILE* destination);
float* remove_nums(double** array, const int size, int value, FILE* destination);
double* square_series(double a, double break_value, double** break_ptr, FILE *fptr);

#endif /* MIDTERM_H_ */
