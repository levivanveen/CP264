# include <stdio.h>
# include <stdlib.h>
# include "data.h"
# include "process.h"
# include "cqueue.h"

void test_cqueue();

int main() {
	setbuf(stdout, NULL);
	test_cqueue();
	return 0;
}

void test_cqueue() {
	int size = 10;
	printf("------------------------------\n");
	printf("Start: Testing Circular Queue:\n\n");

	printf("Calling cQueue* q = create_cqueue(10), print_cqueue(q):\n");
	cQueue *q = create_cqueue(size);
	print_cqueue(q);
	printf("\n");

	printf("Calling is_empty_cqueue(q): ");
	printf("%d\n", is_empty_cqueue(q));
	printf("\n");

	int time = 10, arrival = 1;
	long pid = 1000010000;

	printf("Calling insert_cqueue:\n");
	printf("success = %d\n",
			insert_cqueue(q, create_process(pid++, time++, arrival++)));
	printf("Calling print_cqueue(q):\n");
	print_cqueue(q);
	printf("\n");

	printf("Calling is_empty_cqueue(q):");
	printf("%d\n", is_empty_cqueue(q));
	printf("\n");

	printf("Calling is_full_cqueue(q):");
	printf("%d\n", is_full_cqueue(q));
	printf("\n");

	printf("Adding 9 elements to cQueue:\n");
	int i;
	for (i = 0; i < size - 1; i++) {
		insert_cqueue(q, create_process(pid++, time++, arrival++));
		print_cqueue(q);
		printf("\n");
	}
	printf("\n");

	printf("Calling is_full_cqueue(q):");
	printf("%d\n", is_full_cqueue(q));
	printf("Calling insert_queue:\n");
	printf("success = %d\n",
			insert_cqueue(q, create_process(pid++, time++, arrival++)));
	printf("\n");

	printf("Calling d = peek_cqueue(q):\t");
	Data *d = peek_cqueue(q);
	print_data(d);
	printf("\n\n");

	printf("Calling d = remove_cqueue(q)\n");
	d = remove_cqueue(q);
	printf("Printing removed data:\n");
	print_data(d);
	printf("\n");
	printf("Printing cQueue: \n");
	print_cqueue(q);
	printf("\n");

	printf("remove another element:\n");
	d = remove_cqueue(q);
	printf("Printing removed data:\n");
	print_data(d);
	printf("\n");
	printf("Printing cQueue: \n");
	print_cqueue(q);
	printf("\n");
	printf("is_full_cqueue(q):");
	printf("%d\n\n", is_full_cqueue(q));

	printf("Testing circular insertion/deletion:\n\n");

	printf("Calling insert_cqueue:\n");
	insert_cqueue(q, create_process(pid++, time++, arrival++));
	print_cqueue(q);
	printf("\n");

	printf("remove 2 elements:\n");
	remove_cqueue(q);
	remove_cqueue(q);
	print_cqueue(q);
	printf("\n");

	printf("Calling insert_cqueue:\n");
	insert_cqueue(q, create_process(pid++, time++, arrival++));
	print_cqueue(q);
	printf("\n");

	printf("remove all elements\n");
	while (!is_empty_cqueue(q)) {
		d = remove_cqueue(q);
		printf("Printing removed data:\n");
		print_data(d);
		printf("\nPrinting cQueue: \n");
		print_cqueue(q);
		printf("\n");
	}

	printf("Calling destroy_cqueue(&q):\n");
	destroy_cqueue(&q);
	printf("Destroyed Successfully\n\n");

	printf("End: Testing Circular Queue\n");
	printf("------------------------------\n\n");
	return;
}

