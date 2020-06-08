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

int main() {
    pid_t p = vfork();
    if (p == -1) {
        perror("vfork");
        return errno;
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
    return EXIT_SUCCESS;
}