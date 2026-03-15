#include <stdio.h>
void main(){
int bt[20],wt[20],tat[20],n;
float wtavg,tatavg;
printf("Enter the number of processes --> ");
scanf("%d",&n);
for(int i=0;i<n;i++){
    printf("Enter Brust Time for Process %d --> ",i);
    scanf("%d",&bt[i]);
}
wt[0]=wtavg=0;
tat[0]=tatavg=bt[0];
for(int i=1;i<n;i++){
    wt[i] = wt[i-1]+bt[i-1];
    tat[i] = tat[i-1]+bt[i];
    wtavg+=wt[i];
    tatavg+=tat[i];
}
printf("\tProcess |\t Burst Time |\t Waiting Time |\t Turn Around Time\n");
for(int i=0;i<n;i++){
    printf("\n\t P%d\t\t %d \t\t %d \t\t %d",i,bt[i],wt[i],tat[i]);
}
printf("\n Average Waiting Time -- %f",wtavg/n);
printf("\n Average Turnaround Time -- %f",tatavg/n);
}