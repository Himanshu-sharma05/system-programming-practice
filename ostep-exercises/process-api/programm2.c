#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main(){
    printf("parent process pid : %d\n",getpid());
    int fd = open("output.txt",O_RDWR | O_APPEND | O_CREAT,0644);
    if(fd < 0){
        perror("Error opening the file output.txt \n");
        close(fd);
        exit(1);
    }
    printf("Calling fork...\n");
    int rc = fork();

    if(rc < 0){
        fprintf(stderr,"Fork failed \n");
        exit(1);
    }

    if(rc == 0){
        printf("Inside the child process, pid : %d\n",getpid());
        char *data = "Hello Parent from child! \n";
        ssize_t bytesWritten = write(fd,data,strlen(data));
        if(bytesWritten < 0){
            perror("Error writing into the file\n");
            exit(1);
        }
        printf("Wrote in the file %zd bytes \n",bytesWritten);
        close(fd);
    }
    else{
        printf("Inside the parent process, pid: %d\n",getpid());
        char *data = "Hello Child from parent! \n";
        ssize_t bytesWritten = write(fd,data,strlen(data));
        if(bytesWritten < 0){
            perror("Error writing into the file\n");
            exit(1);
        }
        printf("Wrote in the file %zd bytes \n",bytesWritten);
        close(fd);
    }

    return 0;
}
