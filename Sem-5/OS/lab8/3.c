// Name: V Nagasai
// Roll: CS20B1016
// Write a program to create a thread. The thread is created by passing an array 
// which contains more than two integers as input from the main process. 
// The two or more array elements will be added in the thread and will return the 
// result to the main function. Finally, the main function will print the final sum.

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_SIZE 1000

//struct to store array, its size and sum of the elements
struct array{
	int arr[MAX_SIZE];
	int size;
	int sum;
};

void *thread_fn(void* _args){
	struct array *args = (struct array*)_args;
	args->sum = 0;
	//find the sum of array elements
	for(int i = 0; i < args->size; i++){
		args->sum += args->arr[i];
	}
	//exiting the thread
	pthread_exit(NULL);
}

int main(){
	pthread_t t1;
	struct array *args = calloc(sizeof(struct array), 1);
	printf("Please enter the size of the array: ");
	scanf("%d", &args->size);
	for(int i = 0; i < args->size; i++){
		printf("Enter the element - %d : ", i+1);
		scanf("%d", &args->arr[i]);
	}
	//creating thread with base array pointer
	pthread_create(&t1, NULL, &thread_fn, (void *) args);
	//waiting till the thread is finished
	pthread_join(t1, NULL);
	//after joining the thread args->sum will contain the updated sum from the thread_fn
	printf("Sum of the elements in the array is: %d\n", args->sum);
	return 0;
}