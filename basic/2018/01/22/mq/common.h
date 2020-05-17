//
// Created by zhangrongxiang on 2018/1/22 14:14
// File common
//

#ifndef LEARC_C_COMMON_H
#define LEARC_C_COMMON_H
#ifndef COMMON_H_
#define COMMON_H_

#define QUEUE_NAME  "/tmp"
#define MAX_SIZE    1024
#define MSG_STOP    "exit"

#define CHECK(x) \
    do { \
        if (!(x)) { \
            fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
            perror(#x); \
            exit(-1); \
        } \
    } while (0) \


#endif /* #ifndef COMMON_H_ */
#endif //LEARC_C_COMMON_H
