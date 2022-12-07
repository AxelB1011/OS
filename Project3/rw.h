#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define Thread pthread_t
#define Semaphore sem_t
#define newInt(n) (int*)malloc(sizeof(int)*n)
#define wait(semaphore) sem_wait(&semaphore)
#define signal(semaphore) sem_post(&semaphore)
#define joinThread(thread) pthread_join(thread, NULL)
#define init(semaphore, value) sem_init(&semaphore, 0, value)

int* createArgs(int i) {
    int* args=newInt(1); 
    args[0]=i; 
    return args; 
}

Thread createThread(void* threadFunction(void*), void* args) {
    Thread thread; 
    pthread_create(&thread, NULL, threadFunction, args); 
    return thread;
}

//so apparently the thread.h code in Chapter 11 files is wrong.
//The original func signature for createThread was - Thread createThread(void* threadFunction, void* args)
//which gave the error - //error: no matching function for call to 'pthread_create'
//    pthread_create(&thread, NULL, threadFunction, args);
//candidate function not viable: cannot convert argument of incomplete type 'void *' to 'void * _Nullable (* _Nonnull)(void * _Nullable)' for 3rd argument
//int pthread_create(pthread_t _Nullable * _Nonnull __restrict,
