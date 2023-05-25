#include <stdio.h>

int main(void){

	int age = 1003;
	int *ptr; // declare a pointer 
	ptr  = &age; // assign an address
	*ptr = 200; // updating value through pointer 
	printf("%d \n", *ptr); // Dereferencing the array to get the value


	return 0;
}