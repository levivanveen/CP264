# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include "data_structures.h"

//------------------- Data --------------------
Data* create_data(int value) {
	Data *d = (Data*) malloc(sizeof(Data));
	*d = value;
	return d;
}

void destroy_data(Data **d) {
	assert(d && *d);
	//free(*d);
	*d = NULL;
	return;
}

void print_data(Data *d) {
	assert(d);
	printf("%d", (int) *d);
	return;
}

void print_data_array(Data *array, const int size) {
	assert(array);
	assert(size >= 1);

	int i;
	printf("[");
	for (i = 0; i < size; i++) {
		printf("%d", array[i]);
		if (i != size - 1)
			printf(",");
	}
	printf("]\n");
	return;
}

Data* copy_data(Data *d1) {
	assert(d1);
	int *d2 = (int*) malloc(sizeof(int));
	d2 = d1;
	return d2;
}

void swap_data(Data *d1, Data *d2) {
	assert(d1 && d2);
	Data temp = *d1;
	*d1 = *d2;
	*d2 = temp;
	return;
}

int compare_data(Data *d1, Data *d2) {
	assert(d1 && d2);
	if (*d1 > *d2)
		return 1;
	if (*d1 < *d2)
		return 2;
	return 0;
}
//------------- Stack ---------------
Stack* create_stack(int stack_capacity) {
	Stack *s = (Stack*) malloc(sizeof(Stack));
	if (stack_capacity < 1) {
		printf("Error(create_stack): invalid capacity, set to 10\n");
		stack_capacity = 10;
	}
	s->capacity = stack_capacity;
	s->array = (Data*) malloc(sizeof(Data) * (s->capacity));
	s->top = -1;
	return s;
}

void destroy_stack(Stack **s) {
	assert(s!= NULL);
	while (!is_empty_stack(*s)) {
		Data *d = pop_stack(*s);
		destroy_data(&d);
	}
	free((*s)->array);
	(*s)->array = NULL;
	(*s)->capacity = 0;
	(*s)->top = 0;
	free(*s);
	*s = NULL;
	return;
}

int is_empty_stack(Stack *s) {
	assert(s!=NULL);
	return (s->top == -1);
}

int is_full_stack(Stack *s) {
	assert(s!=NULL);
	return (s->top == s->capacity - 1);
}

int len_stack(Stack *s) {
	assert(s!=NULL);
	return s->top + 1;
}

void print_stack(Stack *s) {
	assert(s!=NULL);
	printf("Stack Size = %d ", len_stack(s));
	if (is_empty_stack(s))
		printf("<emtpy_stack>\n");
	printf("<");
	for (int i = s->top; i >= 0; i--) {
		print_data(&s->array[i]);
		if (i != 0)
			printf("-");
		else
			printf(">\n");
	}
	return;
}

int push_stack(Stack *s, Data *d) {
	assert(s!=NULL && d!=NULL);
	if (is_full_stack(s)) {
		printf("Error(push_stack): stack is full\n");
		return False;
	}
	s->top++;
	s->array[s->top] = *copy_data(d);
	return True;
}

Data* peek_stack(Stack *s) {
	assert(s!=NULL);
	if (is_empty_stack(s)) {
		printf("Error(peek_stack): stack is empty\n");
		return NULL;
	}
	return copy_data(&(s->array[s->top]));
}

Data* pop_stack(Stack *s) {
	assert(s!=NULL);
	Data *d = NULL;
	if (is_empty_stack(s)) {
		printf("Error(pop_stack): stack is empty\n");
		return d;
	}

	d = copy_data(&s->array[s->top]);
	if (s->top != 0) {
		Data *temp = &s->array[s->top];
		destroy_data(&temp);
	}
	s->top--;
	return d;
}

int get_capacity_stack(Stack *s) {
	assert(s!=NULL);
	return s->capacity;
}

