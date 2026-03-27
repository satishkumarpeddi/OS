#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
void main(){
    int fd;
    fd = open("test.txt",O_CREAT|O_RDWR,0644);
    if(fd<0){
        printf("Error Opening file\n");
        return;
    }
    printf("File Open successfully\n");
    printf("File Descriptor: %d\n",fd);
    close(fd);
}