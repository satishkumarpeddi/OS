#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
void main(){
    char fileName[100],buffer[100];
    printf("Enter fileName : ");
    scanf("%s",fileName);
    int choice,n;
    int fd;
    printf("\n1.Create & Write\n2.Read\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            fd = open(fileName,O_CREAT|O_WRONLY|O_TRUNC,0644);
            if(fd<0){
                perror("File Creation | Opening is Failed.\n");
                return;
            }
            printf("Enter text to write : "); 
            getchar();
            fgets(buffer,sizeof(buffer),stdin);
            write(fd,buffer,strlen(buffer));
            printf("Data Written Successfully.\n");
            close(fd);
        break;
        case 2:
            fd = open(fileName,O_RDONLY);
            if(fd<0){
                perror("Error in opening file");
                return;
            }
            printf("\nFile Content:\n");
            while((n=read(fd,buffer,sizeof(buffer)))>0){
                write(1,buffer,n);
            }
            close(fd);
            break;
            
    }
}