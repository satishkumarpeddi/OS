#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t lock;
int shared= 0;
void* increment(void *args){
    int i;
    for(i=0;i<100000;i++){
        pthread_mutex_lock(&lock);
        shared++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void main(){
    pthread_t t1,t2;
    pthread_mutex_init(&lock,NULL);
    pthread_create(&t1,NULL,increment,NULL);
    pthread_create(&t2,NULL,increment,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Final value of shared variable : %d\n",shared);
    pthread_mutex_destroy(&lock); 

}