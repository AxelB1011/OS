//Gopal Krishna Shukla
// Tail: Write a program that prints out the last few lines of a file. The program should be 
// efficient, in that it seeks to near the end of the file, reads in a block of data, and then goes 
// back until it finds the requested number of lines; at this point, it should print out those lines 
// from the beginning to the end of the file. To invoke the program, one should type: mytail 
// -n file, where n is the number of lines at the end of the file to print. 
#include "Directory.h"
#define size 1000

//function to read the last n lines using fseek
//I tried using fseek and read but it was not printing out anything and I could not figure out why
//So I did some research 
void tail(FILE *file, int n){
    int idx=0;
    char buffer[size];
    if (fseek(file, 0, SEEK_END)) {
        fprintf(stderr, "fseek fail");
        return;
    } else {
        // idx = fseek(file, 0, SEEK_CUR);
        idx = ftell(file);
        while(idx){
            // Move 'idx' away from end of file.
            if (fseek(file, --idx, SEEK_SET)) {
                fprintf(stderr, "fseek fail");
                return;
            }
            else {
                if (fgetc(file) == '\n'){ //read n lines
                    n--;
                    if (n==0) {
                        break;
                    }
                }
            }
        }
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    int i=0, n = atoi(argv[1]+1); //input is -2, we just need 2
    
    FILE *file;
    file = fopen(argv[2], "r");
    if(file==NULL){
        fprintf(stderr, "Could not open file %s\n", argv[2]);
        return 0;
    }
    printf("These are the last %d lines of %s\n", n, argv[2]);
    tail(file, n);
    fclose(file);
}