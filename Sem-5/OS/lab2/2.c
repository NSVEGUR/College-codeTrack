//Name: V Nagasai
//Roll: CS20B1016
/*Q: Implement First Come First Serve CPU scheduling algorithm.*/

#include <stdio.h>

int main(){
    int n, temp, i, j;
    float averageWT = 0, averageTAT = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[n], at[n], bt[n], ct[n], wt[n], tat[n];
    for(int i = 0; i < n; i++){
        printf("Enter the Process ID of process %d: ", i+1);
        scanf("%d", &pid[i]);
        printf("Enter the Arrival Time of process %d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter the Burst Time of process %d: ", i+1);
        scanf("%d", &bt[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<(n-1);j++){
            if(at[j]>at[j+1]){
               temp = pid[j+1];
               pid[j+1] = pid[j];
               pid[j] = temp;
               
               temp = at[j+1];
               at[j+1] = at[j];
               at[j] = temp;
               
               temp = bt[j+1];
               bt[j+1] = bt[j];
               bt[j] = temp;
            }
        }
    }
    ct[0] = at[0] + bt[0];
    
    for(i = 1; i< n; i++){
        temp = 0;
        if(ct[i-1]<at[i]){
            temp = at[i] - ct[i-1];
        }
        ct[i] = ct[i-1] + bt[i] + temp;
    }
    for(i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        averageTAT +=tat[i];
        averageWT += wt[i];
    }
    averageTAT = averageTAT / n;
    averageWT = averageWT / n;
    printf("PID\tA.Time\tB.Time\tC.Time\tW.Time\tTA.Time\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);  
    }
    printf("Average Waiting Time: %f\n", averageWT);
    printf("Average Turnaround Time: %f\n", averageTAT);
    return 0;
}