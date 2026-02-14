#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    printf("Starting the programm with pid : %d .....\n",getpid());
    int fd[2];
    char buffer;
    if(pipe(fd) < 0){
        fprintf(stderr,"Pipe failed! \n");
        exit(1);
    }
    int rc = fork();
    if(rc < 0){
        fprintf(stderr,"Fork failed!");
        exit(1);
    }
    else if(rc == 0){
        printf("hello!\n");
        write(fd[1],"x",1);
        close(fd[0]);
        close(fd[1]);
    }
    else{
        read(fd[0],&buffer,1);
        printf("goodbye!\n");
        close(fd[0]);
        close(fd[1]);
    }
    return 0;
}