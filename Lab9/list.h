#ifndef LIST_H_
#define LIST_H_

# include "data.h"

# define True 1
# define False 0

# include "data.h"

typedef struct linkedListNode {
	Data *data; 					//data item
	struct linkedListNode *next; 	//Pointer to next node
} Node;

Node* create_node(Data *d, Node *n);
void destroy_node(Node **n);
void print_node(Node *n);
Node* copy_node(Node *n);

typedef struct {
	Node *head;
	int size;
} List;

//basic functions
List* create_list();
void destroy_list(List **list);
void print_list(List *list);
int is_empty_list(List *list);

//Getters
Data* ge_data_list(List *list, int index);
Node* get_node_list(List *list, int index);
Data* peek_list(List *list);
List* copy_list(List *list);
List* sub_list(List *list, int start, int end);

//Setters
void append_list(List *list, Data *d);
void insert_front_list(List *list, Data *d);

//statistics functions
Data* min_list(List *list);

//Remove Functions
Data* remove_rear_list(List *list);
Data* remove_front_list(List *list);
void cut_list(List *list, int start, int end);

//Conversion functions
List* array_to_list(Data *array, const int size);

//Ordering functions
void reverse_list(List *list);

#endif /* LIST_H_ */
