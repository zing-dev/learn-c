//
// Created by zing on 6/8/2020.
//

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/* Clone the calling process, but without copying the whole address space.
   The calling process is suspended until the new process exits or is
   replaced by a call to `execve'.  Return -1 for errors, 0 to the new process,
   and the process ID of the new process to the old process.  */

void test_vfork() {
    pid_t p = vfork();
    if (p == -1) {
        perror("vfork");
        return;
    }

    if (p == 0) {
        printf("I am new process\n");
        printf("pid %d\n", getpid());
        printf("ppid %d\n", getppid());
    } else {
        printf("I am old process\n");
        printf("pid %d\n", getpid());
        printf("ppid %d\n", getppid());
    }
}
int glob = 6;

void test_vfork2(){
    int var;
    pid_t pid;
    var = 88;
    printf("parent start glob %d var %d\n",glob,var);
    if ((pid = vfork()) == -1){
        perror("vfork");
        return;
    } else if (pid == 0){
        printf("child glob %d var %d\n",glob,var);
        glob++;
        var++;
        printf("child glob %d var %d\n",glob,var);
        _exit(0);
    } else{
        printf("parent end glob %d var %d\n",glob,var);
    }
}
int main() {
    test_vfork2();
    return EXIT_SUCCESS;
}