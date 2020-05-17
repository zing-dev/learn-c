//
// Created by zhangrongxiang on 2017/11/20 10:50
// File 1
//

#include <stdio.h>

#define name "zing"
#define p() \
    int i = 10 ;\
    printf("name is %s -->  i is %d\n",name,i);

#define create() \
    int test() {\
        return 10;\
    } \
    char * getStr(){\
        return "fuck";\
    }

int main() {
    p();
    create();
    int ii = test();
    printf("%d\n", i);
    printf("%s\n", getStr());
}