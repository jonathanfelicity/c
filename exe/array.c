#include <stdio.h>

#define LENGHT 10

void print_all(int arr[]){
	for(int i = 0; i <= LENGHT-1; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void mean(int arr[]){
	int sum = 0;
	for(int i = 0; i <= LENGHT-1; i++){
		sum += arr[i];
	}

	printf("%d", sum/LENGHT);
}


void locate_smallest(int arr[]){
	int index;
	int smallest = arr[0];

	for(int i = 0; i <= LENGHT; i ++){
		if(smallest > arr[i]){
			index = i;
			smallest = arr[i];
		}
	}

	printf("%d \n", index);
}

void second_runner_up(int arr[]){
	int max = arr[0];
	int second_max = arr[0];

	for(int i = 0; i <= LENGHT; i++){
		if(arr[i] > max){
			second_max = max;
			max = arr[i];
		}else if(arr[i] > second_max){
			second_max = arr[i];
		}
	}

	printf("%d \n", second_max);
}


void has_dup(int arr[]){

	for(int i = 0; i <= LENGHT -1; i++){
		for(int j = i+1; j < LENGHT - 1; j++){
			if(arr[i] == arr[j]){
				printf("true \n");
				return;
			}
		}
	}
	printf("false \n");
	return;
}


int main(void){
	int num[LENGHT] = {-1, 1, 1,3,4,5,6,77,8, 0};

	has_dup(num);

	return 0;
}