#include <stdio.h>
struct Process
{
    int id, waitingTime, arrivalTime, burstTime, turnAroundTime, priority;
};

struct Process process[10];

int main()
{
    int n, temp[10], t, count = 0, short_p;
    float total_WT = 0, total_TAT = 0, Avg_WT, Avg_TAT;
    printf("Enter the number of the process: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the id of process - %d : ", i+1);
        scanf("%d", &process[i].id);
        printf("Enter the arrival time of process - %d : ", i+1);
        scanf("%d", &process[i].arrivalTime);
        printf("Enter the burst time of process - %d : ", i+1);
        scanf("%d", &process[i].burstTime);
        printf("Enter the priority of process - %d : ", i+1);
        scanf("%d", &process[i].priority);
        temp[i] = process[i].burstTime;
    }

    process[9].priority = 10000;

    for (t = 0; count != n; t++)
    {
        short_p = 9;
        for (int i = 0; i < n; i++)
        {
            if (process[short_p].priority > process[i].priority && process[i].arrivalTime <= t && process[i].burstTime > 0)
            {
                short_p = i;
            }
        }

        process[short_p].burstTime = process[short_p].burstTime - 1;

        // if any process is completed
        if (process[short_p].burstTime == 0)
        {
            count++;
            process[short_p].waitingTime = t + 1 - process[short_p].arrivalTime - temp[short_p];
            process[short_p].turnAroundTime = t + 1 - process[short_p].arrivalTime;

            // total calculation
            total_WT = total_WT + process[short_p].waitingTime;
            total_TAT = total_TAT + process[short_p].turnAroundTime;
        }
    }

    Avg_WT = total_WT / n;
    Avg_TAT = total_TAT / n;

    // printing of the answer
    printf("PID\tW.Time\tTA.Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", process[i].id, process[i].waitingTime, process[i].turnAroundTime);
    }

    printf("Avg waiting time of the process  is %f\n", Avg_WT);
    printf("Avg turn around time of the process is %f\n", Avg_TAT);

    return 0;
}