#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
sem_t lock;
int shared= 0;
void* increment(void *args){
    int i;
    for(i=0;i<100000;i++){
        sem_wait(&lock);
        shared++;
        sem_post(&lock);
    }
    return NULL;
}

void main(){
    pthread_t t1,t2;
    sem_init(&lock,0,1);
    pthread_create(&t1,NULL,increment,NULL);
    pthread_create(&t2,NULL,increment,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Final value of shared variable : %d\n",shared);
    sem_destroy(&lock); 

}