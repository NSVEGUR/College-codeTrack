#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arrivalZero(int n){
   int id[n], at[n], bt[n], temp; 
   for(int i = 0; i < n; i++){
        printf("Enter the id of process - %d : ", i+1);
        scanf("%d", &id[i]);
        at[i] = 0;
        printf("Enter the burst time of process - %d : ", i+1);
        scanf("%d", &bt[i]);
    }
     for(int i = 0; i < n - 1; i++){
        for(int j = i+1; j < n; j++){
            if(bt[i]>bt[j]){
                swap(&id[i], &id[j]);
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
            }else if(bt[i] == bt[j]){
                if(id[i] > id[j]){
                swap(&id[i], &id[j]);
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
                }
              }  
            }
        }
    int tat[n], wt[n], ct[n];
    ct[0] = bt[0] + at[0];
    for(int i = 0; i < n; i++){
        temp = 0;
        if(ct[i-1]<at[i]){
            temp = at[i] - ct[i-1];
        }
        ct[i] = ct[i-1] + bt[i] + temp;
    }
    for(int i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    float sumWT = 0, sumTAT = 0;
    for(int i = 0; i < n ; i++){
        sumWT += wt[i];
        sumTAT += tat[i];
    }
    printf("PID\tA.Time\tB.Time\tC.Time\tTA.Time\tW.Time\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", id[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average Waiting Time: %f\n", sumWT/n);
    printf("Average Turnaround Time: %f\n", sumTAT/n);
}



int main(){
    int n, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int choice = 1;
    
    // for(int i = 0; i < n - 1; i++){
    //     for(int j = i+1; j < n; j++){
    //         if(bt[i]>bt[j]){
    //             swap(&id[i], &id[j]);
    //             swap(&at[i], &at[j]);
    //             swap(&bt[i], &bt[j]);
    //         }else if(bt[i] == bt[j]){
    //           if(at[i]>at[j]){
    //             swap(&id[i], &id[j]);
    //             swap(&at[i], &at[j]);
    //             swap(&bt[i], &bt[j]);
    //             }else if(at[i] == at[j]){
    //                 if(id[i] > id[j]){
    //                 swap(&id[i], &id[j]);
    //                 swap(&at[i], &at[j]);
    //                 swap(&bt[i], &bt[j]);
    //                 }
    //             }  
    //         }
    //     }
    // }
    while(choice!=3){
        printf("1. All arriving at time 0\n");
        printf("2. All arrive at different time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: arrivalZero(n);
            default: printf("Please enter a correct choice.\n");
            }
        }
    return 0;
}