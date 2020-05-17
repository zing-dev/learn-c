//
// Created by zhangrongxiang on 2017/10/18 11:17
// File main
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define ERR_EXIT(m) \
do\
{\
    perror(m);\
    exit(EXIT_FAILURE);\
}\
while (0);\


void creat_daemon(void);

void main(void) {
    time_t t;
    int fd;
    creat_daemon();
    while (1) {
        fd = open("daemon.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd == -1)
            ERR_EXIT("open error");
        t = time(0);
        char *buf = asctime(localtime(&t));
        write(fd, buf, strlen(buf));
        close(fd);
        sleep(60);

    }
}

/**
 * （1）在父进程中执行fork并exit推出；
 * （2）在子进程中调用setsid函数创建新的会话；
 * （3）在子进程中调用chdir函数，让根目录 ”/” 成为子进程的工作目录；
 * （4）在子进程中调用umask函数，设置进程的umask为0；
 * （5）在子进程中关闭任何不需要的文件描述符
 */
void creat_daemon(void) {
    pid_t pid;
    pid = fork();
    if (pid == -1)
        ERR_EXIT("fork error");
    if (pid > 0)
        exit(EXIT_SUCCESS);
    if (setsid() == -1)
        ERR_EXIT("SETSID ERROR");
    chdir("/");
    int i;
    for (i = 0; i < 3; ++i) {
        close(i);
        open("/dev/null", O_RDWR);
        dup(0);
        dup(0);
    }
    umask(0);
    return;
}