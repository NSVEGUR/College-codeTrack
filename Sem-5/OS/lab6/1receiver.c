//Name: V Nagasai
//Roll: CS20B1016
//Q: Write two different programs (Sender and Receiver) in C to demonstrate IPC using shared memory. 
//Process "Sender.c" will write atleast 100 bytes of data to the shared memory and process "Receiver.c" 
//will read from the shared memory and displays it. Then, "Receiver.c" will write atleast 100 bytes of 
//data to the same shared memory and  "Sender.c" will read and displays it.

//Receiver side code

#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

#define SHM_SIZE 1024


int main(){
	key_t key = ftok("shmfile", 65);
	int shmid;//for shared memory id
	char* shm;//char pointer to shared memory location

	//create shared memory segment
	if((shmid = shmget(key, SHM_SIZE, 0666))<0){
		printf("Error in shmget\n");
		exit(1); //Exit due to abnormal termination in shmget
	}

	//attach the created shared memory to out data space
	if((shm = shmat(shmid, NULL, 0)) == (char *) -1){
		printf("Error in shmat\n");
		exit(1); //Exit due to abnormal termination in shmat
	}

	printf("Data read from memory is [receiver]: %s\n", shm);

	//Writing at the receiver end
	printf("Write something in memory[receiver]: ");
	fgets(shm, 100, stdin);
	printf("Data written in the memory is[receiver]: %s\n", shm);


	//Detach from shared memory
	shmdt(shm);
	return 0;
}