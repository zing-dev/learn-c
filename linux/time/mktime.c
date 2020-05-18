//
// Created by zing on 5/18/2020.
//

#include <time.h>
#include <stdio.h>
#include <unistd.h>

//struct tm
//{
//    int tm_sec;			/* Seconds.	[0-60] (1 leap second) */
//    int tm_min;			/* Minutes.	[0-59] */
//    int tm_hour;			/* Hours.	[0-23] */
//    int tm_mday;			/* Day.		[1-31] */
//    int tm_mon;			/* Month.	[0-11] */
//    int tm_year;			/* Year	- 1900.  */
//    int tm_wday;			/* Day of week.	[0-6] */
//    int tm_yday;			/* Days in year.[0-365]	*/
//    int tm_isdst;			/* DST.		[-1/0/1]*/
//}
int main(int argc, char *argv[]) {
    int i = 0;
    while (i++ < 100) {
        time_t rawtime;
        struct tm *timeinfo;
        const char *weekday[] = {"周日", "周一", "周二", "周三", "周四", "周五", "周六"};
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        mktime(timeinfo);
        printf("%s %d-%02d-%02d %d:%02d:%02d\n",
               weekday[timeinfo->tm_wday],
               timeinfo->tm_year + 1900,
               timeinfo->tm_mon + 1,
               timeinfo->tm_mday,
               timeinfo->tm_hour,
               timeinfo->tm_min,
               timeinfo->tm_sec);
        sleep(1);
    }
    return 0;
}
