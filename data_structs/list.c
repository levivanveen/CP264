/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "list.h"

List* intersection_aux(Node *node1, List *list2, List **list3);
int empty_list(List *list);
int linear_search(List *list, Data item);

/**
 * ------------------------------------------------------------
 * Parameters: 	d - a data item (Data*)
 * 				n - pointer to next node (Node*)
 * Returns: 	new node (Node*)
 * Description:	Creates a new node using the given data
 * Asserts:		data is not NULL
 * ------------------------------------------------------------
 */
Node* create_node(Data *d, Node *n) {
	assert(d);
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = copy_data(d);
	node->next = n;
	return node;
}

/**
 * -------------------------------------------------------
 * Parameters: 	a node (Node*)
 * Returns: 	none
 * Description:	prints the contents of a node
 * 				invokes print_data
 * 				does not print next pointer
 * Assert:		n is not NULL
 * -------------------------------------------------------
 */
void print_node(Node *n) {
	assert(n);
	print_data(n->data);
	return;
}

/**
 * --------------------------------------------------------
 * Parameters: 	a node (Node*)
 * Returns: 	a copy node (Node*)
 * Description:	Creates a copy of the given node
 * 				The new copy has a copy version of the data
 * 				the next pointer points to the same node as the original node's next
 * Assert:		given node is not NULL
 * --------------------------------------------------------
 */
Node* copy_node(Node *n) {
	assert(n);
	return create_node(n->data, n->next);
}

/**
 * ---------------------------------------------------
 * Parameters:  a node (Node**)
 * Returns: 	none
 * Description:	destroys a node by:
 * 				- destroy the encompassed data
 * 				- setting next to NULL
 * 				- free the node pointer
 * Assert:		n and *n are not NULL
 * --------------------------------------------------
 */
void destroy_node(Node **n) {
	assert(n && *n);
	destroy_data(&(*n)->data);
	(*n)->data = NULL;
	(*n)->next = NULL;
	free(*n);
	return;
}

//-----------------------------------------------------------
/**
 * Parameters: 	None
 * Returns: 	A pointer to linked list (List*)
 * Description:	Creates an empty linked list
 * 				head is set to NULL and size to 0
 * 				Returns a pointer to the newly created linked list
 * -----------------------------------------------------------
 */
List* create_list() {
	List *list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->size = 0;
	return list;
}

/**
 * -------------------------------------------------------------------
 * Parameters: 	Pointer to a linked list (List*)
 * Returns: 	None
 * Description:	traverse through all nodes
 * 				uses print_node(Node*) to print contents of nodes
 * 				starting from list head to tail
 * 				node1-->node2-->node3-->...-->NULL
 * 				prints <NULL> if empty list
 * Assert:		list is not NULL
 * -------------------------------------------------------------------
 */
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

/**
 * ---------------------------------------------------------------
 * Parameters: 	A linked list (List*)
 * 				A data item (Data*)
 * Returns: 	None
 * Description:	appends the given data item to the tail of the linked list
 * 				updates size and may update head
 * Assert		list and d are not NULL
 * ---------------------------------------------------
 */
void append_list(List *list, Data *d) {
	assert(list && d);
	Node *new_node = create_node(d, NULL);
	if (empty_list(list)) {
		list->head = new_node;
	} else {
		Node *current = list->head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
	}
	list->size++;
	return;
}

/**
 * ---------------------------------------------------------------
 * Parameters: 	a linked list (List**)
 * Returns: 	None
 * Description:	Destroys a given linked list
 * 				Deletes all nodes (which takes care of destroying data)
 * 				set head to NULL and size to 0
 * 				free list pointer
 * Assert:		**list and *list are is not Null
 * ---------------------------------------------------------------
 */
void destroy_list(List **list) {
	assert(*list && list);
	Node *prev = NULL;
	Node *curr = (*list)->head;
	while (!empty_list(*list) && curr->next != NULL) {
		prev = curr;
		curr = curr->next;
		destroy_node(&curr);
		(*list)->size--;
	}
	(*list)->head = NULL;
	(*list)->size = 0;
	free(*list);
	*list = NULL;
	return;
}

int empty_list(List *list) {
	assert(list);
	return (list->size == 0);
}

