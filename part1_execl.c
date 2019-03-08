//Author@ Mohammed Hossain
//Task_3_p1
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){
    int child = fork();
    if(child == 0){
        //what child should do
        printf("child PID: %d\n", getpid()); //print child pid
        execl("/bin/date","date", NULL);
        printf("EXECV Failed\n");
    }
    else{
        //what the parent process should do
        waitpid(child, &child, 0); 
    }
    return 0;
}
