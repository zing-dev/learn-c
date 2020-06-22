//
// Created by zing on 6/8/2020.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <wait.h>

/* Clone the calling process, creating an exact copy.
   Return -1 for errors, 0 to the new process,
   and the process ID of the new process to the old process.  */
int main() {
    pid_t p = fork();
    if (p == -1) {
        perror("fork");
        return errno;
    }

    if (p == 0) {
        sleep(2);
        printf("I am new process\n");
        printf("pid %d\n",getpid());
        printf("ppid %d\n",getppid());
    } else {
        printf("I am old process\n");
        printf("pid %d\n",getpid());
        printf("ppid %d\n",getppid());
    }

    wait(&p);
    return EXIT_SUCCESS;
}