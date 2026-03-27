#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h> 
#include <pthread.h>
#define BUFFER_SIZE 5
int in=0,out=0;
int buffer[BUFFER_SIZE];
sem_t full,empty,mutex;
void *Producer(void *args){
    int item;
    for(int i=0;i<10;i++){
        item = rand()%100;
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = item;
        printf("Produced: %d at position %d\n",item,in);
        in = (in+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
    }
}
void *Consumer(void *args){
    int item;
    for(int i=0;i<10;i++){
        sem_wait(&full);
        sem_wait(&mutex);
        item = buffer[out];
        printf("Consumer: %d at position %d\n",item,out);
        out = (out+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
    }
}
int main(){
    pthread_t p,c;
    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&full,0,0);
    sem_init(&mutex,0,1);
    pthread_create(&p,NULL,Producer,NULL);
    pthread_create(&c,NULL,Consumer,NULL);
    pthread_join(p,NULL);
    pthread_join(c,NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;
}