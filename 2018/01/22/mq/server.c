//
// Created by zhangrongxiang on 2018/1/22 14:13
// File server
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>
#include <zconf.h>

#include "common.h"

int main(int argc, char **argv) {
    mqd_t mq;
    struct mq_attr attr,mqAttr;
    char buffer[MAX_SIZE + 1];
    int must_stop = 0;

    /* initialize the queue attributes */
//    long    mq_flags //消息队列的标志：0或O_NONBLOCK,用来表示是否阻塞
//    long    mq_maxmsg  //消息队列的最大消息数
//    long    mq_msgsize  //消息队列中每个消息的最大字节数
//    long    mq_curmsgs  //消息队列中当前的消息数目
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;

    /* create the message queue */
    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, 0644, &attr);
    CHECK((mqd_t) - 1 != mq);

    do {
        ssize_t bytes_read;

        /* receive the message */
        sleep(2);
        bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
        CHECK(bytes_read >= 0);

        buffer[bytes_read] = '\0';
        if (!strncmp(buffer, MSG_STOP, strlen(MSG_STOP))) {
            must_stop = 1;
        } else {
            printf("Received: %s\n", buffer);
            if (mq_getattr(mq, &mqAttr) < 0) { //获取消息队列属性
                fprintf(stderr, "mq_getattr: %s\n", strerror(errno));
                return -1;
            }

            printf("flags: %ld, maxmsg: %ld, msgsize: %ld, curmsgs: %ld\n",
                   mqAttr.mq_flags, mqAttr.mq_maxmsg, mqAttr.mq_msgsize, mqAttr.mq_curmsgs);
        }
    } while (!must_stop);

    /* cleanup */
    CHECK((mqd_t) - 1 != mq_close(mq));
    CHECK((mqd_t) - 1 != mq_unlink(QUEUE_NAME));

    return 0;
}