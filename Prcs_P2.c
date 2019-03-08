//Author@ Mohammed Hossain
//Task_3_Prcs_P2
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h> 
#include <errno.h>
#include <unistd.h>	
int copytxt(char* source, char* dest1, char* dest2){

	int fds, fd1, fd2; 
	
	errno = 0; 
	fds = open(source,O_RDONLY); //source is a file, and O_RDONLY is the read only flag
    fd1 = open(dest1, O_WRONLY);//open file for writing
    fd2 = open(dest2, O_WRONLY);//open file for writing

	if(fds == -1 || fd1 == -1 || fd2 == -1) {
		printf("\n open() failed with error [%s]\n",strerror(errno)); 
		return 1;
	} 
	else {
        //prepare for reading from source

        //for reading
        char buf[100]; //buffer of 103, 100 for bytes reading, the other 3 of "XYZ"
        int readCount = read(fds, buf, 100); //read 100 bytes from source
        
        //for writing
        int writeCount;
        int dest1_OR_dest2;
        while(readCount > 0){ //successfully read 100 bytes
            //source to dest1
            for(int i = 0; i< readCount; i++){
                if (buf[i] == '1'){ //every '1' we see 
                    buf[i] = 'A';//change it to an 'A'
                }
            }
            writeCount = write(fd1, buf, readCount); //write the 100 bytes read from source to dest1
            /*-------------------------------------------------------------------------------*/
                
            //source to dest2
            readCount = read(fds, buf, 50); //now read 50 more byte 
            for(int i = 0; i< readCount; i++){ //since we didnt break, we must have read 50 bytes
                if (buf[i] == '2'){ //every '2' we see 
                    buf[i] = 'B';//change it to an 'B'
                }
            }
            writeCount = write(fd2, buf, readCount); //write the 50 bytes read from source to dest2
            readCount = read(fds, buf, 100); //read 100 more bytes for the next iteration 
  
        }
        close(fds);//close source after read
        close(fd1);//close dest1 after write
        close(fd2);//close dest2 after write

	}
	return 0;
}

int main(){

    copytxt("source.txt", "destination1.txt", "destination2.txt");
	return 0;
}
