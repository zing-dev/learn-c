//
// Created by zhangrongxiang on 2018/1/22 11:32
// File 2
//


#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <zconf.h>
#include <clamav.h>

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
int randNum(){
    srand((unsigned int) time(0));
    return rand() % 2 == 0;
}
struct cl_engine *engine;

int main(){
    if (randNum()){
        engine = get_clamav_engine();
    }

    if (engine == NULL){
        printf("%s\n"),"engine null";
    } else{
        sleep(20);
    }
    cl_engine_free(engine);
    return 0;
}