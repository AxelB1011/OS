#include "readerwriter.c"

int main() {
    Thread threads[10000]; 
    int readerID=0, writerID=0, i=0;
    FILE *file=fopen("scenarios.txt", "r"); 
    char readerOrWriter; 
    rw3_init(&rw);
    if(file) {
        while(fscanf(file, "%c", &readerOrWriter)!=EOF){
            if(readerOrWriter== 'r') {
                int* id=createArgs(readerID++);
                threads[i++]=createThread(reader, id);
            }
            else if(readerOrWriter== 'w') {
                int* id=createArgs(writerID++);
                threads[i++]=createThread(writer, id);
            }
        }
        fclose(file); 
        for(int j=0; j<i; j++) {
            pthread_join(threads[j], NULL);
        }
        
    }
    else { 
        printf("Scenario file scenarios.txt does not exist.\n");
    }
    return 0;
}