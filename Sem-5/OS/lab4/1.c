//Name: V Nagasai
//Roll: CS20B1016
//Q: Implement Round Robin Scheduling Algorithm

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1000

struct Process{
	int id;
	int arrivalTime;
	int burstTime;
	int completionTime;
	int turnAroundTime;
	int waitingTime;
	int tempBurstTime;
};

struct Process *process;
int start = -1, end = -2;
int readyQueue[MAX_SIZE];
int timeQuantum, contextSwitchingOverHead = 0, n;

void push(int index){
	if(start == -1){
		start = 0;
		end = start;
		readyQueue[end] = index;
	}else{
		end++;
		readyQueue[end] = index;
	}
}

int pop(){
	if(start == -1){
		return -1;
	}else if(start == end){
		int index = start;
		start = -1;
		end = start;
		return readyQueue[index];
	}else{
		int index = start;
		start++;
		return readyQueue[index];
	}
}

void sortATime(){
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

void sortPID(){
	struct Process temp;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(process[i].id > process[j].id){
				temp = process[i];
				process[i] = process[j];
				process[j] = temp;
			}
		}
	}
}

void scheduleProcesses(){
	sortATime();
	int count = 0;
	int queuedProcess[n];
	for(int i = 0; i < n; i++){
		queuedProcess[i] = 0;
	}
	for(int time = 0; count != n ; time+=timeQuantum){
		int fcfs = n;

		if(start == -1){
			int arrivalTime = time;
			for(int i = 0; i < n; i++){
				if((process[i].arrivalTime <= arrivalTime) && (process[i].tempBurstTime > 0) ){
					arrivalTime = process[i].arrivalTime;
					fcfs = i;
				}
			}
			if(fcfs == n){
				time += 1;
				time -= timeQuantum;
				continue;
			}
		}else{
			fcfs = pop();
			queuedProcess[fcfs] = 0;
		}
		
		if(process[fcfs].tempBurstTime < timeQuantum){
				int timeToFinish;
				timeToFinish = process[fcfs].tempBurstTime;
				process[fcfs].tempBurstTime = 0;
				time += timeToFinish;
				count++;
				process[fcfs].completionTime = time;
				process[fcfs].turnAroundTime = process[fcfs].completionTime - process[fcfs].arrivalTime;
				process[fcfs].waitingTime = process[fcfs].turnAroundTime - process[fcfs].burstTime;
				time -= timeQuantum;
		}else{
			process[fcfs].tempBurstTime -= timeQuantum;
			if(process[fcfs].tempBurstTime == 0){
				count++;
				process[fcfs].completionTime = time + timeQuantum;
				process[fcfs].turnAroundTime = process[fcfs].completionTime - process[fcfs].arrivalTime;
				process[fcfs].waitingTime = process[fcfs].turnAroundTime - process[fcfs].burstTime;
			}
		}

		contextSwitchingOverHead++;
		
		for(int i = 0; i < n; i++){
				if((process[i].arrivalTime <= (time + timeQuantum)) && (process[i].tempBurstTime > 0) && (i != fcfs) && (!queuedProcess[i])){
					push(i);
					queuedProcess[i] = 1;
				}
		}

		if(process[fcfs].tempBurstTime != 0){
			push(fcfs);
			queuedProcess[fcfs] = 1;
		}
		
	}
	contextSwitchingOverHead--;
	sortPID();
}

void printTable(){
	printf("\033[0;33mPID\tA.Time\tB.Time\tC.Time\tTA.Time\tW.Time\n");
	for(int i = 0; i < n; i++){
		printf("\033[0;34m%d\t%d\t%d\t%d\t%d\t%d\n\033[0m", process[i].id, process[i].arrivalTime, process[i].burstTime, process[i].completionTime, process[i].turnAroundTime, process[i].waitingTime);
	}
}

float averageWaitingTime(){
	float sum = 0;
	for(int i = 0; i < n; i++){
		sum += process[i].waitingTime;
	}
	return sum/n;
}

float averageTurnAroundTime(){
	float sum = 0;
	for(int i = 0; i < n; i++){
		sum += process[i].turnAroundTime;
	}
	return sum/n;
}

int main(){
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	process = malloc((n)* sizeof(*process));
	for(int i = 0; i < n; i++){
			process[i].id = i+1;
		// printf("Enter the id of process: ");
		// scanf("%d", &process[i].id);
		printf("Enter the arrival time of process - %d: ", process[i].id);
		scanf("%d", &process[i].arrivalTime);
		printf("Enter the burst time of process - %d: ", process[i].id);
		scanf("%d", &process[i].burstTime);
		process[i].tempBurstTime = process[i].burstTime;
	}
	printf("Enter the time quantum of processes: ");
	scanf("%d", &timeQuantum);
	scheduleProcesses();
	printTable();
	printf("\033[0;36mContext Switching OverHead: %d\n", contextSwitchingOverHead);
	printf("Average Waiting Time: %f\n", averageWaitingTime());
	printf("Average Turnaround Time: %f\n\033[0;m", averageTurnAroundTime());
	return 0;
}

