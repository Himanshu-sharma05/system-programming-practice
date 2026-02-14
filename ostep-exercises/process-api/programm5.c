#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    printf("Starting the programm....\n");
    int rc = fork();
    if(rc < 0){
        fprintf(stderr,"Fork failed! \n");
        exit(1);
    }
    else if(rc == 0){
        printf("Inside the child process \n");
        int result = wait(NULL);
        if(result == -1){
            printf("Wait failed\n");
        }

    }
    else{
        int status;
        printf("Inside the parent \n");
        pid_t pid = wait(&status);
        printf("The program exited with status %d and pid %d",status,pid);
    }
    return 0;
}