//Name: V Nagasai
//Roll: CS20B1016
//Q: Write a program where parent process will display the sorted sequence 
//of those 10 numbers in ascending order whereas the child process will 
//display the sorted sequence of those numbers in descending order.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int n;

	// Taking the input size of array
	printf("Enter the size of array: ");
	scanf("%d", &n);

	int arr[n];

	//Taking the input of array elements
	printf("Enter the elements of the array.\n");
	for(int i = 0; i < n; i++){
		printf("Enter the element - %d : ", i+1);
		scanf("%d", &arr[i]);
	}
	
	//Sorting the array.
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	int x = fork();

	int stop = 3;
	
	//If memory is not enough to allocate a process
	if(x < 0){
		printf("Memory Allocation problem for processes.\n");
		exit(1);
	}

	//wait temporarily stops the parent process and after the execution of child process it will resume
	wait(NULL);
	//Child Process
	if(x == 0){
		//printing the array in descending order and process id of child
		printf("Array in Descending Order: \n");
		printf("\033[1;34m[");
		for(int i = n - 1; i >= 0; i--){
			printf(" %d ,", arr[i]);
		}
		printf("\b]\n\033[0m");
		printf("I am Child Process.\n");
		printf("\033[0;36mMy Id is %d.\n\033[0m", getpid());
	}
	//Parent Process
	else{
		//Printing the array in ascending order and process id of child
		printf("Array in Ascending Order: \n");
		printf("\033[1;34m[");
		for(int i = 0; i < n; i++){
			printf(" %d ,", arr[i]);
		}
		printf("\b]\n\033[0m");
		printf("I am Parent Process.\n");
		printf("\033[0;36mMy Id is %d.\n\033[0m", getpid());
	}
	return 0;
}