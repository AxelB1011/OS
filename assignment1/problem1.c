//COP 4600 - Project 1
//Gopal Krishna Shukla U10076283
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    //argv contains ./problem1 ls -l at this time. We don't need ./problem1 so we skip it
    argv = argv + 1;
    //create new process using fork
    int rc=fork();
    if (rc<0) { //fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rc==0){
        //execute cmd with params as parameter if given
        execvp(argv[0], argv);
    }
    else {
        //wait for process to finish executing
        int rc_wait=wait(NULL);
        //print ++++ on a new line
        printf("++++\n");
    }
    return 0;
}