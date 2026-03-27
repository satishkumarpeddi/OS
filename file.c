#include <stdlib.h>
#include <stdio.h>
void main(){
    int choice;
    char cmd[100];
    char fileName[100];
    printf("The File and Directory Managements\n");
    printf("1.Create File\n");
    printf("2.Delete File\n");
    printf("3.Copy File to File\n");
    printf("4.Rename File\n");
    printf("5.View the Content\n");
    printf("Enter a choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the fileName:");
            scanf("%s",fileName);
            sprintf(cmd,"touch %s",fileName);
            system(cmd);
        break;
        case 2: 
            printf("Enter the fileName to delete: ");
            scanf("%s",fileName);
            sprintf(cmd,"rm %s",fileName);
            system(cmd);
        break;
        case 3:
            char src[100],dest[100];
            printf("Enter the source file :");
            scanf("%s",src);
            printf("Enter the dest file : ");
            scanf("%s",dest);
            sprintf(cmd,"cp %s %s",src,dest);
            system(cmd);
        break;
        case 4:
            char oldName[100],newName[100];
            printf("Enter the old name of the file: ");
            scanf("%s",oldName);
            printf("Enter the new name of the file: ");
            scanf("%s",newName);
            sprintf(cmd,"mv %s %s",oldName,newName);
            system(cmd);
        break;
        case 5: 
            printf("Enter the fileName : ");
            scanf("%s",fileName);
            sprintf(cmd,"cat %s",fileName);
            system(cmd);
        break;

    }
}