//------------------------- Assignment -------------------------
/**
 * -------------------------------------------------------------------------
 * Parameters: 	a linked list (List*)
 * 				a data item (Data*)
 * 				an index (int)
 * Returns: 	True/False
 * Description:	Inserts the given data item at position (index) at the linked list
 * 				if given index is out of range --> print an error and return NULL
 * 				returns True if insertion is successful, False otherwise
 * Assert:		given array and data pointers are not Null
 * -------------------------------------------------------------------------
 */
int insert_list(List *list, Data *d, int index) {
	assert(list && d);
	Node *node = create_node(d, NULL);
	if (index > list->size) {
		printf("Error(insert_list): index out of range\n");
		return False;
	}
	if (index == 0) {
		node->next = list->head;
		list->head = node;
		list->size++;
		return True;
	}
	Node *curr = list->head;
	Node *prev = NULL;
	int counter = 0;

	while (counter < index && curr != NULL) {
		prev = curr;
		curr = curr->next;
		counter++;
	}
	if (curr == NULL) {
		prev->next = node;
	} else {
		prev->next = node;
		node->next = curr;
	}
	list->size++;
	return True;
}

/**
 * -----------------------------------------------------------------
 * Parameters: 	list - a linked list (List*)
 * 				i - an index (int)
 * Returns: 	True/False
 * Description:	deletes the node at position (index) at the linked list
 * 				A copy of the data in the removed node is returned.
 * 				if given index is out of range --> print an error and return NULL
 * 				if given linked list is empty --> print an error and return NULL
 * Asserts:		given linked list is not NULL
 * ------------------------------------------------------------------
 */
