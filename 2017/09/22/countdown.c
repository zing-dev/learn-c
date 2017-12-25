//
// Created by zhangrongxiang on 2017/9/22 15:09
//


/* time example */
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */

int main() {
    time_t timer;
    struct tm y2k = {0}, *info;
    double seconds;
    time(&timer);
    info = gmtime(&timer);
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
    printf("还剩%d小时%d分钟%d秒下班了!\n", h, m, s);
    return 0;
}