//
// Created by zhangrongxiang on 2017/10/31 15:11
// File pipe
//

#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<signal.h>

#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

/**
 * O_NONBLOCK disable：read调用阻塞，即进程暂停执行，一直等到有数据来到为止。
 * O_NONBLOCK enable：read调用返回-1，errno值为EAGAIN。
 *
 *
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    int pipefd[2];
    if (pipe(pipefd) == -1)
        ERR_EXIT("pipe error");

    pid_t pid;
    pid = fork();
    if (pid == -1)
        ERR_EXIT("fork error");

    if (pid == 0) {
        sleep(3);
        close(pipefd[0]);
        write(pipefd[1], "hello", 5);
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    }

    close(pipefd[1]);
    char buf[10] = {0};
    int flags = fcntl(pipefd[0], F_GETFL);
    fcntl(pipefd[0], F_SETFL, flags | O_NONBLOCK); //enable fd的O_NONBLOCK
    int ret = read(pipefd[0], buf, 10); //默认是disable fd的O_NONBLOCK
//    read error: Resource temporarily unavailable
    if (ret == -1) // 父进程不会阻塞，出错返回
        ERR_EXIT("read error");
    printf("buf=%s\n", buf);

    return 0;
}