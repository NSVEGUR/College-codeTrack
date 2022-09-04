//Name: V Nagasai
//Roll: CS20B1016
//Q: Print sum of first n even natural numbers in parent process and n odd natural numbers in child process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int n, evenSum = 0, oddSum = 0;

	//Taking the input count 
	printf("Enter the n to count sum: ");
	scanf("%d", &n);
	int x = fork();

	//To calculate sum
	for(int i = 1; i <= n; i++){
		//for even numbers
		if(i%2 == 0){
			evenSum += i;
		}
		//for odd numbers
		else{
			oddSum += i;
		}
	}
	

	//If memory is not enough to allocate a process
	if(x < 0){
		printf("Memory Allocation problem for processes.\n");
		exit(1);
	}

	//Child Process
	if(x == 0){
		//printing oddsum and id for child
		printf("\033[1;34mSum of upto n odd natural numbers: %d\n\033[0m", oddSum);
		printf("I am Child Process.\n");
		printf("\033[0;36mMy Id is %d.\n\033[0m", getpid());
	}
	//Parent Process
	else{
		//printing evensum and id for parent
		printf("\033[1;34mSum of upto n even natural numbers: %d\n\033[0m", evenSum);
		printf("I am Parent Process.\n");
		printf("\033[0;36mMy Id is %d.\n\033[0m", getpid());
	}
	return 0;
}