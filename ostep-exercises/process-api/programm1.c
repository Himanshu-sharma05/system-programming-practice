#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc,char *argv[]){
    int x = 100;
    printf("Before fork the parent : pid = %d : x = %d \n",getgid(),x);
    int rc = fork();
    if(rc < 0){
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc == 0){
        printf("Child process : pid = %d : initial x = %d\n",getpid(),x);
        x = 200;
        printf("Child process : pid = %d : after change x = %d\n",getpid(),x);
    }
    else{
        printf("Parent process : pid = %d : x = %d\n",getpid(),x);
        x = 300;
        printf("Parent changed the x = %d\n",x);
    }
    return 0;
}
