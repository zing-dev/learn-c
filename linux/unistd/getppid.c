//
// Created by zing on 2021/3/25.
//
#include <stdio.h>
#include <unistd.h>

/* Get the process ID of the calling process's parent.  */
int main(){
    __pid_t pid = getpid();
    __pid_t ppid = getppid();
    printf("pid %d\n",pid);
    printf("ppid %d\n",ppid);
}