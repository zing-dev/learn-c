//
// Created by zhangrongxiang on 2017/9/25 17:09
//


/* time example */
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <unistd.h>

void print_time() {
    time_t timer;
    struct tm y2k = {0}, *info;
    double seconds;
    time(&timer);
    info = gmtime(&timer);
    info = localtime(&timer);
    y2k.tm_hour = 18;
    y2k.tm_min = 0;
    y2k.tm_sec = 0;
    y2k.tm_year = info->tm_year;
    y2k.tm_mon = info->tm_mon;
    y2k.tm_mday = info->tm_mday;
    seconds = difftime(mktime(&y2k), timer);
    if (seconds < 0)
        seconds += 3600 * 24;
    int h = (int) seconds / 3600;
    int m = (int) ((seconds - h * 3600) / 60);
    int s = (int) seconds % 60;
    printf("北京时间：%d年%d月%d日%d时%d分%d秒\n",
           info->tm_year + 1900,
           info->tm_mon + 1,
           info->tm_mday,
           info->tm_hour,
           info->tm_min,
           info->tm_sec
    );
    if ((int) seconds % 3600 == 0) {
        printf("还剩%d小时下班了!\n", h);
    } else {
        printf("还剩%d小时%d分钟%d秒下班了!\n", h, m, s);
    }
}

void main() {
    while (1) {
        print_time();
        sleep(2);
    }
}