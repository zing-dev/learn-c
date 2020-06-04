//
// Created by zing on 6/4/2020.
//
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int test() {
    int pipefd[2] = {0};
    int i = pipe(pipefd);
    char buf;

    if (i == -1) {
        perror("pipe");
        return errno;
    }
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return errno;
    }

    if (pid == 0) {    /* Child reads from pipe */
        printf("===============child================\n");
        close(pipefd[1]);          /* Close unused write end */
        while (read(pipefd[0], &buf, 1) > 0)
            write(STDOUT_FILENO, &buf, 1);

        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
    } else {            /* Parent writes argv[1] to pipe */
        printf("-----------------parent---------------------");
        close(pipefd[0]);          /* Close unused read end */
        char *str = "hello from parent";
        write(pipefd[1], str, strlen(str));
        close(pipefd[1]);          /* Reader will see EOF */
        wait(NULL);                /* Wait for child */
    }
    sleep(10);
    return 0;
}

int main(int argc, char *argv[]) {
    int pipefd[2];
    pid_t cpid;
    char buf;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {    /* Child reads from pipe */
        close(pipefd[1]);          /* Close unused write end */

        while (read(pipefd[0], &buf, 1) > 0) {
            write(STDOUT_FILENO, &buf, 1);
        }
        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);

    } else {            /* Parent writes argv[1] to pipe */
        close(pipefd[0]);          /* Close unused read end */
        write(pipefd[1], argv[1], strlen(argv[1]));
        close(pipefd[1]);          /* Reader will see EOF */
        wait(NULL);                /* Wait for child */
        exit(EXIT_SUCCESS);
    }
}