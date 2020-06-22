//
// Created by zing on 6/22/2020.
//

#include <csapp.h>

void fork_test2() {
    pid_t pid = fork();
    int status;
    printf("pid %d\n",pid);
    if (pid == 0) {
        sleep(2);
        printf("child process %d\n",getpid());
    } else if (pid == -1) {
        perror("fork");
    } else{
        printf("parent process %d\n",getpid());
    }
    printf("wait %d\n",wait(&status));
    printf("wait %d\n",status);
}

void fork_test() {
    pid_t pid = Fork();
    int status;
    printf("%d\n", pid);
    if (pid == 0) {
        Sleep(2);
        printf("子进程\n");
    } else if (pid == -1) {
        printf("err\n");
    } else {
        printf("父进程\n");
    }
    Wait(&status);
}

int main(int argc, char *argv[]) {
    fork_test();
    fork_test2();
    return 0;
}
