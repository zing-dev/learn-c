//
// Created by zhangrongxiang on 2018/1/25 16:28
// File volatile
//

#include <stdio.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    struct timeval start, end;
    gettimeofday(&start, NULL);  /*测试起始时间*/
    double timeuse;
    int  volatile j;
    for (j = 0; j < 1000000000; j++);
    gettimeofday(&end, NULL);   /*测试终止时间*/
    timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    timeuse /= 1000000;
    printf("运行时间为：%f\n", timeuse);
    return 0;

}