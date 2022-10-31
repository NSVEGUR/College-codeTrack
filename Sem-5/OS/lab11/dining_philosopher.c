//Name: V Nagasai
//Roll: CS20B1016
//Q: Implement the dining philosopher's problem’s solution using semaphore. 
// Your solution should allow two philosopher's to eat simultaneously if there are five philosophers thread running simultaneously. 
// Also, clearly define the eating task and thinking task inside the respective functions. 

#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

#define PHILOSOPHERS 5
#define LOOP_COUNT 5

//Binary Semaphore
pthread_mutex_t s[PHILOSOPHERS], m;
char state[PHILOSOPHERS] = {'T'};

void eat(int i){
	printf("\033[0;34mPhilosopher - %d is eating\n\033[0m", i);
}

void think(int i){
	printf("\033[0;33mPhilosopher - %d is thinking\n\033[0m", i);
}

void findLeftRight(int i, int *left, int *right){
	//finding left and right based on circular dining table
	if(i == 0){
		*left = PHILOSOPHERS - 1;
		*right = i+1;
	}else if(i == PHILOSOPHERS - 1){
		*left = i - 1;
		*right = 0;
	}else{
		*left = i - 1;
		*right = i + 1;
	}
}

void test(int i){
	int left, right;
	//finding left and right philosophers of the current one
	findLeftRight(i, &left, &right);
	//testing
	if(state[i] == 'H' && state[left] != 'E' && state[right] != 'E')
	{
		//changing ith philosopher state to eating
		state[i] = 'E';
		pthread_mutex_unlock(&s[i]);
		//pick up both the forks
	}
}

void take_fork(int i){
	pthread_mutex_lock(&m);
	state[i] = 'H';
	//test whether forks are available
	test(i);
	pthread_mutex_unlock(&m);
	pthread_mutex_lock(&s[i]);
}

void put_fork(int i){
	pthread_mutex_lock(&m);
	state[i] = 'T';
	//Release both the fork
	int left, right;
	//finding left and right philosophers of the current one
	findLeftRight(i, &left, &right);
	//test LEFT and RIGHT
	test(left);
	test(right);
	pthread_mutex_unlock(&m);
}

void *philosopher(void *args){
	char* id = (char*) args;
	int philosopher_id = atoi(id);
	for(int i = 0; i < LOOP_COUNT; i++){
		think(philosopher_id);
		take_fork(philosopher_id);
		eat(philosopher_id);
		put_fork(philosopher_id);
	}
	return NULL;
}

int main()
{
	pthread_t p[PHILOSOPHERS];
	//Initialising Binary Semaphore
	pthread_mutex_init(&m, NULL);
	for(int i = 0; i < PHILOSOPHERS; i++){
		pthread_mutex_init(&s[i], NULL);
	}
	//Making all philosopher threads to 0
	for(int i = 0; i < PHILOSOPHERS; i++){
		pthread_mutex_lock(&s[i]);
	}
	//Creating threads
	pthread_create(&p[0], NULL, (void *)philosopher, (void *)"0");
	pthread_create(&p[1], NULL, (void *)philosopher, (void *)"1");
	pthread_create(&p[2], NULL, (void *)philosopher, (void *)"2");
	pthread_create(&p[3], NULL, (void *)philosopher, (void *)"3");
	pthread_create(&p[4], NULL, (void *)philosopher, (void *)"4");
	//Ending threads
	for(int i = 0; i < PHILOSOPHERS; i++){
		pthread_join(p[i], NULL);
	}
	//Destroying mutex
	pthread_mutex_destroy(&m);
	for(int i = 0; i < PHILOSOPHERS; i++){
		pthread_mutex_destroy(&s[i]);
	}
	return 0;
}