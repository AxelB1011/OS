//Gopal Krishna Shukla
// Write a program that prints out the names of each file and directory in 
// the file system tree, starting at a given point in the tree.  For example, when run without 
// arguments,  the  program  should  start  with  the  current  working  directory  and  print  its 
// contents, as well as the contents of any sub-directories, etc., until the entire tree, root at the 
// CWD, is printed. If given a single argument (of a directory name), use that as the root of 
// the tree instead.   

#include "Directory.h"

//helper function copied from Lecture 15, most of the work was done by me in the class for listdirrecursive.c
char* getFolderName(char* parentFolder, char* childFolder)
{
	char* name=newString(strlen(parentFolder)+1+strlen(childFolder));
	sprintf(name, "%s/%s", parentFolder, childFolder); return name;
}

void listFolder(char* pathName, char* folderName, int indent)
{
	printf("%*s%s\n", indent*4, " ", folderName); 
	DIR* rootDir=opendir(pathName); Dir* dir;
	if(rootDir==NULL)return; 
	for(dir=readdir(rootDir); dir!= NULL; dir=readdir(rootDir))
	{
		if(equals(dir->d_name,".") || equals(dir->d_name, "..")) continue;
		listFolder(getFolderName(pathName, dir->d_name), dir->d_name, indent+1);
	}
	
	closedir(rootDir); 
}

int main(int argc, char *argv[])
{
	//to print out the current working directory
	char cwd[PATH_MAX];
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("Current Path: %s\n", cwd);
	} else {
		perror("getcwd() error");
		return 1;
	}
	//If given a single argument (of a directory name), use that as the root of the tree instead.
	if (argv[1] != NULL){
		listFolder(argv[1], argv[1], 0);
		printf("Search with %s as root has finished!\n", argv[1]);
		return 0;
	}

	listFolder(".", ".", 0);
	printf("Search has finished!\n");
	return 0;
}
