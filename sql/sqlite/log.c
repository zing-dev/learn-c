//
// Created by zhangrongxiang on 2017/10/26 15:26
// File log
//

#include "log.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *content[] = {
            "管理员登陆",
            "添加用户",
            "删除用户",
            "修改用户",
            "修改密码",
            "删除密码",
            "备份密码",
            "管理员退出"
    };
    createTable();
    int i;
#if 0
    DB_LOG db_log = {0};
    for (i = 0; i < 100; ++i) {
        db_log.level = i % 6;
        strcpy(db_log.content, *(content + rand() % 8));
        time(&db_log.time);
        insert(db_log);
        printf("已经完成%d个数据插入\n",i+1);
//        sleep(10);
    }
#endif
//    selectTable();
//    getLength();
    unsigned char *ptr = NULL;
    int len = 20;
    ptr = (unsigned char *) malloc(sizeof(DB_LOG) * len);
    getMoreLogs(ptr, &len);
    DB_LOG *db_log;

    for (i = 0; i < len; i++) {
        db_log = (DB_LOG *) (ptr + i * sizeof(DB_LOG));
        printf("%d--%s--%d--%d--\n", db_log->id, db_log->content, db_log->level, db_log->time);
    }
    return 0;
}