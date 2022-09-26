// Name: V Nagasai
// Roll: CS20B1016
// Write a program to create five threads using pthread library. 
// Find the sum of first 1000 numbers using five threads, where each 
// thread can calculate sum of 200 numbers in each (parallel counting using threads).

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//To store sum of 5 threads each in each element of the array
int sum[5];

void *thread_fn(void* arg){
	//converting arg passed to id of the array
	int id = (int) arg;
	printf("\033[0;31mI am thread %d\033[0m\n", id);
	int start = id * 200;
	int i = start + 1;
	//calculating sum of idth 200 numbers
	while(i<=start+200){
		sum[id] += i;
		i++;
	}
	printf("\033[0;32mSum calculated at thread %d is: %d\033[0m\n", id, sum[id]);
	return NULL;
}

int main(){
	pthread_t t1, t2, t3, t4, t5;
	//creating 5 threads
	pthread_create(&t1, NULL, &thread_fn, (void*) 0);
	pthread_create(&t2, NULL, &thread_fn, (void*) 1);
	pthread_create(&t3, NULL, &thread_fn, (void*) 2);
	pthread_create(&t4, NULL, &thread_fn, (void*) 3);
	pthread_create(&t5, NULL, &thread_fn, (void*) 4);
	//waiting till each process is completed
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	pthread_join(t5, NULL);
	//printing the sum of first thousand numbers save in sum array calculated by 5 different threads
	printf("\n\033[1;34mSum of first thousand numbers: %d\033[0m\n\n", sum[0]+sum[1]+sum[2]+sum[3]+sum[4]);
	return 0;
}