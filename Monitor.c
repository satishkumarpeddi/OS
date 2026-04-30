#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
typedef struct {
    int shared;
    pthread_mutex_t lock;
}Monitor;

void increament(Monitor *m){
    pthread_mutex_lock(&m->lock);
    m->shared++;
    pthread_mutex_unlock(&m->lock);
}
void *alloction(void *args){
    Monitor *m = (Monitor*)args;
    for(int i=0;i<10000;i++){
        increament(m);
    }
    return NULL;
}
void main(){
    pthread_t t1,t2;
    Monitor m;
    m.shared=0;
    pthread_mutex_init(&m.lock,NULL);
    pthread_create(&t1,NULL,alloction,&m);
    pthread_create(&t2,NULL,alloction,&m);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Final value of shared variable : %d\n",m.shared);
    pthread_mutex_destroy(&m.lock); 

}