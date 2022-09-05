//Name: V Nagasai
//Roll: CS20B1016
//Q: Write two different programs (Sender and Receiver) in C to demonstrate IPC using shared memory. 
//Process "Sender.c" will write atleast 100 bytes of data to the shared memory and process "Receiver.c" 
//will read from the shared memory and displays it. Then, "Receiver.c" will write atleast 100 bytes of 
//data to the same shared memory and  "Sender.c" will read and displays it.

//Sender side code

#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

#define SHM_SIZE 1024


int main(){
	//For unique id to the shared memory
	key_t key = ftok("shmfile", 65);
	int shmid;//for shared memory id
	char* shm, *s;//char pointer to shared memory location

	//create shared memory segment
	if((shmid = shmget(key, SHM_SIZE, IPC_CREAT|0666))<0){
		printf("Error in shmget\n");
		exit(1); //Exit due to abnormal termination in shmget
	}

	//attach the created shared memory to out data space
	if((shm = shmat(shmid, NULL, 0)) == (char *) -1){
		printf("Error in shmat\n");
		exit(1); //Exit due to abnormal termination in shmat
	}

	s = shm;

	printf("Write something in memory[sender]: ");
	fgets(shm, 100, stdin);
	printf("Data written in the memory is[sender]: %s\n", shm);

	//Wait until receiver reads and writes in the process
	printf("Run receiver process and then press enter key --->: ");
	getchar();

	printf("Data read from the memory[sender]: %s\n", shm);
	//Detach from shared memory
	shmdt(shm);

		// destroy the shared memory
  shmctl(shmid,IPC_RMID,NULL);
	return 0;
}