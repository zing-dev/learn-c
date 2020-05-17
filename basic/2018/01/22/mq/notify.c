//
// Created by zhangrongxiang on 2018/1/22 15:06
// File notify
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

typedef unsigned int uint_t;

volatile sig_atomic_t mqflag;  //全局变量，检查信号的产生
static void sig_usr1(int);

int main(int argc, char *argv[]) {
    mqd_t mqd;
    void *buff;
    ssize_t n;
    sigset_t zeromask, newmask, oldmask;
    struct mq_attr attr;
    struct sigevent sigev;
    if (argc != 2) {
        printf("usage :mqnotify <name>\n");
        exit(0);
    }
    mqd = mq_open(argv[1], O_RDONLY);
    mq_getattr(mqd, &attr);
    buff = malloc(attr.mq_msgsize);
    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigemptyset(&oldmask);
    sigaddset(&newmask, SIGUSR1);
    signal(SIGUSR1, sig_usr1);
    sigev.sigev_notify = SIGEV_SIGNAL;
    sigev.sigev_signo = SIGUSR1;
    if (mq_notify(mqd, &sigev) == -1) {
        perror("mq_notify error");
        exit(-1);
    }
    for (;;) {
        sigprocmask(SIG_BLOCK, &newmask, &oldmask);
        while (mqflag == 0)
            sigsuspend(&zeromask); //挂起，等待
        mqflag = 0;
        mq_notify(mqd, &sigev);
        n = mq_receive(mqd, buff, attr.mq_msgsize, NULL);
        printf("read %ld bytes\n", (long) n);
        sigprocmask(SIG_UNBLOCK, &newmask, NULL);
    }
    exit(0);
}

static void sig_usr1(int signo) {
    mqflag = 1;
    return;
}