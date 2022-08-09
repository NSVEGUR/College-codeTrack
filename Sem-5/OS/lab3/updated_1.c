#include<stdio.h>
#include<stdlib.h>

struct Process{
	int id;
	int arrivalTime;
	int burstTime;
	int completionTime;
	int turnAroundTime;
	int waitingTime;
};

struct Process *process;

void sortATime(int n){
	struct Process temp;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(process[i].arrivalTime > process[j].arrivalTime){
				temp = process[i];
				process[i] = process[j];
				process[j] = temp;
			}
		}
	}
}

void updateAvailable(int n, int currentTime, int *availableProcesses, int completedProcesses[]){
	for(int i = 0; i < n; i++){
		if(process[i].arrivalTime <= currentTime){
			if(completedProcesses[i]!=1){
				*(availableProcesses+i) = 1;
			}else{
				*(availableProcesses+i) = 0;
			}
		}
	}
}

int lowestBurstTime(int n, int availableProcesses[]){
	int min = 9999;
	int minIndex = -1;
	for(int i = 0; i < n; i++){
		if((availableProcesses[i] == 1) && (process[i].burstTime<min)){
			minIndex = i;
			min = process[i].burstTime;
		}
	}
	return minIndex;
}

void turnAroundAndWaitingTime(int n){
	for(int i = 0; i < n; i++){
		process[i].turnAroundTime = process[i].completionTime - process[i].arrivalTime;
		process[i].waitingTime = process[i].turnAroundTime - process[i].burstTime;
	}
}

void scheduleProcesses(int n){
	int availableProcesses[n];
	int completedProcesses[n];
	for(int i = 0; i < n; i++){
		availableProcesses[i] = 0;
		completedProcesses[i] = 0;
	}
	int currentTime = process[0].arrivalTime;
	int currentIndex = 0, previousIndex = -1;
	updateAvailable(n, currentTime, availableProcesses, completedProcesses);
	for(int i = 0; i < n; i++){
		currentIndex = lowestBurstTime(n, availableProcesses);
		// printf("current index %d\n", currentIndex);
		if(currentIndex == -1){
			i--;
			currentTime++;
			updateAvailable(n, currentTime, availableProcesses, completedProcesses);
			continue;
		}
		if(previousIndex == -1){
			process[currentIndex].completionTime = process[currentIndex].arrivalTime + process[currentIndex].burstTime; 
			// printf("cbt: %d cct %d\n", process[currentIndex].burstTime, process[currentIndex].completionTime);
		}else{
			int idleTime = 0;
			if(process[previousIndex].completionTime < process[currentIndex].arrivalTime){
				idleTime = process[currentIndex].arrivalTime - process[previousIndex].completionTime;
			}
			process[currentIndex].completionTime = process[previousIndex].completionTime + process[currentIndex].burstTime + idleTime;
			// printf("pct: %d cbt: %d cct %d idle %d\n", process[previousIndex].completionTime, process[currentIndex].burstTime, process[currentIndex].completionTime, idleTime);
		}
		currentTime = process[currentIndex].completionTime;
		completedProcesses[currentIndex] = 1;
		previousIndex = currentIndex;
		updateAvailable(n, currentTime, availableProcesses, completedProcesses);
		// for(int i = 0; i < n; i++){
	  // 	printf("%d ", availableProcesses[i]);
	  // }
	  // printf("\n");
	}
	turnAroundAndWaitingTime(n);
}


void printTable(int n){
	printf("PID\tA.Time\tB.Time\tC.Time\tTA.Time\tW.Time\n");
	for(int i = 0; i < n; i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", process[i].id, process[i].arrivalTime, process[i].burstTime, process[i].completionTime, process[i].turnAroundTime, process[i].waitingTime);
	}
}

int main(){
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	process = malloc(n*sizeof(*process));
	for(int i = 0; i < n; i++){
		// process[i].id = i+1;
		printf("Enter the id of process: ");
		scanf("%d", &process[i].id);
		printf("Enter the arrival time of process - %d: ", process[i].id);
		scanf("%d", &process[i].arrivalTime);
		printf("Enter the burst time of process - %d: ", process[i].id);
		scanf("%d", &process[i].burstTime);
	}
	sortATime(n);
	scheduleProcesses(n);
	printTable(n);
	free(process);
	return 0;
}
