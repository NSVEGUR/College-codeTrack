// Name: V Nagasai
// Roll: CS20B1016
// Banker's Algorithm

#include <stdio.h>
#include <stdbool.h>


// P0, P1, P2, P3, P4, P5 are the Process names here
const int processes = 6, resources = 4;// Number of processes and Number of resources
int max_matrix[processes][resources] = 
				{ // MAX Matrix
					{ 7, 5, 3, 3 }, // P0 
					{ 3, 2, 2, 4 }, // P1
					{ 9, 0, 2, 0 }, // P2
					{ 2, 2, 2, 3 }, // P3
					{ 4, 3, 3, 2 },  // P4
					{5, 4, 4, 1} //P5
				}; 
int allocated_matrix[processes][resources] = 
					{  // Allocation Matrix
						{0, 1, 0, 2 }, // P0 
						{ 2, 0, 0, 3 }, // P1
						{ 3, 0, 2, 0 }, // P2
						{ 2, 1, 1, 0 }, // P3
						{ 0, 0, 2, 1 }, // P4
						{1, 1, 0, 0 }, //P5
					};
int needed_matrix[processes][resources];
int available_resources[resources] = { 3, 3, 2, 4}; // Available Resources


void check_safety(int process, int *requested_resources){
	int allocated[processes][resources], available[resources], needed[processes][resources];
	//making a copy of all the data 
	for(int i = 0; i < processes; i++){
		for(int j = 0; j < resources; j++){
			allocated[i][j] = allocated_matrix[i][j];
			needed[i][j] = needed_matrix[i][j];
		}
		available[i] = available_resources[i];
	}
	//modify copies based on request
	for(int i = 0; i < resources; i++){
		available[i] -= requested_resources[i];
		allocated[process][i] += requested_resources[i];
		needed[process][i] -= requested_resources[i];
	}
	//check if the system is safe or not
	bool finished[processes] = {false};
	int sequence[processes], index = 0;
	for(int i = 0; i < processes; i++){
		for(int j = 0; j < processes; j++){
			//if system is not finished
			if(finished[j] == false){
				bool flag = false;
				for(int k = 0; k < resources; k++){
					//if its needed is greater than available
					if(needed[j][k] > available[k]){
						flag = true;
						break;
					}
				}
				if(flag == false){
					sequence[index] = j;
					index++;
					for(int k = 0; k < resources; k++){
						available[k] += allocated[j][k];
					}
					finished[j] = true;
				}
			}
		}
	}

	bool flag = false;

	for(int i = 0; i < processes; i++){
		if(finished[i] == false){
			flag = true;
			printf("\033[1;31mUNSAFE\033[0m\n");
			return ;
		}
	}
	if(flag == false){
		printf("\033[1;34mSAFE\033[0m\n");
		for(int i = 0; i < processes - 1; i++)
			printf(" P%d -> ", sequence[i]);
		printf(" P%d\n", sequence[processes-1]);
		//modify originals to copies if safe
		for(int i = 0; i < processes; i++){
			for(int j = 0; j < resources; j++){
				allocated_matrix[i][j] = allocated[i][j];
				needed_matrix[i][j] = needed[i][j];
			}
			available_resources[i] = available[i];
		}
	}
}


void request_resources(int process){
	int requested_resources[resources];
	printf("Enter the number of resources needed with spaces: ");
	for(int i = 0; i < resources; i++){
		scanf("%d", &requested_resources[i]);
	}
	for(int i = 0; i < resources; i++){
		if(requested_resources[i] > max_matrix[process][i] - allocated_matrix[process][i]){
			printf("\033[1;31mProcess is exceeding its maximum claim.\033[0m\n");
			return;
		}
	}
	for(int i = 0; i < resources; i++){
		if(requested_resources[i] > available_resources[i]){
			printf("\033[1;31mProcess is exceeding maximum available resources.\033[0m\n");
			return;
		}
	}
	check_safety(process, requested_resources);
}


int main()
{
	int process = 0, choice = 1;
	//finding the need matrix
	for (int i = 0; i < processes; i++) {
			for (int j = 0; j < resources; j++)
					needed_matrix[i][j] = max_matrix[i][j] - allocated_matrix[i][j];
	}
	//----printing initial matrix----
	printf("\n\033[1;34m-----Max Matrix-----\033[0;32m\n");
	for(int i = 0; i < processes; i++){
		for(int j = 0; j < resources; j++){
			printf("%d ", max_matrix[i][j]);
		}
		printf("\n");
	}
	printf("\033[1;34m-----Allocated Matrix-----\033[0;32m\n");
	for(int i = 0; i < processes; i++){
		for(int j = 0; j < resources; j++){
			printf("%d ", allocated_matrix[i][j]);
		}
		printf("\n");
	}
	printf("\033[1;34m-----Needed Matrix-----\033[0;32m\n");
	for(int i = 0; i < processes; i++){
		for(int j = 0; j < resources; j++){
			printf("%d ", needed_matrix[i][j]);
		}
		printf("\n");
	}
	printf("\033[1;34m-----Available Resources-----\033[0;32m\n");
	for(int i = 0; i < resources; i++){
		printf("%d ", available_resources[i]);
	}
	printf("\n\n\033[0m");
	while(choice != 2){
		printf("\033[0;33m1. Request resource.\n");
		printf("2. Exit\033[0m\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:	printf("Enter the process number to request[0 to 5]: ");
							scanf("%d", &process);
							if(process < 0 || process >= processes)
							break;
							else
							request_resources(process);
							break;
			case 2: printf("\nProgram is exited.\n");
							break;
			default: printf("\nPlease enter a valid choice.\n\n");
							break;
		}
	}
	return 0;
}
