//Name: V Nagasai
//Roll: CS20B1016
//Q: Write a program to create multiple processes (up to 3/4 Levels) using fork() 
// and display their process IDs (getpid()) and parent process ID (getppid()).

#include<stdio.h>
#include<unistd.h>

int main(){
    //Forking for the first time to create two processes.
	int n0 = fork();
	//when its zero it will print the child process
 	if(n0 == 0){
		printf("I am the First Child (Level 1).\n");
		printf("My id is %d\n", getpid());
		printf("My parent id is %d\n\n", getppid());
		//Forking for the second time to create a child process to the present child as parent.
		n0 = fork();
		if(n0 == 0){
			printf("I am the Second Child (Level 2).\n");
			printf("My id is %d\n", getpid());
			printf("My parent id is %d\n\n", getppid());
			//Forking for the third time to create a child process to the present child as parent.
			n0 = fork();
			if(n0 == 0){
				printf("I am the Third Child (Level 3).\n");
				printf("My id is %d\n", getpid());
				printf("My parent id is %d\n\n", getppid());
				//Forking for the fourth time to create a child process to the present child as parent.
				n0 = fork();
				if(n0 == 0){
				printf("I am the Fourth Child (Level 4).\n");
				printf("My id is %d\n", getpid());
				printf("My parent id is %d\n\n", getppid());
			}
		}
	 }
	}
	//Every time when its not zero it will print the parent process
	printf("\nI am the Parent.\n");
	printf("My id is %d\n", getpid());
	printf("My parent id is %d\n\n", getppid());
	return 0;
}