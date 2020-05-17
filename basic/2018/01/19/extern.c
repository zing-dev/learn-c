//
// Created by zhangrongxiang on 2018/1/19 15:42
// File extern
//

#include <string.h>
#include "extern.h"

extern int i1;
extern char name[20];

void ex() {
    i1 = 10;
}

void ex2() {
    strcpy(name, "hello world");
}