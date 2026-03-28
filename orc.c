#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

void main(){
    DIR * dir;
    struct dirent *entry;
    dir = opendir("/bin/ls");
    if(dir==NULL){
        perror("Failed to open current working directory");
        return;
    }
    while(entry=readdir(dir))
        printf("%s\n",entry->d_name);
    closedir(dir);
}