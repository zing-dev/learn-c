//
// Created by zhangrongxiang on 2018/1/4 12:15
// File 3
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <clamav.h>

#define PROCESS_NUM 2

struct cl_engine *get_clamav_engine();

void scan(char *argv);

struct cl_engine *engine;

int main(int argc, char **argv) {
    pid_t fpid[PROCESS_NUM];
    int i = 0;
    const char *virname;
    engine = get_clamav_engine();

//    if (argc > 1) {
//        for (i = 0; i < argc; ++i) {
//            int ret = cl_scanfile(argv[i], &virname, NULL, engine, CL_SCAN_STDOPT);
//            if (ret == CL_VIRUS) {
//                printf("Virus detected: %s\n", virname);
//            } else {
//                printf("No virus detected.\n");
//                if (ret != CL_CLEAN)
//                    printf("Error: %s\n", cl_strerror(ret));
//            }
//        }
//    }

//    for (i = 0; i < PROCESS_NUM; ++i) {
//        fpid[i] = fork();
//        if (fpid[i] < 0) {
//            printf("error in fork! \n");
//            perror("fork() error\n");
//        } else if (fpid[i] == 0) {
//            printf("i --> %d\n", i);
//            scan(argv[i]);
//            exit(0);
//        } else {
//            printf("主进程\n");
//        }
//    }
    cl_engine_free(engine);
    return 0;
}

void scan(char *argv) {
    int i = 0, ret = 0;
    char *result = NULL;
    const char *virname;
    ret = cl_scanfile(argv, &virname, NULL, engine, CL_SCAN_STDOPT);
    if (ret == CL_VIRUS) {
        printf("Virus detected: %s\n", virname);
    } else {
        printf("No virus detected.\n");
        if (ret != CL_CLEAN)
            printf("Error: %s\n", cl_strerror(ret));
    }
}

struct cl_engine *get_clamav_engine() {
    struct cl_engine *engine;
    unsigned int sigs = 0;
    int ret;

    if (ret = cl_init(CL_INIT_DEFAULT) != 0) {
        return ((struct cl_engine *) 1);
    }

    if (!(engine = cl_engine_new())) {
        return ((struct cl_engine *) 2);
    }

    ret = cl_load(cl_retdbdir(), engine, &sigs, CL_DB_STDOPT);

    if (ret != CL_SUCCESS) {
        cl_engine_free(engine);
        return ((struct cl_engine *) 3);
    }

    if ((ret = cl_engine_compile(engine)) != CL_SUCCESS) {
        cl_engine_free(engine);
        return ((struct cl_engine *) 4);
    }
    printf("---------------create engine -----------------\n");
    return engine;
}