#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
int main(){
    printf("Starting the program ... \n");
    int rc = fork();
    if(rc<0){
        fprintf(stderr,"Fork failed!");
        exit(1);
    }
    else if(rc == 0){
        printf("Inside the child process... \n");
        char *args[3];
        args[0] = strdup("ls");
        args[1] = strdup("-a");
        args[2] = NULL;
        execvp("ls",args);
        printf("ls command failed");
        exit(1);
    }
    else{
        printf("Inside the parent process... \n");
        wait(NULL);
    }
    return 0;
}
