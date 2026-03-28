#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <fcntl.h>
#define BUFFER_SIZE 5
int in=0,out=0;
sem_t empty,full,mutex;
int buffer[BUFFER_SIZE];
void *Producer(void *arg){
    int item = 0;
    for(int i=0;i<10;i++){
        item = rand()%10;
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = item;
        printf("Producer : %d is position %d\n",item,in);
        in = (in+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}
void *Consumer(void *arg){
    int item;
    for(int i=0;i<10;i++){
        sem_wait(&full);
        sem_wait(&mutex);
        item = buffer[out];
        printf("Consumer : %d is position %d\n",item,out);
        out = (out+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
    }
    return NULL;
}
void main(){
    pthread_t p,c;
    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&full,0,0);
    sem_init(&mutex,0,1);
    pthread_create(&p,NULL,Producer,NULL);
    pthread_create(&c,NULL,Consumer,NULL);
    pthread_join(p,NULL);
    pthread_join(c,NULL);
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return;
}