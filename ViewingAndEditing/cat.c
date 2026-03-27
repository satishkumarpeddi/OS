#include <stdio.h>
#include <fcntl.h>
void main(){
    int fd;
    char buffer[100];
    int n;
    fd = open("text.txt",O_RDONLY);
    if(fd<0){
        perror("Error in opening.");
        return;
    }
    while((n=read(fd,buffer,sizeof(buffer)))>0){
        write(1,buffer,n);
    }
    close(fd);
    return;
}