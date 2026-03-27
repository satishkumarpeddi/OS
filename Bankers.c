#include <stdio.h>
int max[100][100],need[100][100],alloc[100][100],avail[100];
int n,r;
void input();
void show();
void calculate();
int main(){
    printf("--Banker's Algorithm--\n");
    input();
    show();
    calculate();
}
void input(){
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resources: ");
    scanf("%d",&r);
    printf("Enter Max Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&max[i][j]);
    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);
    printf("Enter available resource:\n");
    for(int i=0;i<r;i++)
        scanf("%d",&avail[i]);
}
void show(){
    printf("\nProcess\tAlloaction\tMax\tAvailable\n");
    for(int i=0;i<n;i++){
        printf("P%d\t",i);
        for(int j=0;j<r;j++)
            printf("%d ",alloc[i][j]);
        printf("\t");
        for(int j=0;j<r;j++)
            printf("%d ",max[i][j]);
        printf("\t");
        if(i==0){
            for(int j=0;j<r;j++)
                printf("%d ",avail[j]);
        }
        printf("\n");
    }
}
void calculate(){
    int count=0;
    int finish[100] = {0};
    int sequence[100];
    for(int i=0;i<n;i++)   
        for(int j=0;j<r;j++)    
            need[i][j] = max[i][j] - alloc[i][j];
    while(count<n){
        int found= 0;
        for(int i=0;i<n;i++){
            if(finish[i]==0){
                int canExecute = 1;
                for(int j=0;j<r;j++){
                    if(need[i][j]>avail[j]){
                        canExecute=0;
                        break;
                    }
                }
                if(canExecute){
                    for(int k=0;k<r;k++)
                        avail[k] += alloc[i][k];
                    sequence[count++] = i;
                    found=1;
                    finish[i]=1;
                }
            }
        }
        if(!found) break;
    }
    if(count==n){
        printf("\n System is in Safe state\n Safe Sequence: ");
        for(int i=0;i<n;i++)
            printf("P%d ",sequence[i]);
    }else{
        printf("\n System is not in Safe state\n");
    }
}