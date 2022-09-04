//Name: V Nagasai
//Roll: CS20B1016
//Q: Program to show case the example of exec command in C

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	//Copied to previous process and will be executed
	printf("Hello form exec2.c\n");

	//Process id will be same since it is copied to that process by replacing it entirely
	printf("PID of exec2.c is: %d.\n", getpid());
	printf("Finished exec2.c\n");

	//After the end process will stop
	return 0;
}