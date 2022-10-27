#ifndef LAB3_H_
#define LAB3_H_

#define True 1
#define False 0
#define SIZE 11
#define ERROR_CODE -99

void init(int);
int len();
void print();
void append(int);
void insert(int, int);
void reverse();

int list[SIZE];

void clear();
int indx(int);
void remove_item(int);
void del(int);
int pop(int pos);

#endif /* LAB3_H_ */
