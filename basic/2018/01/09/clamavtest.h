//
// Created by zhangrongxiang on 2018/1/9 16:13
// File clamat
//

#ifndef LEARC_C_CLAMAT_TEST_H
#define LEARC_C_CLAMAT_TEST_H

#include <clamav.h>

struct cl_engine *get_clamav_engine();

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
#endif //LEARC_C_CLAMAT_TEST_H
