/*
 * -----------------------------------------------------
 * Course: 		CP264: Fall 2018
 * Author: 		Qutaiba Albluwi
 * Category: 	Stacks (Array Implementation) (Testing File)
 * -----------------------------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include "data.h"
# include "process.h"
# include "queue_array.h"

void test_queue();

int main() {
	setbuf(stdout, NULL);
	test_queue();
	return 0;
}

void test_queue() {
	int size = 10;
	printf("------------------------------\n");
	printf("Start: Testing Queue:\n\n");

	printf("Calling Queue* q = create_queue(10), print_queue(q):\n");
	Queue *q = create_queue(size);
	print_queue(q);
	printf("\n");

	printf("Calling is_empty_queue(q): ");
	printf("%d\n", is_empty_queue(q));
	printf("\n");

	int time = 10, arrival = 1;
	long pid = 1000010000;

	printf("Calling insert_queue:\n");
	printf("success = %d\n",
			insert_queue(q, create_process(pid++, time++, arrival++)));
	printf("Calling print_queue(q):\n");
	print_queue(q);
	printf("\n");

	printf("Calling is_empty_queue(q):");
	printf("%d\n", is_empty_queue(q));
	printf("\n");

	printf("Calling is_full_queue(q):");
	printf("%d\n", is_full_queue(q));
	printf("\n");

	printf("Adding 9 elements to Queue:\n");
	int i;
	for (i = 0; i < size - 1; i++) {
		insert_queue(q, create_process(pid++, time++, arrival++));
		print_queue(q);
		printf("\n");
	}
	printf("\n");

	printf("Calling is_full_queue(q):");
	printf("%d\n", is_full_queue(q));

	printf("Calling insert_queue:\n");
	printf("success = %d\n",
			insert_queue(q, create_process(pid++, time++, arrival++)));
	printf("\n");

	printf("Calling d = peek_queue(q):\t");
	Data *d = peek_queue(q);
	print_data(d);
	printf("\n\n");

	printf("Calling d = remove_queue(q)\n");
	d = remove_queue(q);
	printf("Printing removed data:\n");
	print_data(d);
	printf("\n");
	printf("Printing Queue: \n");
	print_queue(q);
	printf("\n");

	printf("remove another element:\n");
	d = remove_queue(q);
	printf("Printing removed data:\n");
	print_data(d);
	printf("\n");
	printf("Printing Queue: \n");
	print_queue(q);
	printf("\n");
	printf("is_full_queue(q):");
	printf("%d\n\n", is_full_queue(q));

	printf("Testing adjust:\n");
	printf("Calling insert_queue:\n");
	insert_queue(q, create_process(pid++, time++, arrival++));
	print_queue(q);
	printf("\n");

	printf("remove 8 elements\n");
	for (i = 0; i < size - 1; i++) {
		d = remove_queue(q);
		printf("Printing removed data:\n");
		print_data(d);
		printf("\nPrinting Queue: \n");
		print_queue(q);
		printf("\n");
	}

	printf("Calling destroy_queue(&q):\n");
	destroy_queue(&q);
	printf("Destroyed Successfully\n\n");

	printf("End: Testing Queue\n");
	printf("------------------------------\n\n");
	return;
}
