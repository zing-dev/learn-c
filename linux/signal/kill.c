//
// Created by zing on 6/22/2020.
//

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return errno;
    }
    if (pid == 0) {
        printf("child process %d\n", getpid());
        sleep(10);
    } else {
        printf("parent process\n");
        sleep(2);
        int ret = kill(pid, SIGKILL);
        if (ret == -1) {
            perror("kill");
            return errno;
        }
        printf("kill %d\n", pid);
        printf("%d\n", ret);
    }
    return 0;
}
