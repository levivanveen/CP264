#ifndef DATA_STRUCTURES_H_
#define DATA_STRUCTURES_H_

# define True 1
# define False 0
# define COUNT 5

//--------------------- Data --------------------------
typedef int Data;

Data* create_data(int value);
void print_data(Data *d);
Data* copy_data(Data *d);
int compare_data(Data *d1, Data *d2);
void destroy_data(Data**);

//------------------- LinkedList ------------------
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
int is_empty_list(List *list);
void print_list(List *list);
void append_list(List *list, Data *d);
Data* get_data_list(List *list, int index);
Node* get_node_list(List *list, int index);
void destroy_list(List **list);
Data* pop_list(List *list, int index);
//------------------- Stack -----------------------
typedef struct {
	Data *array; 	//stack array
	int top; 		//index for top of stack
	int capacity;	//maximum capacity of stack
} Stack;

Stack* create_stack(int stack_capacity);
void destroy_stack(Stack **s);
void print_stack(Stack *s);
Data* pop_stack(Stack *s);
int push_stack(Stack *s, Data *d);
Data* peek_stack(Stack *s);
int is_empty_stack(Stack *s);
int is_full_stack(Stack *s);
int len_stack(Stack *s);

//----------------- Process ------------------
typedef struct {
	unsigned long PID; 	//process id
	unsigned int time;	//requested processing time
	unsigned int arrival; //arrival time
} Process;

Process* create_process(long p_pid, int p_time, int arrival_time);
void destroy_process(Process **p);
void print_process(Process *p);
Process* copy_process(Process *p);
void get_process_info(Process *p, char *info);
unsigned long get_UPID();

#endif /* DATA_STRUCTURES_H_ */
