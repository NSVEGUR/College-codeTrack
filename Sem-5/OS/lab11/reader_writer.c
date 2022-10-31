//Name: V Nagasai
//Roll No: CS20B1016
//Q: Implement the reader - writer problem’s solution using semaphore. 
// Use atleast three reader threads and two writer threads.  
// Also, clearly define the reading task and reading task inside the respective functions. 

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define LOOP_COUNT 10

//Binary Semaphore
pthread_mutex_t rd, wrt;
int r_count = 0;
char common_variable = '0';

void *read(void *args){
	char *reader_id = (char*)args;
	for(int i = 0; i < LOOP_COUNT; i++){
		//Lock reader semaphore to access r_count
		pthread_mutex_lock(&rd);
		r_count++;
		if(r_count == 1)
		//Lock writer semaphore if there is atleast one reading process
			pthread_mutex_lock(&wrt);
		pthread_mutex_unlock(&rd);
		//other readers can enter 
		//reading data
		printf("\n\033[0;34mReading data in reader - %c, common_variable is %c\n\n\033[0m", *reader_id, common_variable);
		//Lock reader semaphore to access r_count
		pthread_mutex_lock(&rd);
		r_count--;
		if(r_count == 0)
		//UnLock writer if there are no reading process
			pthread_mutex_unlock(&wrt);
		pthread_mutex_unlock(&rd);
	}
	return NULL;
}

void *write(void *args){
	char *writer_id = (char*)args;
	for(int i = 0; i < LOOP_COUNT; i++){
		//Lock writer semaphore to write data and dont allow any other writers
		pthread_mutex_lock(&wrt);
		printf("\n\033[0;31mWriting data in writer - %c\n\033[0m", *writer_id);
		common_variable = *writer_id;
		printf("\033[0;31mData written in common-variable is %c\n\n\033[0m", common_variable);
		//Unlock writer semaphore
		pthread_mutex_unlock(&wrt);
	}
	return NULL;
}

int main()
{
	pthread_t r1, r2, r3, w1, w2;
	//Initialising Binary Semaphore
	pthread_mutex_init(&rd, NULL);
	pthread_mutex_init(&wrt, NULL);
	//Creating threads
	//Reader & writer threads
	pthread_create(&r1, NULL, (void *)read, (void *)"1");
	pthread_create(&w1, NULL, (void *)write, (void *)"1");
	pthread_create(&r2, NULL, (void *)read, (void *)"2");
	pthread_create(&w2, NULL, (void *)write, (void *)"2");
	pthread_create(&r3, NULL, (void *)read, (void *)"3");
	//Ending threads
	pthread_join(r1, NULL);
	pthread_join(r2, NULL);
	pthread_join(r3, NULL);
	pthread_join(w1, NULL);
	pthread_join(w2, NULL);
	//Destroying the mutex
	pthread_mutex_destroy(&rd);
	pthread_mutex_destroy(&wrt);
	return 0;
}