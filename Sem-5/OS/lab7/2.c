//Name: V Nagasai
//Roll: CS20B1016
//Q: A parent process creates a child process and the child process creates a grandchild process. 
//The parent creates a pipe that is shared between the parent and the child. 
//The parent writes a message to the pipe and the child reads it from the pipe.
// The child creates another pipe which is shared between the child and the grandchild. 
//Note that this pipe is not available to the parent and is not the same as the one shared by the parent and the child. 
//The grandchild writes another message to the pipe and the child reads it from the pipe.
// After obtaining the two messages from the pipes, the child prints the difference in lengths of the two messages. 
//Moreover, each of the three processes prints the PID of its respective parent process. 
//The contents of the two messages must be taken as user inputs.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>

#define MAX_SIZE 50

int main(){
	int parentFds[2];//File descriptors for parent and child [0]->read, [1]->write
	int pid1;
	char parentWriteMessage[MAX_SIZE], parentReadMessage[MAX_SIZE];
	char grandchildWriteMessage[MAX_SIZE], grandchildReadMessage[MAX_SIZE];
	//creating pipe 1 parent and child pipe
	int returnStatus1 = pipe(parentFds);
	//check whether pipe 1 is created or not
	if(returnStatus1 < 0){
		printf("Unable to create parent pipe - pipe 1 [between parent and child].\n");
		exit(1);
	}
	//taking input for both pipes
	printf("Please Enter a message to write into the pipe-1 [between parent and child]: ");
	scanf("%s", parentWriteMessage);
	printf("Please Enter a message to write into the pipe-2 [between child and grandchild]: ");
	scanf("%s", grandchildWriteMessage);
	//creating parent and child processes
	pid1 = fork();
	if(pid1 != 0){
		//Parent Process
		printf("\nI am Parent. My id is %d\n", getpid());
		//writing into pipe1 from parent
		write(parentFds[1], parentWriteMessage, sizeof(parentWriteMessage));
		printf("Written Message from Parent is: %s\n\n", parentWriteMessage);
	}else{
		//Child process
		int childFds[2]; //File descriptors for child and grand child [0]->read, [1]->write
		int pid2;
		//creating pipe 2 child and grand child pipe
		int returnStatus2 = pipe(childFds);
		//check whether pipe 2 is created or not
		if(returnStatus2 < 0){
			printf("Unable to create child pipe - pipe 2 [between child and grand child].\n");
			exit(1);
		}
		//creating child and grandchild processes
		pid2 = fork();
		if(pid2!=0){
			//Child Process Continued as parent of grand child
			wait(NULL);//Wait until grandchild completes writing into the pipe
			printf("I am Child. My id is %d\n", getpid());
			//Reading from pipe 1
			read(parentFds[0], parentReadMessage, sizeof(parentReadMessage));
			printf("Read Message from pipe-1 is: %s\n", parentReadMessage);
			//Reading from pipe 2
			read(childFds[0], grandchildReadMessage, sizeof(grandchildReadMessage));
			printf("Read Message from pipe-2 is: %s\n", grandchildReadMessage);
			//calculating lengths and finding Difference
			int len1 = strlen(parentReadMessage);
			int len2 = strlen(grandchildReadMessage);
			int diff = abs(len1 - len2);
			printf("Difference between both the messages is: %d\n\n", diff);
		}else{
			//Grandchild process
			printf("I am Grandchild. My id is %d\n", getpid());
			//writing into pipe1 from parent
			write(childFds[1], grandchildWriteMessage, sizeof(grandchildWriteMessage));
			printf("Written Message from Grandchild is: %s\n\n", grandchildWriteMessage);
		}
	}
}