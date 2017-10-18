//
// Created by zhangrongxiang on 2017/10/18 10:44
// File recv
//

#include "mq.h"

int main() {
    struct mq_attr mq_attr;
    mq_attr.mq_msgsize = MQ_MSGSIZE;
    mq_attr.mq_maxmsg = MQ_MAXMSG;
    int mqd;
    char get[MQ_MSGSIZE];
    mqd = mq_open(NAME, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, &mq_attr);
    if (mqd == -1) {
        perror("mq_open error");
    }
    int prio = 1;
    if (mq_receive(mqd, get, mq_attr.mq_msgsize, &prio) == -1) {
        perror("mq_receive error");
        exit(-1);
    }
    puts(get);
    mq_close(mqd);
    return 0;
}