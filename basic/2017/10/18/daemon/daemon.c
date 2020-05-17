//
// Created by zhangrongxiang on 2017/10/18 11:36
// File daemon
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

int main(void) {
    time_t t;
    int fd;

//    nochdir：=0将当前目录更改至“/”
//    noclose：=0将标准输入、标准输出、标准错误重定向至“/dev/null”
    if (daemon(0, 0) == -1)
        ERR_EXIT("daemon error");
    while (1) {
        fd = open("/home/vagrant/learn-c/2017/10/18/daemon/daemon.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd == -1)
            ERR_EXIT("open error");
        t = time(0);
        char *buf = asctime(localtime(&t));
        write(fd, buf, strlen(buf));
        close(fd);
        sleep(60);

    }
    return 0;
}