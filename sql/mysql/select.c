//
// Created by zhangrongxiang on 2017/8/29 14:20.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include <stdio.h>
#include <mysql/mysql.h>
#include "database.h"
int main()
{
    MYSQL *mysql;
    database_init_and_connect(mysql);
    MYSQL_RES *rs;
    MYSQL_ROW row;
    char *sql = "SELECT * FROM `stu`";
    if (mysql_real_query(mysql, sql, strlen(sql))) {// 如果失败
        ERROR_PRINT("%d: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(-1); // 表示失败
    }
    rs = mysql_store_result(mysql);
    printf("id\tname\tage\tqq\n");
    while ((row = mysql_fetch_row(rs))) // 打印结果集
        printf("%d\t%s\t%d\t%s\n", row[0], row[1],row[2],row[3]); // 第一，第二字段

    mysql_free_result(rs); // 释放结果集
    mysql_close(mysql); // 关闭链接

}