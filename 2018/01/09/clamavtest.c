//
// Created by zhangrongxiang on 2018/1/9 15:48
// File clamavtest
//
#include <stdio.h>
#include <clamav.h>
#include <stdlib.h>
#include <unistd.h>

void scan(char **argv);

int main(int argc, char **argv) {
    pid_t pid;
    int i = 0;
    for (; i < 5; ++i) {
        pid = fork();
        if (pid == -1) {
            perror("fork error");
            exit(0);
        } else if (pid == 0) {
            scan(argv);
            exit(0);
        } else {
        }
    }
    return 0;
}

/**
 * 内存溢出
 * @param argv
 */
void scan(char **argv) {
    struct cl_engine *engine;
    unsigned int sigs = 0;
    const char *virname;
    int ret;

    if (ret = cl_init(CL_INIT_DEFAULT) != 0) {
        perror("cl_init error");
        exit(0);
    }

    if (!(engine = cl_engine_new())) {
        perror("cl_engine_new error");
        exit(0);
    }

    ret = cl_load(cl_retdbdir(), engine, &sigs, CL_DB_STDOPT);

    if (ret != CL_SUCCESS) {
        cl_engine_free(engine);
        perror("cl_init error");
        exit(0);
    }

    if ((ret = cl_engine_compile(engine)) != CL_SUCCESS) {
        cl_engine_free(engine);
        perror("cl_engine_free error");
        exit(0);
    }
    ret = cl_scanfile(argv[0], &virname, NULL, engine, CL_SCAN_STDOPT);
    if (ret == CL_VIRUS) {
        printf("%s Virus detected: %s\n", argv[0], virname);
    } else {
        printf("No virus detected.\n");
        if (ret != CL_CLEAN)
            printf("Error: %s\n", cl_strerror(ret));
    }
    cl_engine_free(engine);
}
