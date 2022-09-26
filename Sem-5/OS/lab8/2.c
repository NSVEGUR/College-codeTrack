// Name: V Nagasai
// Roll: CS20B1016
//Write a program to create a thread. The thread prints numbers from 0 to n, 
//where value of n is passed from the main process to the thread. 

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void *thread_fn(void* arg){
	//converting arg passed to id of the array
	int n = (int) arg;
	//printing 0 to n numbers
	for(int i = 0; i <= n; i++){
		printf("%d ", i);
	}
	printf("\n");
	return NULL;
}

int main(){
	pthread_t t1;
	int n;
	printf("Please enter the n: ");
	scanf("%d", &n);
	//creating a threads
	pthread_create(&t1, NULL, &thread_fn, (void*) n);
	//waiting till thread is completed
	pthread_join(t1, NULL);
	return 0;
}