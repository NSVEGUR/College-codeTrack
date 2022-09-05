//Name: V Nagasai
//Roll: CS20B1016
//Write two different programs (SenderNew and ReceiverNew) in C to demonstrate IPC using shared memory. 
//Process "SenderNew.c" will sets-up a string (take input from user) and writes it on to the shared memory and process. 
//"ReceiverNew.c" will read the string from the shared memory, checks whether the string is palindrome or not 
//(in the same process itself) and writes either 0 (not palindrome) or 1 (palindrome) to the shared memory. 
//Then, "ReceiverNew.c" will read the number (0/1) and displays the input string is palindrome or not.

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

	printf("Write something in memory to check palindrome or not[sender]: ");
	fgets(shm, 100, stdin);
	printf("Data written in the memory is[sender]: %s\n", shm);

	//Wait until receiver reads and writes in the process
	printf("Run receiver process and then press enter key --->: ");
	getchar();

	if(shm[0] == '0')
		printf("'0' is received hence it is not palindrome.\n");
	else if(shm[0] == '1')
		printf("'1' is received hence it is palindrome.\n");

	//Detach from shared memory
	shmdt(shm);

		// destroy the shared memory
  shmctl(shmid,IPC_RMID,NULL);
	return 0;
}