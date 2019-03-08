//Author@ Mohammed Hossain
//Task_3_Prcs_P1
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h> 
#include <errno.h>
#include <unistd.h>	
int create2f(char* file1, char* file2){

	int fd1, fd2; 
	
	fd1 = creat(file1, 0700); //create file1 for read, write and excute for owner
    fd2 = creat(file2, 0700);//create file2 for read, write and execute for owner
	if(-1 == fd1 || fd2 == -1) {
		printf("\n creat() failed with error [%s]\n",strerror(errno)); 
		return 1;
	} 
	return 0;
}

int main(){
    char * f1 = "destination1.txt";
    char * f2 = "destination2.txt";

    create2f(f1, f2);
	return 0;
}
