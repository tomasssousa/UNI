#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    pid_t pid;
    
    pid = fork();
    if (pid > 0){
        printf("pid do pai = %d\n", (int) getpid());
        printf("pid do filho = %d\n", pid);
    }
    else if (pid == 0){
        printf("pid do pai = %d\n", pid);
        printf("pid do filho = %d\n", (int) getpid());
    }
    
    pid = fork();
    if (pid > 0){
        printf("pid do pai = %d\n", (int) getpid());
        printf("pid do filho = %d\n", pid);
    }
    else if (pid == 0){
        printf("pid do pai = %d\n", pid);
        printf("pid do filho = %d\n", (int) getpid());
    }

    pid = fork();
    if (pid > 0){
        printf("pid do pai = %d\n", (int) getpid());
        printf("pid do filho = %d\n", pid);
    }
    else if (pid == 0){
        printf("pid do pai = %d\n", pid);
        printf("pid do filho = %d\n", (int) getpid());
    }
    exit(EXIT_SUCCESS);
}