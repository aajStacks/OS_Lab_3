//Author@ Mohammed Hossain
//Task_3_p2
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char * argv[]){
    int child = fork();
    if(child == 0){
        //what child should do
        printf("child PID: %d\n", getpid()); //print child pid
        /*swaps the content of the arguements to allow for -la to be the first
         * second argument followed by the directory to be listed*/
        char * dir = argv[1]; 
        argv[1] = "-la";
        argv[2] = dir;
        argv[3] = NULL; //last element in the array is null
        execvp("ls", &argv[0]);
        printf("EXECVP Failed\n");
    }
    else{
        //what the parent process should do
        waitpid(child, &child, 0); 
    }
    return 0;
}
