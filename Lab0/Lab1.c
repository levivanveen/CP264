/**
 -------------------------
 Student Name: Levi Van Veen
 Student ID: 200852490
 Student email: vanv2490@mylaurier.ca
 -------------------------
 **/

void t2();

int main(void) {
	t1();
	printf("\n");
	t2();
	printf("\n");
	t3();
	return 0;
}

void t1() {
	int tall,short,total;
	double avg_height;
	int symbol = 84;
	const int VAL = 43;

	printf("Enter number of tall trees: ");
	scanf("%d", &tall);
	printf("Enter number of short trees: ");
	scanf("%d", &short);
	total = tall + short;
	//printing report
	printf("Number of %c trees = %d\n", symbol, tall);
	printf("Number of %c trees = %d\n",(symbol-1),short);
	printf("Average height = %.2lf", (VAL / (double) total));
	return 0;
}

void t2(){
	unsigned int year;
	short month;
	int day;
	char university[30];
	
	scanf("%u", &year);
	scanf("%hd", &month);
	scanf("%d", &day);
	scanf("%c", &university);
	
	printf("This is %c\n", university);
	printf("Today is: %d/%hd/%u", day, month, year);
	
	return 0;
}

void t3(){
	//your code here
	return 0;
}