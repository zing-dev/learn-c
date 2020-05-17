//
// Created by zhangrongxiang on 2017/10/26 16:31
// File time
//

#include <stdio.h>
#include <time.h>

int main() {

    printf("%s\n", __TIME__);
    printf("%s\n", __TIMESTAMP__);

    struct tm *t = {0};
    time_t now;
    time(&now);
    printf("%d\n", now);

    t = localtime(&now);
    printf("%d\n", t->tm_year);
}