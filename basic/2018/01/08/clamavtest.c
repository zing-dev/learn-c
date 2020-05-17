//
// Created by zhangrongxiang on 2018/1/8 10:32
// File clamav
//

#include <stdlib.h>
#include <stdio.h>
#include "clamscan.h"

int main(int argc, char **argv) {

    struct cl_engine *engine;
    const char *virname;
    engine = get_clamav_engine();

    int ret = cl_scanfile(argv[0], &virname, NULL, engine, CL_SCAN_STDOPT);
    if (ret == CL_VIRUS) {
        printf("Virus detected: %s\n", virname);
    } else {
        printf("No virus detected.\n");
        if (ret != CL_CLEAN)
            printf("Error: %s\n", cl_strerror(ret));
    }
    return 0;
}