//
// Created by zhangrongxiang on 2017/10/26 15:26
// File log
//

#include "log.h"
#include <unistd.h>
#include <string.h>

int main() {
    createTable();
#if 0
    int i;
    DB_LOG db_log = {0};
    for (i = 0; i < 10; ++i) {
        db_log.level = i % 6;
        strcpy(db_log.content, "今天是个好日子。。。。。");
        time(&db_log.time);
        insert(db_log);
        printf("已经完成%d个数据插入\n",i+1);
        sleep(10);
    }
#endif
    selectTable();
    return 0;
}