Data* pop_list(List *list, int index) {
	assert(list);
	if (empty_list(list)) {
		printf("Error(pop_list): list is empty\n");
		return NULL;
	}
	if (index >= list->size) {
		printf("Error(pop_list): index out of range\n");
		return NULL;
	}

	Data *d = NULL;
	if (index == 0) {
		d = copy_data(list->head->data);
		list->head = list->head->next;
	} else {
		Node *curr = list->head;
		Node *prev = NULL;
		int counter = 0;

		while (counter < index && curr->next != NULL) {
			prev = curr;
			curr = curr->next;
			counter++;
		}
		d = copy_data(curr->data);
		prev->next = curr->next;
		destroy_node(&curr);

	}

	list->size--;
	if (list->size == 0) {
		list->head = NULL;
	}
	return d;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a linked List (List*)
 * 				start index (int)
 * 				end index  (int)
 * Returns: 	None
 * Description:	deletes items from the list from index start to end (inclusive both ends)
 * 				Updates head and size as necessary
 * 				if given list is empty, print error and return
 *				if given start or end indices are out of range --> print error msg and return
 * Assert:		linked list is not NULL
 * ---------------------------------------------------------------------
 */
void cut_list(List *list, int start, int end) {
	assert(list);
	if (empty_list(list)) {
		printf("Error(cut_list): Linked List is empty\n");
		return;
	}
	if (start < 0 || start >= list->size) {
		printf("Error(cut_list): Invalid start index\n");
		return;
	}
	if (end < 0 || end >= list->size || end < start) {
		printf("Error(cut_list): Invalid end index\n");
		return;
	}
	Node *curr = list->head;
	Node *prev = NULL;
	Node *temp = NULL;
	int counter = 0;

	while (counter < start && curr->next != NULL) {
		prev = curr;
		curr = curr->next;
		counter++;
	}

	while (counter < end && curr->next != NULL) {
		temp = curr;
		curr = curr->next;
		destroy_node(&temp);
		list->size--;
		counter++;
	}
	if (prev != NULL)
		prev->next = curr->next;
	else {
		list->head = NULL;
		list->size = 0;
	}

	return;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a linked list (List*)
 * 				start index (int)
 * 				end index  (int)
 * Returns: 	a linkedList (List*)
 * Description:	Constructs and returns a new linked list.
 * 				The new list contains elements from start to end (inclusive both ends)
 * 				if list is empty, print error msg and return empty list
 * 				if start/end is out of scope, print error msg and return empty list
 * 				Check if end index is greater than or requal to start index
 * Asserts:		list is not NULL
 * ---------------------------------------------------------------------
 */
List* sub_list(List *list, int start, int end) {
	assert(list);
	List *stil = create_list();
	if (empty_list(list)) {
		printf("Error(sub_list): Linked list is empty\n");
		return stil;
	}
	if (start < 0 || start >= list->size) {
		printf("Error(sub_list): Invalid start index\n");
		return stil;
	}
	if (end < 0 || end >= list->size || end < start) {
		printf("Error(sub_list): Invalid end index\n");
		return stil;
	}
	Node *curr = list->head;
	Node *prev = NULL;
	Node *temp = NULL;
	int counter = 0;
	while (counter < start && curr->next != NULL) {
		prev = curr;
		curr = curr->next;
		counter++;
	}
	while (counter <= end && curr != NULL) {
		temp = copy_node(curr);
		curr = curr->next;
		append_list(stil, copy_data(temp->data));
		counter++;
	}
	return stil;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a pointer to a linked list (List*)
 * 				i - index of first item (int)
 * 				j - index of second item (int)
 * Returns: 	None
 * Description:	swaps items i and j in the list
 * 				if invalid i and j, print error msg and return
 * Asserts:		asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */
void swap_list(List *list, int i, int j) {
	assert(list);
	if (empty_list(list)) {
		printf("Error(swap_list): list is empty\n");
		return;
	}
	if (i < 0 || j < 0 || i >= list->size || j >= list->size) {
		printf("Error (swap_list): Invalid value of i or j\n");
		return;
	}
	if (i == j)
		return;
	Node *curr = list->head;
	Node *prev = NULL;
	Node *prev2 = NULL;
	Node *iNode = NULL;
	Node *jNode = NULL;
	Node *temp = NULL;
	int counter = 0;

	if (j < i) {
		int k = j;
		j = i;
		i = k;
	}
	while (counter < i && curr->next != NULL) { //Prev is node before i
		prev = curr;
		curr = curr->next;
		counter++;
	}
	while (counter < j && curr->next != NULL) {	//Prev2 is node before j
		prev2 = curr;
		curr = curr->next;
		counter++;
	}
	if (i == 0) {
		iNode = list->head;
		jNode = prev2->next;
		temp = iNode->next;
		iNode->next = jNode->next;

		if (compare_data(temp->data, jNode->data) != 0) {
			prev2->next = iNode;
			jNode->next = temp;
		} else
			jNode->next = iNode;
		list->head = jNode;

	} else if (j - i == 1) {
		iNode = prev->next;
		jNode = prev2->next;
		iNode->next = jNode->next;
		prev->next = jNode;
		jNode->next = iNode;
	} else {
		iNode = prev->next;
		jNode = prev2->next;

		temp = iNode->next;
		iNode->next = curr->next;
		prev2->next = iNode;

		jNode->next = temp;
		prev->next = jNode;
	}
	return;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	first linked list (List*)
 * 				second linked list (List*)
 * Returns: 	new list (List*)
 * Description:	Creates a new list that contains items which appear in both lists
 * 				No duplicates allowed
 * Assert:		both linked lists are not NULL
 * ---------------------------------------------------------------------
 */
List* intersection_list(List *list1, List *list2) {
	assert(list1 && list2);
	Node *node1 = list1->head;
	List *list3 = create_list();

	intersection_aux(node1, list2, &list3);
	return list3;
}

List* intersection_aux(Node *node1, List *list2, List **list3) {
	int current = -1;
	if (node1 != NULL) {
		Data *d = node1->data;
		current = linear_search(list2, *d);
		if (current != -1) {
			current = linear_search(*list3, *d);
			if (current == -1) {
				append_list(*list3, copy_data(d));
			}
		}
		intersection_aux(node1->next, list2, list3);
	}
	return *list3;
}

int linear_search(List *list, Data item) {
	assert(list);
	int result = -1;
	int i = 0;
	Node *curr = list->head;
	while (curr != NULL) {
		if (compare_data(curr->data, &item) == 0) {
			result = i;
			break;
		}
		if (curr->next != NULL)
			curr = curr->next;
		else
			break;
		i++;
	}
	return result;
}

