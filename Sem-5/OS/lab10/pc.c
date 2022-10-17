// Name: V Nagasai
// Roll: CS20B1016
/* Implement the producer – consumer problem’s solution using semaphore. 
	Use one producer thread and one consumer thread. Also, clearly define 
	the produce_item() function and consume_item() function. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

//Count and buffer variable shared by both the processes
int count = 0;
int buffer[3];// Max size of buffer is taken as 3
//Counting semaphores to keep track of produced and consumed items
sem_t empty, full;
//Binary semaphore for accessing buffer
pthread_mutex_t S;

//Produce_item which produces random numbers
int produce_item(){
	return rand()%100;
}

//Consume_item which does nothing
void consume_item(int item){

}

//Insert item which inserts into buffer
void insert_item(int item){
	if(count<3){
		buffer[count] = item;
		count += 1;
	}
}

//Remove item which removes item from buffer
int remove_item(){
	if(count>0){
		count -= 1;
		return buffer[count];
	}
	return -1;
}

//Producer
void *producer(void* args){
	while(1){
		//produce random numbers
		int item = produce_item();
		//Semaphore which checks whether the buffer is full or not and sleeps producer if full
		sem_wait(&empty);
		//Binary semaphore which locks S for accessing buffer
		pthread_mutex_lock(&S);
		//insert into buffer
		insert_item(item);
		//Binary semaphore which unlocks S after accessing buffer
		pthread_mutex_unlock(&S);
		printf("Inserted item: %d\n", item);
		//Semaphore which wakes up consumer if its asleep
		sem_post(&full);
	}
	return NULL;
}

void *consumer(void *args){
	while(1){
		//Semaphore which checks whether the buffer is full or not and sleeps consumer if empty
		sem_wait(&full);
		//Binary semaphore which locks S for accessing buffer
		pthread_mutex_lock(&S);
		int item = remove_item();
		//Binary semaphore which unlocks S after accessing buffer
		pthread_mutex_unlock(&S);
		printf("Removed item: %d\n", item);
		//Semaphore which wakes up producer if its asleep
		sem_post(&empty);
		//consume item
		consume_item(item);
	}
	return NULL;
}

int main(){
	pthread_t p, c;

	//Initialise semaphores
	sem_init(&empty, 0, 3);
	sem_init(&full, 0, 0);
	pthread_mutex_init(&S, NULL);

	//creates threads
	pthread_create(&p, NULL, (void *)producer, NULL);
	pthread_create(&c, NULL, (void *)consumer, NULL);

	//End threads
	pthread_join(p, NULL);
	pthread_join(c, NULL);

	//Destroy semaphores
	sem_destroy(&empty);
	sem_destroy(&full);
	pthread_mutex_destroy(&S);
	return 0;
}