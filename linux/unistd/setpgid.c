//
// Created by zing on 2021/3/25.
//

#include <stdio.h>
#include <unistd.h>

/* Set the process group ID of the process matching PID to PGID.
   If PID is zero, the current process's process group ID is set.
   If PGID is zero, the process ID of the process is used.  */
//extern int setpgid (__pid_t __pid, __pid_t __pgid) __THROW;
int main() {
    int pid = getpid();
    int ppid = getppid();
    int pgrp = getpgrp();
    int pgid = getpgid(0);
    printf("parent %d %d %d %d\n", pid, ppid, pgrp, pgid);
    if (fork() == 0) {
        int cpid = getpid();
        int cppid = getppid();
        int cpgrp = getpgrp();
        int cpgid = getpgid(0);
        printf("child before %d %d %d %d\n", cpid, cppid, cpgrp, cpgid);
        setpgid(cpid, pgid);
        cpid = getpid();
        cppid = getppid();
        cpgrp = getpgrp();
        cpgid = getpgid(0);
        printf("child after %d %d %d %d\n", cpid, cppid, cpgrp, cpgid);
    }
    if (fork() == 0) {
        int cpid = getpid();
        int cppid = getppid();
        int cpgrp = getpgrp();
        int cpgid = getpgid(0);
        printf("child2 before %d %d %d %d\n", cpid, cppid, cpgrp, cpgid);
        setpgid(cpgid, 1000);
        cpid = getpid();
        cppid = getppid();
        cpgrp = getpgrp();
        cpgid = getpgid(0);
        printf("child2 after %d %d %d %d\n", cpid, cppid, cpgrp, cpgid);
    }
}