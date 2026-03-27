#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;
int readCount = 0;

// Reader Function
void *reader(void *arg) {
    int id = *((int *)arg);

    sem_wait(&mutex);
    readCount++;
    if (readCount == 1)
        sem_wait(&wrt);  // First reader blocks writer
    sem_post(&mutex);

    printf("Reader %d is reading\n", id);
    sleep(1);

    sem_wait(&mutex);
    readCount--;
    if (readCount == 0)
        sem_post(&wrt);  // Last reader releases writer
    sem_post(&mutex);

    printf("Reader %d finished reading\n", id);
    return NULL;
}

// Writer Function
void *writer(void *arg) {
    int id = *((int *)arg);

    sem_wait(&wrt);  // Writer gets exclusive access

    printf("Writer %d is writing\n", id);
    sleep(2);

    printf("Writer %d finished writing\n", id);

    sem_post(&wrt);
    return NULL;
}

int main() {
    pthread_t r[5], w[5];
    int i, id[5];

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create Readers
    for (i = 0; i < 5; i++) {
        id[i] = i + 1;
        pthread_create(&r[i], NULL, reader, &id[i]);
    }

    // Create Writers
    for (i = 0; i < 5; i++) {
        id[i] = i + 1;
        pthread_create(&w[i], NULL, writer, &id[i]);
    }

    // Join Threads
    for (i = 0; i < 5; i++) {
        pthread_join(r[i], NULL);
        pthread_join(w[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}