//
// Created by zhangrongxiang on 2018/1/9 16:12
// File pthread
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "clamavtest.h"

int *thread(void *arg) {
    struct cl_engine *engine = (struct cl_engine *) arg;
    const char *virname;
    int ret = cl_scanfile("./pthread.c", &virname, NULL, engine, CL_SCAN_STDOPT);
    printf("thread id is %d  --> %d.\n", pthread_self(), ret);
    if (ret == CL_VIRUS) {
        printf("%s Virus detected: %s\n", "./pthread.c", virname);
    } else {
        printf("No virus detected.\n");
        if (ret != CL_CLEAN)
            printf("Error: %s\n", cl_strerror(ret));
    }
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t id;
    struct cl_engine *engine;
    engine = get_clamav_engine();

    printf("Main thread id is %d \n", pthread_self());
    int i = 0;
    for (; i < 5; ++i) {
        if (!pthread_create(&id, NULL, (void *) thread, engine)) {
            printf("succeed!\n");
        } else {
            printf("Fail to Create Thread");
        }
    }
    return 0;
}