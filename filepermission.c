#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
    char fileName[100];
    char premission[100];
    char cmd[100];
    int choice;
    while(1){
        printf("\n--- File Permission Commands ---\n");
        printf("1. Change permission (numeric)\n");
        printf("2. Add permission (symbolic)\n"); 
        printf("3. View permissions\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter fileName :");
                scanf("%s",fileName);
                printf("Enter numeric for premission: ");
                scanf("%s",premission);
                sprintf(cmd,"chmod %s %s",premission,fileName);
                system(cmd);
            break;
            case 2:
                printf("Enter fileName : ");
                scanf("%s",fileName);
                printf("Enter symbolic for premission: ");
                scanf("%s",premission);
                sprintf(cmd,"chmod %s %s",premission,fileName);
                system(cmd);
            break;
            case 3:
                printf("Enter fileName  : ");
                scanf("%s",fileName);
                sprintf(cmd,"ls -l %s",fileName);
                system(cmd);
            break;
            case 4:
                exit(0);
            break;
            default : 
                printf("Invalid choice\n");
        }
    }
    return 0;
}