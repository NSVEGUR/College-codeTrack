// Pre-emptive Priority based CPU scheduling

#include<stdio.h>
#include<stdlib.h>

struct Process{
	int id;
	int arrivalTime;
	int burstTime;
	int tempBurstTime;
	int completionTime;
	int turnAroundTime;
	int waitingTime;
	int priority;
};

struct Process *process;

void scheduleProcesses(int n){
	int count = 0;
	process[n].priority = -9999;
	for(int time = 0; count != n ; time++){
		int highest = n;
		for(int i = 0; i < n; i++){
			if((process[i].priority > process[highest].priority) && (process[i].arrivalTime <= time) && (process[i].tempBurstTime > 0)){
				highest = i;
			}
		}
		if(highest == n)
			continue;

		process[highest].tempBurstTime -= 1;
		
		if(process[highest].tempBurstTime == 0){
			//A Process is completed
			count++;
			process[highest].completionTime = time+1;
			process[highest].turnAroundTime = process[highest].completionTime - process[highest].arrivalTime;
			process[highest].waitingTime = process[highest].turnAroundTime - process[highest].burstTime;
		}
	}
}

void printTable(int n){
	printf("PID\tA.Time\tB.Time\tPri\tC.Time\tTA.Time\tW.Time\n");
	for(int i = 0; i < n; i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", process[i].id, process[i].arrivalTime, process[i].burstTime, process[i].priority, process[i].completionTime, process[i].turnAroundTime, process[i].waitingTime);
	}
}

int main(){
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	process = malloc((n+1)* sizeof(*process));
	for(int i = 0; i < n; i++){
			// process[i].id = i+1;
		printf("Enter the id of process: ");
		scanf("%d", &process[i].id);
		printf("Enter the arrival time of process - %d: ", process[i].id);
		scanf("%d", &process[i].arrivalTime);
		printf("Enter the burst time of process - %d: ", process[i].id);
		scanf("%d", &process[i].burstTime);
		printf("Enter the priority of process - %d: ", process[i].id);
		scanf("%d", &process[i].priority);
		process[i].tempBurstTime = process[i].burstTime;
	}
	scheduleProcesses(n);
	printTable(n);
	free(process);
}