//------------- Process ----------------------
Process* create_process(long pid, int p_time, int arrival_time) {
	Process *p = (Process*) malloc(sizeof(Process));

	//set process time
	if (p_time <= 0) {
		fprintf(stderr, "Error(create_process): invalid time - set to 0\n");
		p->time = 0;
	} else
		p->time = p_time;

	//set arrival time
	if (arrival_time < 0) {
		fprintf(stderr,
				"Error(create_process): invalid arrival time - set to 0\n");
		p->arrival = 0;
	} else
		p->arrival = arrival_time;

	//set PID
	if (pid <= 0) {
		fprintf(stderr, "Error(create_process): invalid pid - set to random\n");
		p->PID = get_UPID();
	} else
		p->PID = pid;

	return p;
}

void destroy_process(Process **p) {
	assert(*p != NULL);
	(*p)->PID = 0;
	(*p)->time = 0;
	(*p)->arrival = 0;
	//free(*p);
	*p = NULL;
	return;
}

unsigned long get_UPID() {
	//Note: MAX for unsigned long is 4294967295

	static int counter = 100000;

	//Get higher 5 digits
	//random number between 10000 to 39999
	unsigned long higher5 = rand() % (39999 - 10000 + 1) + 10000;
	higher5 = higher5 * 100000;

	//Get lower 5 digits
	//sequential number between 10000 to 99999
	int lower5 = counter;
	counter++;

	return higher5 + lower5;
}

Process* copy_process(Process *p1) {
	assert(p1!=NULL);
	Process *p2 = (Process*) malloc(sizeof(Process));
	p2->PID = p1->PID;
	p2->time = p1->time;
	p2->arrival = p1->arrival;
	return p2;
}

void get_process_info(Process *p, char *info) {
	assert(p!=NULL);
	char process[30] = "";
	sprintf(process, "[%u](%lu,%u)", p->arrival, p->PID, p->time);
	strcpy(info, process);
	return;
}

void print_process(Process *p) {
	assert(p!=NULL);
	char info[30];
	strcpy(info, "");
	get_process_info(p, info);
	printf("%s", info);
	return;
}

//--------------- Node --------------
Node* create_node(Data *d, Node *n) {
	assert(d);
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = copy_data(d);
	node->next = n;
	return node;
}

void print_node(Node *n) {
	assert(n);
	print_data(n->data);
	return;
}

Node* copy_node(Node *n) {
	assert(n);
	return create_node(n->data, n->next);
}

void destroy_node(Node **n) {
	assert(n && *n);
	destroy_data(&(*n)->data);
	(*n)->data = NULL;
	(*n)->next = NULL;
	free(*n);
	return;
}

//---------------- Linked List --------------
List* create_list() {
	List *list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->size = 0;
	return list;
}

int is_empty_list(List *list) {
	assert(list);
	return (list->head == NULL);
}

void print_list(List *list) {
	assert(list);
	Node *current_node = list->head;
	while (current_node != NULL) {
		print_node(current_node);
		printf("-->");
		current_node = current_node->next;
	}
	printf("NULL\n");
	return;
}

void append_list(List *list, Data *d) {
	assert(list && d);
	Node *new_node = create_node(d, NULL);
	if (is_empty_list(list))
		list->head = new_node;
	else {
		Node *current_node = list->head;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	list->size++;
	return;
}

Data* get_data_list(List *list, int index) {
	assert(list);
	return get_node_list(list, index)->data;
}

Node* get_node_list(List *list, int index) {
	assert(list!=NULL);
	Node *n = NULL;
	if (index < 0 || index >= list->size) {
		printf("Error(get_node_list): index out of range\n");
		return n;
	}
	Node *current_node = list->head;
	int i = 0;
	while (i < index) {
		current_node = current_node->next;
		i++;
	}
	return copy_node(current_node);
}

void destroy_list(List **list) {
	//while (!is_empty_list(*list))
	//	pop_list(*list, 0);
	(*list)->head = NULL;
	(*list)->size = 0;
	//free(*list);
	return;
}

