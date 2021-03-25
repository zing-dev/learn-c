//
// Created by zing on 6/8/2020.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <wait.h>
#include <fcntl.h>
#include <string.h>

void test_fork() {
    pid_t p = fork();
    if (p == -1) {
        perror("fork");
        return;
    }

    if (p == 0) {
        sleep(1);
        printf("I am new process\n");
        printf("pid %d\n", getpid());
        printf("ppid %d\n", getppid());
    } else {
        printf("I am old process\n");
        printf("pid %d\n", getpid());
        printf("ppid %d\n", getppid());
    }
    printf("parent and child all run here\n");
    wait(&p);
}

void read_file() {
    pid_t pid;
    int fd;
    int i = 1;
    char *s1 = "hello";
    char *s2 = "world";
    char *s3 = "cccccc";

    if (remove("test.txt") == -1) {
        if (errno == ENOENT) {
            printf("remove ok\n");
        } else {
            perror("remove");
            return;
        }
    }
    if ((fd = open("test.txt", O_RDWR | O_CREAT, 0644)) == -1) {
        perror("parent open");
        return;
    }
    if (write(fd, s1, strlen(s1)) == -1) {
        perror("parent write");
        return;
    }
    if (write(fd, s3, strlen(s3)) == -1) {
        perror("parent write");
        return;
    }
    if ((pid = fork()) == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {
        i = 2;
        printf("in child process\n");
        printf("i = %d\n", i);
        if (write(fd, s2, strlen(s2)) == -1) {
            perror("child write");
            return;
        }
    } else {
        sleep(1);
        printf("in parent process\n");
        printf("i = %d \n", i);
        if (write(fd, s3, strlen(s3) == -1)) {
            perror("parent write");
            return;
        }
    }
    wait(&pid);
    printf("over...\n");
}

/* Clone the calling process, creating an exact copy.
   Return -1 for errors, 0 to the new process,
   and the process ID of the new process to the old process.  */
int main() {
    //test_fork();
    read_file();
    return EXIT_SUCCESS;
}