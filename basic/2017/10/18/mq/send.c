//
// Created by zhangrongxiang on 2017/10/18 10:43
// File send
//

#include "mq.h"

int main() {

    struct mq_attr mq_attr;
    mq_attr.mq_msgsize = MQ_MSGSIZE;
    mq_attr.mq_maxmsg = MQ_MAXMSG;
    int mqd;
    if (mq_unlink(NAME) == 0)
        fprintf(stdout, "Message queue %s removed from system.\n", NAME);
    mqd = mq_open(NAME, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, &mq_attr);
    if (mqd == -1) {
        perror("mq_open error");
    }
    char *string = "hello world";
    if (mq_send(mqd, string, mq_attr.mq_msgsize, 1) == -1) {
        perror("mq_send error");
        exit(-2);
    }
    return 0;
}