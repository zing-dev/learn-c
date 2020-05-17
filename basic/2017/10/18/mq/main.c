//
// Created by zhangrongxiang on 2017/10/18 10:10
// File main
//

#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    mqd_t mqd;

    /**
     * mqd_t mq_open(const char *name, int oflag);
     * mqd_t mq_open(const char *name, int oflag, mode_t mode,
     * struct mq_attr *attr);
     * Link with -lrt.
     */
    struct mq_attr mq_attr;
    mq_attr.mq_msgsize = 20;
    mq_attr.mq_maxmsg = 10;
    mqd = mq_open("/test", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, &mq_attr);
    if (mqd == -1) {
        perror("mq_open error");
    }
    char *string = "hello world";
    char get[sizeof(string)];
    /**
     *  int mq_send(mqd_t mqdes, const char *msg_ptr,
     *      size_t msg_len, unsigned int msg_prio);
     */
    if (mq_send(mqd, string, mq_attr.mq_msgsize, 1) == -1) {
        perror("mq_send error");
        exit(-2);
    }
    int prio = 1;
    if (mq_receive(mqd, get, mq_attr.mq_msgsize, &prio) == -1) {
        perror("mq_receive error");
        exit(-1);
    }
    puts(get);
    printf("%s\n", get);
    mq_close(mqd);
}