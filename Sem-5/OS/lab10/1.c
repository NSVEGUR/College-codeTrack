// Name: V Nagasai
// Roll: CS20B1016
/* Given 2 threads, schedule the order of execution in such a way that Thread A 
has to wait for Thread B and vice versa. In other words, given the code below you must guarantee that Statement A1 
happens before Statement B2 and Statement B1 happens before Statement A2.*/

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

//Binary Semaphore
pthread_mutex_t B1, B2;
int loopTime = 10;

//Thread A function
void *threadA(void*args){
	char* ch = (char*) args;
	for(int i = 0; i < loopTime; i++){
		//Lock B1 since entering statement A1
		pthread_mutex_lock(&B1);
		printf("I am Statement %c-1.\n", *ch);
		//Unlock B2 since A1 is executed to let B2 execute.
		pthread_mutex_unlock(&B2);
		//Lock B1 to stop A to execute A2
		pthread_mutex_lock(&B1);
		printf("I am Statement %c-2[must happen after B1].\n", *ch);
		//Unlock B2 to restart from start
		pthread_mutex_unlock(&B2);
	}
	return NULL;
}

//Thread B function
void *threadB(void* args){
	char* ch = (char*) args;
	for(int i = 0; i < loopTime; i++){
		//Lock B2 since entering statement B1
		pthread_mutex_lock(&B2);
		printf("I am Statement %c-1.\n", *ch);
		//Unlock B1 since B1 is executed to let A2 execute.
		pthread_mutex_unlock(&B1);
		//Lock B2 to stop B to execute B2
		pthread_mutex_lock(&B2);
		printf("I am Statement %c-2[must happen after A1].\n", *ch);
		pthread_mutex_unlock(&B1);
		//Unlock B1 to restart from start
	}
	return NULL;
}


int main(){
	pthread_t tA, tB;

	//Initialising Binary Semaphore
	pthread_mutex_init(&B1, NULL);
	pthread_mutex_init(&B2, NULL);

	//Creating threads
	pthread_create(&tA, NULL, (void *)threadA, (void *)"A");
	pthread_create(&tB, NULL, (void *)threadB, (void *)"B");

	//Ending threads
	pthread_join(tA, NULL);
	pthread_join(tB, NULL);

	//Destroying the mutex
	pthread_mutex_destroy(&B1);
	pthread_mutex_destroy(&B2);
	return 0;
}