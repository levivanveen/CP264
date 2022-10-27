/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include <math.h>
# include "heap.h"
# include "queue_array.h"
# include "stack_array.h"

Node* find_node_heap_aux(Node *n, Data *d);
int contains_heap_aux(Heap *h, Node *n, Data *d);
int is_full_heap_aux(Node *root);
Data* find_min_aux(Node *n, Data *min);
Data* find_max_aux(Node *n, Data *max);

//------------------------ A10 Task 1 -------------------------
/**
 * ------------------------------------------------------------
 * Parameters: 	d - 	a data item (Data*)
 * 				parent- pointer to parent (Node*)
 * 				left - 	pointer to left child (Node*)
 * 				right - pointer to right child (Node*)
 * Returns: 	node -	new heap node (Node*)
 * Description:	Creates a new heap node using the given data and pointers
 * Asserts:		data is not NULL
 * ------------------------------------------------------------
 */
Node* create_node(Data *d, Node *parent, Node *left, Node *right) {
	assert(d);
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = copy_data(d);
	node->parent = parent;
	node->left = left;
	node->right = right;
	return node;
}

/**
 * -------------------------------------------------------
 * Parameters: 	n - a node (Node*)
 * Returns: 	none
 * Description:	prints the contents of a heap node
 * 				invokes print_data, does not print parent, left and right
 * 				if node is NULL prints <NULL Node>
 * Assert:		None
 * -------------------------------------------------------
 */
void print_node(Node *n) {
	if (n == NULL) {
		printf("<NULL Node>");
	} else
		print_data(n->data);
	return;
}

/**
 * --------------------------------------------------------
 * Parameters: 	n - 	a node (Node*)
 * Returns: 	n2 -	a copy node (Node*)
 * Description:	Creates a copy of the given heap node
 * 				The new node has a duplicate copy of data and
 * 				same parent, left and right child
 * Assert:		given node is not NULL
 * --------------------------------------------------------
 */
Node* copy_node(Node *n) {
	assert(n);
	Node *n2 = create_node(copy_data(n->data), n->parent, n->left, n->right);
	return n2;
}

/**
 * ---------------------------------------------------
 * Parameters:  n - a node (Node**)
 * Returns: 	none
 * Description:	destroys a heap node by:
 * 				- destroy the encompassed data
 * 				- setting parent, left and right to NULL
 * 				- free the node pointer, and set it to NULL
 * Assert:		n and *n are not NULL
 * --------------------------------------------------
 */
void destroy_node(Node **n) {
	assert(n && *n);
	destroy_data(&(*n)->data);
	(*n)->data = NULL;
	(*n)->parent = NULL;
	(*n)->left = NULL;
	(*n)->right = NULL;
	free(*n);
	n = NULL;
	return;
}

//------------------------ A10 Task 2 -------------------------

/**
 * ------------------------------------------------------------
 * Parameters: 	type - heap type (max or min) (char*)
 * Returns: 	h - new heap (Heap*)
 * Description:	Creates a new heap of given type
 * 				Heap root is set to NULL and size to 0
 * 				if type is not "max" or "min" print error msg, set to "max"
 * Asserts:		none
 * ------------------------------------------------------------
 */
Heap* create_heap(char *type) {
	if (strcmp(type, "max") != 0 && strcmp(type, "min") != 0) {
		printf("Error(create_heap): invalid type, set to max\n");
		type = "max";
	}
	Heap *h = (Heap*) malloc(sizeof(Heap));
	strcpy(h->type, type);
	h->root = NULL;
	h->size = 0;
	return h;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap**)
 * Returns: 	none
 * Description:	destroys a heap by:
 * 				- removing all items
 * 				- setting root to NULL and size to 0 and type to empty string
 * 				- free the heap pointer, and set it to NULL
 * Assert:		h and *h are not NULL
 * --------------------------------------------------
 */
