//Name: V Nagasai
//Roll: CS20B1016
//Q: Program to show case the example of exec command in C

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	printf("Hello form exec1.c\n");

	//Pid of current process
	printf("PID of exec1.c is: %d.\n", getpid());

	char *args[] = {"Hello", NULL};

	//This command replaces this current file entirely with the exec2.c and executes it
	execvp("./exec2", args);

	//Since it is replaced this line won't be executed
	printf("Finished exec1.c\n");
	return 0;
}