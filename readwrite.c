#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
sem_t mutex,wrt;
int readCount = 0;
void *reader(void *arg){
    int id = *(int*)arg;
    free(arg);
    sem_wait(&mutex);
    readCount++;
    if(readCount==1)
        sem_wait(&wrt);
    sem_post(&mutex);
    printf("Reader:%d is reading.\n",id);
    sleep(1);
    sem_wait(&mutex);
    readCount--;
    if(readCount==0)
        sem_post(&wrt);
    sem_post(&mutex);
    printf("Reader:%d completed reading.\n",id);
    return NULL;
}
void *writer(void *arg){
    int id = *(int*)arg;
    free(arg);
    sem_wait(&wrt);
    printf("Writer:%d is writting.\n",id);
    sleep(2);
    printf("Writer:%d completed writing.\n",id);
    sem_post(&wrt);
    return NULL;
}
int main(){
    pthread_t r[5],w[5]; 
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    for(int i=0;i<5;i++){
        int *id=malloc(sizeof(int));
        *id = i+1;
        pthread_create(&r[i],NULL,reader,id);
    }
    for(int i=0;i<5;i++){
        int *id=malloc(sizeof(int));
        *id = i+1;
        pthread_create(&w[i],NULL,writer,id);
    }
    for(int i=0;i<5;i++){
        pthread_join(r[i],NULL);
        pthread_join(w[i],NULL);
    }
    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}