void destroy_heap(Heap **h) {
	assert(h && *h);
	while (!is_empty_heap(*h)) {
		remove_heap(*h);
	}
	strcpy((*h)->type, "");
	(*h)->root = NULL;
	(*h)->size = 0;
	free(*h);
	h = NULL;
	return;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	True/False
 * Description:	check if heap is empty
 * Assert:		h is not NULL
 * --------------------------------------------------
 */
int is_empty_heap(Heap *h) {
	assert(h);
	return (h->size == 0);
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	copy of data at the heap root
 * Description:	Returns a duplicate copy of the data item at the root
 * 				if heap is empty prints error msg, returns NULL
 * Assert:		h is not NULL
 * --------------------------------------------------
 */
Data* peek_heap(Heap *h) {
	assert(h);
	if (is_empty_heap(h)) {
		printf("Error(peek_heap): heap is empty\n");
		return NULL;
	}
	return copy_data(h->root->data);
}

//------------------------ A10 Task 3 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				d - a data item (Data*)
 * Returns: 	pointer to a node
 * Description:	Returns a pointer to the node that contains given data
 * 				if not found returns NULL
 * Assert:		h and are not NULL
 * --------------------------------------------------
 */
Node* find_node_heap(Heap *h, Data *d) {
	assert(h && d);
	Node *node = NULL;

	if (strcmp(h->type, "max") == 0) { //return NULL if d is bigger than heap root
		if (compare_data(h->root->data, d) == 2) {
			return NULL;
		}
	} else if (strcmp(h->type, "min") == 0) { //return NULL if d is smaller than heap root
		if (compare_data(h->root->data, d) == 1) {
			return NULL;
		}
	}
	node = find_node_heap_aux(h->root, d);

	return node;
}

/**
 * ---------------------------------------------------
 * Parameters:  n - a node (Node*)
 * Returns: 	a pointer to  a node
 * Description:	private helper function for find_node_heap
 * 				Uses recursion.
 * 				Search through given node and recurse to other nodes
 * Assert:		None
 * --------------------------------------------------
 */
Node* find_node_heap_aux(Node *n, Data *d) {
	// Base case, n doesn't exist
	if (n == NULL)
		return NULL;
	//Base case, check if node is node we're looking for
	if (compare_data(n->data, d) == 0) {
		return n;
	}
	Node *ptr = find_node_heap_aux(n->left, d); //ptr is left node of n, check if in heap
	if (ptr != NULL) {
		return ptr;
	} else {
		return find_node_heap_aux(n->right, d); //check if right node of n is in heap
	}
	return NULL;
}

//------------------------ A10 Task 4 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	None
 * Description:	Prints contents of a heap
 * 				if heap is empty prints <empty heap>
 * 				if heap is NULL prints <NULL Heap>
 * 				prints type and size of heap, then prints items in levelorder
 * 				Uses a queue.
 * 				items are separated by a space
 * Asserts:		None
 * --------------------------------------------------
 */
void print_heap(Heap *h) {
	if (h == NULL) {
		printf("<NULL Heap>\n");
		return;
	}
	printf("heap type = %s, size = %d\n", h->type, h->size);
	if (is_empty_heap(h)) {
		printf("<empty heap>\n");
	} else {
		Queue *q = create_queue(h->size);
		Node *n = h->root;
		insert_queue(q, h->root->data);
		int i = 0, j = 0;

		print_data(remove_queue(q));
		printf(" ");

		if (n->left != NULL) {
			insert_queue(q, n->left->data);
		}
		if (n->right != NULL) {
			insert_queue(q, n->right->data);
		}
		j = len_queue(q);

		//Heap root is printed, and root's children are in the queue
		while (i < j) {
			n = find_node_heap(h, remove_queue(q));
			print_data(n->data);
			printf(" ");
			if (n->left != NULL) {
				insert_queue(q, n->left->data);
			}
			if (n->right != NULL) {
				insert_queue(q, n->right->data);
			}
			i++;
			if (i == j) {
				i = 0;
				j = len_queue(q);
			}
		}
		printf("\n");

	}
	return;
}

//------------------------ A10 Task 5 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				d - data to search for (Data*)
 * Returns: 	True/False
 * Description:	Check if a heap contains a data item
 * 				recurse through all nodes to check
 * 					if any node contains the data
 * 				returns True if found and False otherwise
 * Asserts:		h and d are not NULL
 * --------------------------------------------------
 */
int contains_heap(Heap *h, Data *d) {
	assert(h && d);

	int contain = contains_heap_aux(h, h->root, d);
	return contain;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				n - current node to check if it contains the data (Node*)
 * 				d - data to search for (Data*)
 * Returns: 	True/False
 * Description:	Private helper function for contains_heap
 * 				recurse through all nodes to check if node contains data
 * 				returns True if found and False otherwise
 * Asserts:		None
 * --------------------------------------------------
 */
int contains_heap_aux(Heap *h, Node *n, Data *d) {
	// Base case, n doesn't exist
	if (n == NULL)
		return 0;
	//Base case, check if node is node we're looking for
	if (compare_data(n->data, d) == 0) {
		return 1;
	}
	//Base Case, check if node's data is lower than data
	if (strcmp(h->type, "max") == 0) { //return 0 if d is bigger than heap root
		if (compare_data(n->data, d) == 2) {
			return 0;
		}
	} else if (strcmp(h->type, "min") == 0) { //return 0 if d is smaller than heap root
		if (compare_data(n->data, d) == 1) {
			return 0;
		}
	}

	int contain = 0;
	contain = contains_heap_aux(h, n->left, d); //ptr is left node of n, check if in heap
	if (contain == 1) {
		return 1;

	} else {
		return contains_heap_aux(h, n->right, d); //check if right node of n is in heap
	}

	return 0;
}
//------------------------ A10 Task 6 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				start - a node for starting the search, normally the root (Node*)
 * 				node - the node to search for its level (Node*)
 * 				level - keeps track for level so far (int)
 * Returns: 	node_level - level of "node" in the heap (int)
 * Description:	Private helper method. Uses recursion.
 * 				Finds the level of a given node in a heap
 * 				if not found returns -1
 * Asserts:		heap is not NULL
 * --------------------------------------------------
 */
int find_node_level_heap_aux(Node *start, Node *node, int level) {
	if (start == NULL) // BAse case, node = null
		return -1;

	if (compare_data(start->data, node->data) == 0) {
		return level;
	}
	int new_level = find_node_level_heap_aux(start->left, node, level + 1);

	if (new_level != -1) {
		return new_level;
	}
	new_level = find_node_level_heap_aux(start->right, node, level + 1);
	return new_level;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				node - the node to search for its level (Node*)
 * Returns: 	node_level - level of "node" in the heap (int)
 * Description:	Finds the level of a given node in a heap
 * 				if not found returns -1
 * 				Root is assumed to be at level 1
 * Asserts:		heap is not NULL
 * --------------------------------------------------
 */
int find_node_level_heap(Heap *h, Node *node) {
	assert(h);
	if (node == NULL) {
		return -1;
	}
	int level = find_node_level_heap_aux(h->root, node, 1);

	return level;
}

//------------------------ A10 Task 7 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  root - pointer to root node (Node*)
 * Returns: 	True/False
 * Description:	A private helper function for is_full_heap function
 * 				Uses recursion
 * 				Returns True if heap is full and False otherwise
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
int is_full_heap_aux(Node *root) {
	// Base case, root doesn't exist
	if (root == NULL)
		return 1;

	int count = 0;
	if (root->left != NULL)
		count++;
	if (root->right != NULL)
		count++;
	//Base case, node has no children
	if (count == 0)
		return 1;

	//Node has children, check how many
	if (count == 1) {
		return 0;
	} else {
		int full = is_full_heap_aux(root->left);
		if (full == 0)
			return 0;
		else {
			return is_full_heap_aux(root->right);
		}
	}
	return 0;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - pointer to a heap (Heap*)
 * Returns: 	True/False
 * Description:	Returns True if heap is full and False otherwise
 * 				A full heap is a heap in which each node has 0 or 2 children
 * 				An empty heap is considered a full heap
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
int is_full_heap(Heap *h) {
	assert(h);
	int full = is_full_heap_aux(h->root);
	return full;
}

//------------------------ A10 Task 8 -------------------------
/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	d - copy of data with max data
 * Description:	Returns a duplicate copy of maximum item in heap
 * 				steps are different depending on max/min heap
 * 				if heap is empty, print error msg and return NULL
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
Data* find_max_heap(Heap *h) {
	assert(h);
	if (is_empty_heap(h)) {
		printf("Error(find_max_heap): empty heap\n");
		return NULL;
	}
	Data *d = NULL;
	//Check what type of heap it is
	if (strcmp(h->type, "max") == 0) {
		d = peek_heap(h);
	} else if (strcmp(h->type, "min") == 0) {
		Data *max = copy_data(h->root->data);
		d = find_max_aux(h->root, max);
	}
	return d;
}

Data* find_max_aux(Node *n, Data *max) {
	if (n == NULL) {
		return max;
	}
	if (compare_data(n->data, max) == 1) {
		max = copy_data(n->data);
	}
	max = find_max_aux(n->left, max);
	max = find_max_aux(n->right, max);
	return max;
}
/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	d - copy of data with min data
 * Description:	Returns a duplicate copy of minimum item in heap
 * 				steps are different depending on max/min heap
 * 				if heap is empty, print error msg and return NULL
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
Data* find_min_heap(Heap *h) {
	assert(h);

	if (is_empty_heap(h)) {
		printf("Error(find_min_heap): empty heap\n");
		return NULL;
	}
	Data *d = NULL;

	//Check what type of heap it is
	if (strcmp(h->type, "max") == 0) {
		Data *min = copy_data(h->root->data);
		d = find_min_aux(h->root, min);

	} else if (strcmp(h->type, "min") == 0) {
		d = peek_heap(h);
	}
	return d;
}

Data* find_min_aux(Node *n, Data *min) {
	if (n == NULL) {
		return min;
	}
	if (compare_data(n->data, min) == 2) {
		min = copy_data(n->data);
	}
	min = find_min_aux(n->left, min);
	min = find_min_aux(n->right, min);
	return min;
}

//------------------------ Do not change these -------------------------
void insert_heap(Heap *h, Data *d) {
	return;
}

void remove_heap(Heap *h) {
	return;
}
