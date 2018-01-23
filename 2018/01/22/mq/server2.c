//
// Created by zhangrongxiang on 2018/1/22 15:17
// File server2
//

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

#define SLN_IPC_MQ_MAXMSG 1024
#define SLN_IPC_MQ_MSGSIZE 10
#define SLN_IPC_MQ_NAME "/tmp"

int sln_ipc_mq_loop(void)
{
    mqd_t           mqd;
    struct mq_attr  setattr, attr;
    char            *recvbuf = NULL;
    unsigned int    prio;
    int             recvlen;

    setattr.mq_maxmsg = SLN_IPC_MQ_MAXMSG;
    setattr.mq_msgsize = SLN_IPC_MQ_MSGSIZE;
    setattr.mq_flags = 0;
    setattr.mq_curmsgs = 0;

    mqd = mq_open(SLN_IPC_MQ_NAME, O_RDWR | O_CREAT | O_EXCL, 0644, &setattr); //创建消息队列并设置消息队列属性
//    mqd = mq_open(SLN_IPC_MQ_NAME, O_CREAT | O_RDONLY, 0644, &setattr);

    if ((mqd < 0) && (errno != EEXIST)) {
        fprintf(stderr, "mq_open1: %s\n", strerror(errno));
        return -1;
    }

    if ((mqd < 0) && (errno == EEXIST)) { // 消息队列存在则打开
        mqd = mq_open(SLN_IPC_MQ_NAME, O_RDWR);
        if (mqd < 0) {
            fprintf(stderr, "mq_open2: %s\n", strerror(errno));
            return -1;
        }
    }

    if (mq_getattr(mqd, &attr) < 0) { //获取消息队列属性
        fprintf(stderr, "mq_getattr: %s\n", strerror(errno));
        return -1;
    }

    printf("flags: %ld, maxmsg: %ld, msgsize: %ld, curmsgs: %ld\n",
           attr.mq_flags, attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);

    recvbuf = malloc(attr.mq_msgsize); //为读取消息队列分配当前系统允许的每条消息的最大大小的内存空间
    if (NULL == recvbuf) {
        return -1;
    }

    for (;;) {
        recvlen = mq_receive(mqd, recvbuf, attr.mq_msgsize, &prio); //从消息队列中读取消息
        if (recvlen < 0) {
            fprintf(stderr, "mq_receive: %s\n", strerror(errno));
            continue;
        }
        printf("recvive length: %d, prio: %d, recvbuf: %s\n", recvlen, prio, recvbuf);
    }
}
int main(int argc, char **argv) {
    sln_ipc_mq_loop();
    return 0;
}