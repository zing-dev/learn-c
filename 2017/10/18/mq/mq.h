//
// Created by zhangrongxiang on 2017/10/18 10:42
// File mq
//

#ifndef LEARN_C_MQ_H
#define LEARN_C_MQ_H

#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MQ_MSGSIZE 20
#define MQ_MAXMSG 10
#define NAME "/test"

#endif //LEARN_C_MQ_H
