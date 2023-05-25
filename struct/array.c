#include <stdio.h>


struct Array
{
	int value;
};

int main(void){

	struct Array array[5];

	array[0].value = 45;
	array[1].value = 6;
	array[2].value = 4;
	array[3].value = 5;

	for(int i = 0; i < 5; i++){
		printf("%d \n", array[i].value);
	}


	return 0;
}