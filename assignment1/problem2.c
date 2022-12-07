//COP 4600 - Project 1
//Gopal Krishna Shukla U10076283
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    //argv contains ./problem2 ls "|" -wc at this time. We don't need ./problem2 so we skip it
    argv = argv + 1;
    //char array to store the stuff before |
    char* pr1[20];
    //loop variable
    int i;
    //loop until we find the | symbol
    for (i=0; strcmp(argv[i], "|")!=0; i++){
        pr1[i]=argv[i];
    }
    //NULL terminate the array so that we can pass it to execvp
    pr1[i]=NULL;
    //pr1 should contain stuff before | and argv should contain stuff after | 
    argv+=i+1;

    int pipefd[2];
    if (pipe(pipefd)==-1){ //pipe failed
        fprintf(stderr, "pipe failed");
    } 
    int rc=fork();
    if (rc<0) { //fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rc==0){
        //in first child process where we make the process run cmd1(pr1)
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);close(pipefd[1]);
        execvp(pr1[0], pr1);
        
    }
    else {
        //in parent process where we wait for the first process to finish and create another child process
        int rc_wait=wait(NULL);
        int rc2=fork();
        if (rc2<0) { //fork failed
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if(rc2==0){
            //in second child process where we make the process run cmd2(argv)
            // using the output of the first process as the input
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);close(pipefd[1]);
            execvp(argv[0], argv);
            
        }
        else {
            //in parent process where we wait for the second child process to finish and print ++++ on a new line
            close(pipefd[0]);close(pipefd[1]);
            int rc_wait2=wait(NULL);
            printf("++++\n");
        }
    }
    return 0;
}