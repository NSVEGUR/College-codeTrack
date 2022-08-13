#include<stdio.h>
#include<stdlib.h>

struct Process{
	int id;
	int arrivalTime;
	int burstTime;
	int completionTime;
	int turnAroundTime;
	int waitingTime;
	int priority;
	int completed;
};

struct Process *process;

void scheduleProcesses(int n){
	int count = 0;
	for(int time = 0; count != n; time++){
	int schedule = n;
	int priority = -9999;
		for(int i = 0; i < n; i++){
			if((process[i].priority > priority) && (process[i].arrivalTime <= time) &&(process[i].completed == 0)){
				schedule = i;
				priority = process[i].priority;
			}
		}
		if(schedule == n){
			continue;
		}
		process[schedule].completionTime = time + process[schedule].burstTime;
		time += (process[schedule].burstTime - 1);
		count++;
		process[schedule].completed = 1;
		process[schedule].turnAroundTime = process[schedule].completionTime - process[schedule].arrivalTime;
		process[schedule].waitingTime = process[schedule].turnAroundTime - process[schedule].burstTime;
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
	process = malloc((n)* sizeof(*process));
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
		process[i].completed = 0;
	}
	scheduleProcesses(n);
	printTable(n);
	return 0;
}