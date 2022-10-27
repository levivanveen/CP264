# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "process.h"
# include "data.h"
# include "stack_array.h"

void test_process();
void test_data();
void test_stack();

int main() {
	setbuf(stdout, NULL);
	test_process();
	test_data();
	test_stack();
	return 0;
}

void test_process() {
	printf("------------------------------\n");
	printf("Start: Testing Process structure:\n\n");

	printf("Testing create_process:\n");
	printf("\tProcess* p1 = create_process(10000100000,40,10):\n");
	Process *p1 = create_process(1000010000, 40, 10);
	printf("\tarrival = \t%u\n", p1->arrival);
	printf("\tPID = \t\t%lu\n", p1->PID);
	printf("\ttime = \t\t%u\n", p1->time);
	printf("\n");

	char info[30] = "";
	printf("Testing get_process_info:\n");
	printf("\tget_process_info(p1,info)\n");
	get_process_info(p1, info);
	printf("\tvalue of info = %s\n", info);
	printf("\n");

	printf("Testing print_process:\n");
	printf("\tcall print_process(p1):\n\t");
	print_process(p1);
	printf("\n\n");

	Process *p2 = create_process(2000020000, 38, 16);
	printf("Creating Process p2:\n\t");
	print_process(p2);
	printf("\n\n");

	printf("Testing copy_process:\n");
	printf("\tcall Process* p3 = copy_process(p2):\n");
	printf("\tcall print_process(p3):\n\t");
	Process *p3 = copy_process(p2);
	print_process(p3);
	printf("\n\n");

	printf("Testing is_equal_process:\n");
	printf("\tcall is_equal_process(p2,p3):\n");
	printf("\tResult = %d\n", is_equal_process(p2, p3));
	printf("\n\tp2->arrival = 10\n");
	p2->arrival = 10;
	printf("\tcall is_equal_process(p2,p3):\n");
	printf("\tResult = %d\n", is_equal_process(p2, p3));
	printf("\n\tp2->time = 20\n");
	p2->time = 20;
	printf("\tcall is_equal_process(p2,p3):\n");
	printf("\tResult = %d\n", is_equal_process(p2, p3));
	printf("\n");

	printf("End: Testing Process Structure\n");
	printf("------------------------------\n\n");
	return;
}

void test_data() {
	printf("------------------------------\n");
	printf("Start: Testing Data:\n\n");

	int size = 10, i;
	Data *array = (Data*) malloc(sizeof(Data) * size);
	int pid = 1000010000, arrival = 30, time = 1;
	for (i = 0; i < size; i++)
		array[i] = *create_process(pid++, time++, arrival++);
	printf("Testing print Data:\n");
	for (i = 0; i < size; i++) {
		print_data(&array[i]);
		printf("\n");
	}
	printf("\n");
	printf("Testing Copy Data - copy last element to first element:\n");
	array[0] = *copy_data(&array[size - 1]);
	for (i = 0; i < size; i++) {
		print_data(&array[i]);
		printf("\n");
	}
	printf("\n");

	printf("Testing destroy_data:\n");
	Process *ptr;
	for (i = 0; i < 10; i++) {
		ptr = &array[i];
		destroy_data(&ptr);
	}
	printf("\tdestroy_data successful\n");
	printf("\n");

	free(array);

	printf("End: Testing Data\n");
	printf("------------------------------\n\n");
	return;
}

void test_stack() {
	printf("------------------------------\n");
	printf("Start: Testing Stack:\n\n");

	int size = 10;

	printf("--------- Testing Create/isEmpty/print ----------- \n");
	printf("Calling Stack* s = create_stack(10), print_stack(s):\n");
	Stack *s = create_stack(size);
	print_stack(s);
	printf("\n");

	printf("Calling isEmpty_stack(s):\n");
	printf("%d\n", is_empty_stack(s));
	printf("\n");

	printf("Testing push/is_empty/is_full/print:\n");

	printf("Calling push_stack(create_process(2000040000, 23, 44)):\n");
	printf("success = %d\n", push_stack(s, create_process(2000040000, 23, 44)));
	printf("Calling print_stack(s):\n");
	print_stack(s);
	printf("\n");

	printf("Calling isEmpty_stack(s):\n");
	printf("%d\n", is_empty_stack(s));
	printf("\n");

	printf("Calling isFull_stack(s):\n");
	printf("%d\n", is_full_stack(s));
	printf("\n");

	printf("Adding 9 elements to Stack:\n");
	int i, time = 10, arrival = 1;
	unsigned long pid = 1000010000;
	for (i = 0; i < size - 1; i++) {
		push_stack(s, create_process(pid++, time++, arrival++));
		print_stack(s);
		printf("\n");
	}
	printf("\n");

	printf("Calling isFull_stack(s):\n");
	printf("%d\n", is_full_stack(s));
	printf("\n");

	printf("Calling push_stack(randomProcess(5,20,0,40):\n");
	printf("success = %d\n", push_stack(s, create_process(pid++, 59, 88)));
	printf("\n\n");

	printf("Testing peek/pop:\n");

	printf("Calling d = peek_stack(s)\n");
	Data *d = peek_stack(s);
	print_data(d);
	printf("\n\n");

	printf("Calling d = pop_stack(s)\n");
	d = pop_stack(s);
	printf("Printing popped data:\n");
	print_data(d);
	printf("Printing Stack: \n");
	print_stack(s);
	printf("\n");

	printf("Popping 9 elements\n");
	for (i = 0; i < size - 1; i++) {
		d = pop_stack(s);
		printf("Printing popped data:\n");
		print_data(d);
		printf("\nPrinting Stack: \n");
		print_stack(s);
		printf("\n");
	}
	printf("\n");

	printf("Testing peek/pop/destroy:\n");
	d = pop_stack(s);
	d = peek_stack(s);

	printf("Calling destroy_stack(&s):\n");
	destroy_stack(&s);
	printf("destroy_stack successful\n\n");

	printf("End: Testing Stack\n");
	printf("------------------------------\n\n");
	return;
}

