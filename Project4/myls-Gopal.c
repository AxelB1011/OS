//Gopal Krishna Shukla
// Write a program that lists files in the given directory. When called without any 
// arguments, the program should just print the file names. When invoked with the -l flag, the 
// program should print out information about each file, such as the owner, group, 
// permissions,  and  other  information  obtained  from  the  stat()  system  call.  The  program 
// should take one additional argument, which is the directory to read, e.g., myls -l directory. 
// If no directory is given, the program should just use the current working directory. 

#include "Directory.h"
//printing the type is not required but doing it anyway
void printType(char* dirName){
	int i = strlen(dirName)-1;
	for(; i>0 && dirName[i]!='.'; i--) {
        if(i<0){ 
            printf("Folder\n"); 
            return;
        }
        if(i==strlen(dirName)-1){
            printf("Folder\n"); 
            return;
        }
    }
	for(i++; i<strlen(dirName); i++){
		printf("%c", dirName[i]);
	}
	printf("\n");

}

int main(int argc, char *argv[])
{
	DIR* rootDir=opendir(".");
	Dir* dir=readdir(rootDir);
    if(argc==1 && argv[1]==NULL){
        for(; dir!= NULL; dir=readdir(rootDir)) {
            printf("%s\n", dir->d_name);
        }
        return 0;
    }
    //if second argumennt is -l, print information
    if(argc==2 && strcmp(argv[1], "-l")==0 ){
        for(; dir!= NULL; dir=readdir(rootDir)) {
            printf("%s\n", dir->d_name);
            DirInfo dirInfo=getDirInfo(dir->d_name);
            printf("Size: %lld Bytes\n", dirInfo.st_size);
            printf("# blocks allocated: %lld\n", dirInfo.st_blocks);
            printf("reference (link) count: %d\n", dirInfo.st_nlink);
            printf("file inode #: %llu\n", dirInfo.st_ino);
            printTime(&dirInfo.st_mtime);
            printf("\nType: " );
            printType(dir->d_name);
            printf("Owner: %s\n", getpwuid(dirInfo.st_uid)->pw_name);
            printf("Group: %s\n", getgrgid(dirInfo.st_gid)->gr_name);
            printf("Permissions: ");
            printf(S_ISDIR(dirInfo.st_mode) ? "d" : "-");

            int parr[9] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
            char rwx[3] = {'r', 'w', 'x'};
            for(int i=0; i<9; i++){
                if (dirInfo.st_mode & parr[i]) {
                    printf("%c", rwx[i%3]);
                } else{
                    printf("-");
                }
            }
            printf("\n\n");
        }
        return 0;
    }
    //if third argument exists, (eg-./myls -l .vscode), print ls -l for the given directory
    if(argc==3 && argv[2]!=NULL){
        rootDir=opendir(argv[2]);
	    dir=readdir(rootDir);
        for(; dir!= NULL; dir=readdir(rootDir)) {
            printf("%s\n", dir->d_name);
            char *newStr = (char *)malloc(sizeof(char)*(strlen(argv[2])+strlen(dir->d_name)+1));
            strcpy(newStr, argv[2]);
            strcat(newStr, "/");
            strcat(newStr, dir->d_name);
            DirInfo dirInfo=getDirInfo(newStr);
            printf("Size: %lld Bytes\n", dirInfo.st_size);
            printf("# blocks allocated: %lld\n", dirInfo.st_blocks);
            printf("reference (link) count: %d\n", dirInfo.st_nlink);
            printf("file inode #: %llu\n", dirInfo.st_ino);
            printTime(&dirInfo.st_mtime);
            printf("\nType: " );
            printType(dir->d_name);
            printf("Owner: %s\n", getpwuid(dirInfo.st_uid)->pw_name);
            printf("Group: %s\n", getgrgid(dirInfo.st_gid)->gr_name);
            printf("Permissions: ");
            printf(S_ISDIR(dirInfo.st_mode) ? "d" : "-");

            int parr[9] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
            char rwx[3] = {'r', 'w', 'x'};
            for(int i=0; i<9; i++){
                if (dirInfo.st_mode & parr[i]) {
                    printf("%c", rwx[i%3]);
                } else{
                    printf("-");
                }
            }
            printf("\n\n");
            free(newStr);
        }
        return 0;
    }
}