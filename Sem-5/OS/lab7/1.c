//Name: V Nagasai
//Roll: CS20B1016
//Q: Write a program using pipe() and fork() in which parent process takes one string as input. 
//The same is sent to the child using pipe1 and child will reverse it. After the reversing is complete, 
//the child process will send it (reversed string) to parent process using pipe2. 
//Subsequently, parent process will read the string and displays it.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>

#define MAX_SIZE 50

//function to reverse the string
void reverseString(char *str1, char* str2)  
{  
    int len = strlen(str1);
		//for specifying end of string
		str2[len] = '\0';
    int j = len - 1;
    for (int i = 0; i < len; i++)  
    {  
			str2[j] = str1[i];
			j--;
    }
}

int main(){
	int pipefds1[2], pipefds2[2];//File descriptors for parent and child, [0]->read, [1]->write
	int pid;
	char pipe1WriteMessage[MAX_SIZE], pipe2WriteMessage[MAX_SIZE], readMessage1[MAX_SIZE], readMessage2[MAX_SIZE];
	//creating pipe 1
	int returnStatus1 = pipe(pipefds1);
	//check whether pipe 1 is created or not
	if(returnStatus1 < 0){
		printf("Unable to create parent pipe - pipe 1.\n");
		exit(1);
	}
	//creating pipe 2
	int returnStatus2 = pipe(pipefds2);
	//check whether pipe 2 is created or not
	if(returnStatus2 < 0){
		printf("Unable to create child pipe - pipe 2.\n");
		exit(1);
	}
	//create parent and child processes
	pid = fork();
	if(pid != 0){
		//Parent Process
		close(pipefds1[0]);//close first pipe reading
		close(pipefds2[1]);//close second pipe writing

		printf("Please Enter the Message: ");
		scanf("%s", pipe1WriteMessage);
		//writing into pipe 1 from parent process to child
		write(pipefds1[1], pipe1WriteMessage, sizeof(pipe1WriteMessage));	
		printf("Written message from parent to child is[initial]: %s\n\n", pipe1WriteMessage);
		//wait till child reads, reverses and writes into pipe2.
		wait(NULL);
		//read from pipe 2 written from child process
		read(pipefds2[0], readMessage2, sizeof(readMessage2));
		printf("Read message from child in parent is[final]: %s\n", readMessage2);
	}else{
		//Child Process
		close(pipefds1[1]);//close first pipe writing
		close(pipefds2[0]);//close second pipe reading
		//read from pipe 1 written from parent process
		read(pipefds1[0], readMessage1, sizeof(readMessage1));
		printf("Read message from parent in child is[from pipe 1]: %s\n", readMessage1);
		//Reversing the string
		reverseString(readMessage1, pipe2WriteMessage);
		//writing into pipe 2 from child process to parent
		write(pipefds2[1], pipe2WriteMessage, sizeof(pipe2WriteMessage));	
		printf("Written message from child to parent is[from pipe 2]: %s\n\n", pipe2WriteMessage);
	}
	return 0;
}