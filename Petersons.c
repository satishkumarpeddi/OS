#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
int flag[2] = {0,0};
int trun;
int shared=0;
void* increment(void *args){ 
    int id = *(int*)args;
    int other = 1 - id;
    int i;
    for(i=0;i<100000;i++){ 
        flag[id] =1;
        trun = other;
        while(flag[other]&&trun==other);
        shared++; 
        flag[id]=0;
    }
    return NULL;
}

int main(){
    pthread_t t1,t2; 
    int id1=0,id2=1;
    pthread_create(&t1,NULL,increment,&id1);
    pthread_create(&t2,NULL,increment,&id2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Final value of shared variable : %d\n",shared); 
    return 0;
}