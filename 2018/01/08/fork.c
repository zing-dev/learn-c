//
// Created by zhangrongxiang on 2018/1/8 10:01
// File fork
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "clamscan.h"

#define P_NUM 5

int main(int argc, char **argv) {
    printf("-----------------Hello World----------------\n");
    pid_t pid[P_NUM];

    int i = 0;
    for (; i < P_NUM; ++i) {
        pid[i] = fork();
        if (pid[i] == 0) {
//            printf("1num %d child process\n", i + 1);
            struct cl_engine *engine;
            engine = get_clamav_engine();
            const char *virname;
            int ret = cl_scanfile(argv[0], &virname, NULL, engine, CL_SCAN_STDOPT);
            if (ret == CL_VIRUS) {
                printf("Virus detected: %s\n", virname);
            } else {
                printf("No virus detected.\n");
                if (ret != CL_CLEAN)
                    printf("Error: %s\n", cl_strerror(ret));
            }
            cl_engine_free(engine);
            sleep(2);
            exit(1);
        } else if (pid[i] == -1) {
            perror("fork err:");
            exit(-1);
        } else {
            wait(NULL);
            printf("parent process\n");
        }
    }
//    wait(NULL);
    return 0;
}