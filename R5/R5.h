#ifndef R5_H_
#define R5_H_

# define MAX 20
# define True 1
# define False 0

int* get_array1(int, int);
long* get_array2(long, long);

void print_array(int*, const int);
int indx(int*, const int, int);
void insert_item(int*, const int, int, int);
void remove_item(int*, const int, int);

void init_str();

void reverse_str1(char*);
void reverse_str2(char*);
char* reverse_str3(char*);
char* reverse_str4(char*);

void swap_str1(char*, char*);
void swap_str2(char**, char**);

int has_double(char*);
void plural_to_singular(char*);
#endif /* R5_H_ */
