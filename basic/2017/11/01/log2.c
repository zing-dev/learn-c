//
// Created by zhangrongxiang on 2017/11/1 14:17
// File log2
//

#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    f = fopen("not_here", "r");
    if (!f)
//        Nov  1 14:20:32 debian log2.out: oops - No such file or directory/n
        //  --->>  /var/log/syslog
//        syslog(LOG_ERR | LOG_USER, "oops - %m \n");
//        syslog(LOG_WARNING | LOG_USER, "oops - %m \n");
//        syslog(LOG_CRIT | LOG_USER, "oops - %m \n");
//        syslog(LOG_ALERT | LOG_USER, "oops - %m \n");
        syslog(LOG_EMERG | LOG_USER, "oops - %m \n");
    exit(0);
}