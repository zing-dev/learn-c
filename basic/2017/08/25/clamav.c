//
// Created by zhangrongxiang on 2017/8/25 10:29.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <clamav.h>
#include <unistd.h>

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
    return engine;
}

char *file_scan(char *filename, struct cl_engine *engine) {
    char *return_string = malloc(100);
    int ret;
    const char *virname;
    const char *no_vir = "NO Virus detected";
    const char *scan_err = "file scan error";

    ret = cl_scanfile(filename, &virname, NULL, engine, CL_SCAN_STDOPT);

    if (ret == CL_VIRUS) {
        strcpy(return_string, virname);
        return return_string;
    } else if (ret == CL_CLEAN) {
        strcpy(return_string, no_vir);
        return return_string;
    } else {
        strcpy(return_string, scan_err);
        return return_string;
    }
}

int main() {
    struct cl_engine *engine = get_clamav_engine();
    printf("%d\n", (unsigned int) engine);
    char *result = file_scan("clamav.c", engine);
    sleep(5);
    printf("result:%s\n", result);
    cl_engine_free(engine);
    return 0;
}