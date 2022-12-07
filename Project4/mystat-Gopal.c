//Gopal Krishna Shukla
//Stat: Write your own version of the command line program  stat, which simply calls the 
//stat() system call on a given file or directory. Print out file size, number of blocks allocated, 
//reference (link) count, file permissions, and file inode.   

#include "Directory.h"

//Print out file size, number of blocks allocated, reference (link) count, file permissions, and file inode. 
int main(int argc, char *argv[])
{
	DirInfo dirInfo;
	stat(argv[1], &dirInfo);
	printf("Name: %s \n", argv[1]);
	printf("Size: %lld Bytes\n", dirInfo.st_size);
	printf("# blocks allocated: %lld\n", dirInfo.st_blocks);
	printf("reference (link) count: %d\n", dirInfo.st_nlink);
	printf("file inode #: %llu\n", dirInfo.st_ino);
	printf("Permissions: ");
	printf(S_ISDIR(dirInfo.st_mode) ? "d" : "-");

	//create permissions array and rwx array for ease of use
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

