//
// Created by zhangrxiang on 17-8-26.
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>
#include <fcntl.h>
#include <errno.h>
#include<sys/stat.h>

typedef unsigned int uint_t;

int main(int argc, char *argv[]) {
    int c, flags;
    mqd_t mqd;
    ssize_t n;
    uint_t prio;
    void *buff;
    struct mq_attr attr;

    flags = O_RDONLY;
    while ((c = getopt(argc, argv, "n")) != -1) {
        switch (c) {
            case 'n':
                flags |= O_NONBLOCK;  //设置为非阻塞
                break;
        }
    }
    if (optind != argc - 1) {
        printf("usage: mqreceive [-n] <name>");
        exit(0);
    }
    mqd = mq_open(argv[optind], flags);
    mq_getattr(mqd, &attr);
    buff = malloc(attr.mq_msgsize);
    if ((n = mq_receive(mqd, buff, attr.mq_msgsize, &prio)) == -1) {
        perror("mq_receive error: ");
        exit(-1);
    }
    printf("read %ld bytes,priority = %u\n", (long) n, prio);
    exit(0);
}