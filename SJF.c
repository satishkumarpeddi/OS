#include <stdio.h>
void main(){
    int p[20],wt[20],tat[20],bt[20];
    printf("Enter number of processes: ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter Burst Time for Process %d: ",i+1);
        scanf("%d",&bt[i]);
        p[i] = i+1;
    }
    //Sorting processes based on burst time (SJF)
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(bt[i]>bt[j]){
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for(int i=1;i<n;i++){
        wt[i] = wt[i-1]+bt[i-1];
    }
    for(int i=0;i<n;i++){
        tat[i] = wt[i]+bt[i];
    }
    float total_wt = 0;
    float total_tat = 0;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
        total_tat+=tat[i];
        total_wt+=wt[i];
    }
    printf("\nAverage Waiting Time = %.2f",total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n",total_tat/n);
}