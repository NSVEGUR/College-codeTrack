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

int n;
struct Process *process;

void scheduleProcesses(){
	int count = 0;
	int completedProcess[n];
	for(int i = 0; i < n; i++){
		completedProcess[i] = 0;
	}
	
	for(int time = 0; count != n; time++){
		int highestRRIndex = n;
		float highestRR = -9999.00;
		for(int i = 0; i < n; i++){
			if((process[i].arrivalTime <= time) && (!completedProcess[i])){
				float w = time - process[i].arrivalTime;
				float s = process[i].burstTime;
				float rr = (w+s) / s;
				if(rr > highestRR){
					highestRR = rr;
					highestRRIndex = i;
				}
			}
		}
		if(highestRRIndex == n){
			continue;
		}
		process[highestRRIndex].completionTime = time + process[highestRRIndex].burstTime;
		process[highestRRIndex].turnAroundTime = process[highestRRIndex].completionTime - process[highestRRIndex].arrivalTime;
		process[highestRRIndex].waitingTime = process[highestRRIndex].turnAroundTime - process[highestRRIndex].burstTime;
		completedProcess[highestRRIndex] = 1;
		time += process[highestRRIndex].burstTime;
		time -= 1;
		count++;
	}
}


void printTable(){
	printf("PID\tA.Time\tB.Time\tC.Time\tTA.Time\tW.Time\n");
	for(int i = 0; i < n; i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", process[i].id, process[i].arrivalTime, process[i].burstTime, process[i].completionTime, process[i].turnAroundTime, process[i].waitingTime);
	}
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
	}
	scheduleProcesses();
	printTable();
	return 0;
}