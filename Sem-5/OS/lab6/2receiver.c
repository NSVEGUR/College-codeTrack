//Name: V Nagasai
//Roll: CS20B1016
//Write two different programs (SenderNew and ReceiverNew) in C to demonstrate IPC using shared memory. 
//Process "SenderNew.c" will sets-up a string (take input from user) and writes it on to the shared memory and process. 
//"ReceiverNew.c" will read the string from the shared memory, checks whether the string is palindrome or not 
//(in the same process itself) and writes either 0 (not palindrome) or 1 (palindrome) to the shared memory. 
//Then, "ReceiverNew.c" will read the number (0/1) and displays the input string is palindrome or not.

//Receiver side code

#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SHM_SIZE 1024

char isPalindrome(char *str){
	int i = 0;
	int j = strlen(str) - 2;

	if(j == 0 || j == 1)
		return '1';

	while(j > i){
		if(str[i++] != str[j--]){
			return '0';
		}
	}
	return '1';
}


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

	*shm = isPalindrome(shm);

	printf("Palindrome is checked and written to the memory\n");
	//Detach from shared memory
	shmdt(shm);
	return 0;
}