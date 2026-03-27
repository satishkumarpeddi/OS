#include <stdio.h>
int max[100][100],alloc[100][100],avail[100],finish[100]={0},need[100][100],p,r;
void input();
void calculateNeed();
int safeCheck();
void preventDeadLock();
void main(){
    printf("---DeadLock Prevention---\n");
    input();
    calculateNeed();
    if(safeCheck()){
        printf("No DeadLock Occured System is Safe.\n");
        return;
    }else{
        printf("DeadLock occured.\n");
        preventDeadLock();
    }
}
void input(){
    printf("Enter number of processes:");
    scanf("%d",&p);
    printf("Enter number of resources:");
    scanf("%d",&r);
    printf("Enter Max Matrix : \n");
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&max[i][j]);
    printf("Enter Allocation Matrix : \n");
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);
    printf("Enter the available matrix : \n");
    for(int i=0;i<r;i++)
        scanf("%d",&avail[i]);
}
void calculateNeed(){
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            need[i][j] = max[i][j] - alloc[i][j];
}
int safeCheck(){
    int count=0;
    for(int i=0;i<p;i++){
        int found = 0;
        if(finish[i]==0){
            int canExecute = 1;
            for(int j=0;j<r;j++){
                if(need[i][j]>avail[j]){
                    canExecute=0;
                    break;
                }
            }
            if(canExecute){
                for(int k=0;k<r;k++){
                    avail[k] += alloc[i][k];
                    found=1;
                    finish[i]=1;
                }
            }
        }
        if(!found) return 0;
    }
    return 1;
}
void preventDeadLock(){
    printf("\nApplying Prevention(No Preemption+No Hold & Wait )\n");
    for(int i=0;i<p;i++){
        if(!finish[i]){
            printf("\nProcees P%d cannot procced -> Applying Preemption",i);
            for(int j=0;j<r;j++){
                avail[j]+=alloc[i][j];
                alloc[i][j]=0;
            }
            int canAllocate=1;
            for(int j=0;j<r;j++){
                if(need[i][j]>avail[j]){
                    canAllocate=0;
                    break;
                }
            }
            if(canAllocate){
                printf("\nAllocating all required resources to P%d",i);
                for(int j=0;j<r;j++){
                    avail[j]-=need[i][j];
                    alloc[i][j]+=need[i][j];
                    need[i][j]=0;
                }
                printf("\nP%d is exectued and released resources",i);
                for(int j=0;j<r;j++){
                    avail[j]+=alloc[i][j];
                    alloc[i][j]=0;
                }
                finish[i]=1;
            }else{
                printf("\nStill can't allocate resource to P%d",i);
            }
        }
    }
    printf("\n\nFinal Available Resources: ");
    for (int j = 0; j < r; j++)
        printf("%d ", avail[j]);

    printf("\n\nDeadlock prevented by:\n");
    printf("✔ Eliminating Hold and Wait\n");
    printf("✔ Applying Preemption\n");
}