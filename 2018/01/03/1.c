//
// Created by zhangrongxiang on 2018/1/3 14:53
// File 1
//


#include <stdio.h>
#include <clamav.h>

#define NO_VIRUS "NO_VIRUS"
#define FILE_SCAN_ERROR "FILE_SCAN_ERROR"

struct cl_engine *get_clamav_engine();

char *file_scan(char *filename, struct cl_engine *engine);

int main(int argc, char **argv) {
    int i = 0, ret;
    char *result = NULL;
    const char *virname;

    struct cl_engine *engine = get_clamav_engine();
    if (argc > 1) {
        for (i = 0; i < argc; ++i) {
            ret = cl_scanfile(argv[i], &virname, NULL, engine, CL_SCAN_STDOPT);
            if (ret == CL_VIRUS) {
                printf("Virus detected: %s\n", virname);
            } else {
                printf("No virus detected.\n");
                if (ret != CL_CLEAN)
                    printf("Error: %s\n", cl_strerror(ret));
            }

        }
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
    return engine;
}

char *file_scan(char *filename, struct cl_engine *engine) {
    char *return_string = malloc(100);
    int ret;
    const char *virname;

    ret = cl_scanfile(filename, &virname, NULL, engine, CL_SCAN_STDOPT);
    if (ret == CL_VIRUS) {
        strcpy(return_string, virname);
        return return_string;
    } else if (ret == CL_CLEAN) {
        strcpy(return_string, NO_VIRUS);
        return return_string;
    } else {
        strcpy(return_string, FILE_SCAN_ERROR);
        return return_string;
    }
}
