//rrrrwrrr

//skeleton code copied from professor's code for "ReaderWriter.c" and "thread.h"

//"More thinking is needed than lines of code, indeed, the story behind this project is more interesting..." ---------- Dr. Wanwan Li 
//Well said

#include "rw.h"


typedef struct {
    sem_t rwl; //read-write lock (mutex)
    sem_t lock; //guard read count (guard)
    int readers; //no. of readers, writer will either be 1 or 0 so don't need a variable for that
    sem_t nostarve; //prevents the writer from starvation (fairness)
} rw3;

//initialize all semaphores to 1 and # of readers to 0
void rw3_init(rw3 *lock) {
    lock->readers = 0;
    init(lock->lock, 1); 
    init(lock->rwl, 1); 
    init(lock->nostarve, 1); 
}

rw3 rw;

//acquire read lock
void getrl(rw3 *lock) {
    // printf("getrl\n"); 
    wait(lock->nostarve);
    wait(lock->lock);
    lock->readers++;
    if (lock->readers == 1) {
        wait(lock->rwl);
    }
    signal(lock->lock);
    signal(lock->nostarve);
}

//release read lock
void freerl(rw3 *lock) {
    // printf("freerl\n"); 
    wait(lock->lock);
    lock->readers--;
    if (lock->readers == 0){
        signal(lock->rwl);
    }
    signal(lock->lock);
}

//acquire write lock
void getwl(rw3 *lock) {
    // printf("getwl\n"); 
    wait(lock->nostarve);
    wait(lock->rwl);
}

//release write lock
void freewl(rw3 *lock) {
    // printf("freewl\n"); 
    signal(lock->rwl);
    signal(lock->nostarve);
}


//reader writer and main copied from professors code
//added locks to solve starvation
void* writer(void* args) {
    
    int writerID=((int*)args)[0];

    printf("Writer[%d]  is created..\n", writerID); 
    getwl(&rw);
    printf("Writer[%d]  is writing\n", writerID); 
    printf("Writer[%d]  finished writing\n", writerID); 
    freewl(&rw);
    return NULL;
}

void* reader(void* args) {
    
    int readerID=((int*)args)[0];
    
    printf("Reader[%d]  is created..\n", readerID); 
    getrl(&rw);
    printf("Reader[%d]  is reading\n", readerID); 
    freerl(&rw);
    printf("Reader[%d]  finished reading\n", readerID); 
    
    return NULL;
}



