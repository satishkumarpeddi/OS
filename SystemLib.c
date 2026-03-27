/*
    dirent :-  directory handling in C
    struct dirent
    struct dirent{
        ino_t d_ino;
        char d_name[256];
    };
*/
#include <stdio.h>
#include <dirent.h>
void main(){
    DIR * dir;
    struct dirent * entry;
    dir = opendir(".");
    if(dir==NULL){
        printf("Cannot Open Directory");
        return;
    }
    while((entry=(readdir(dir)))){
        printf("%s\n",entry->d_name);
    }
    return;
}