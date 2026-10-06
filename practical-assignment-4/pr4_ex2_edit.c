#include <stdio.h>
#include <unistd.h>
int main() {
    int pid;
    printf("I`m the original process with %d and ppid %d\n", getpid(), getppid());
    pid = fork();
    if(pid!=0){
            printf("I`m the parent process with pid %d and ppid %d\n", getpid(), getppid());
            printf("My child's pid is %d\n", pid);
    }
    else{     /*esli pid==0, this is child process*/
        int newPid;
        newPid = fork();


        if (newPid != 0){
            printf("I am the parent process yohoo, my PID is %d\n", getpid());
        }
        else{
            sleep(5);
            printf("I am the child process with PID %d and PPID %d\n", getpid(), getppid());
        }
    }
    printf("\n pid %d terminates\n", getpid());
    
    return 0;
}
