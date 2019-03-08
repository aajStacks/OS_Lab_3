//Author@ Mohammed Hossain
//Task_3_Parent_Prcs
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){
    int child1 = fork();
    if(child1 == 0){
        //what child1 should do
        char* argv[1]; 
        argv[0]= NULL;
        execvp("./Prcs_P1", &argv[0]);
        printf("EXECV Failed\n");
    }
    else{
        //what the parent process should do
        waitpid(child1, &child1, 0); 

        int child2 = fork();
        if(child2 == 0){
            //what child2 should do
            char* argv[1]; 
            argv[0]= NULL;
            execvp("./Prcs_P2", &argv[0]);
            printf("EXECV Failed\n");
        }  
        else{
            waitpid(child2, &child2, 0); 
        }
    }
    return 0;
}
