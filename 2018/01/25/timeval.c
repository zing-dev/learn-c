//
// Created by zhangrongxiang on 2018/1/25 16:09
// File timeval
//

#include <stdio.h>
#include <sys/time.h>
#include <zconf.h>

int main(int argc, char *argv[]) {
    struct timeval start, end;
    gettimeofday(&start, NULL);  /*测试起始时间*/
    double timeuse;
    int j;
    for (j = 0; j < 100000; j++);
    gettimeofday(&end, NULL);   /*测试终止时间*/
    timeuse = 1.0 * 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    timeuse /= 1000000.0;
    printf("运行时间为：%.6f\n", timeuse);
    ////////////////////////////////////////////////////////////////////////
    printf("运行时间为: %.6f\n", (end.tv_usec - start.tv_usec) * 1.0 / 1000000 + end.tv_sec - start.tv_sec);
    return 0;

}