//
// Created by zhangrongxiang on 2018/3/1 17:36
// File conn3
//
#include <stdio.h>
#include <mysql/mysql.h>
#include <stdlib.h>
#include <string.h>

int main() {
    MYSQL *mysql = NULL;
//    const char *host = "192.168.33.13";
    const char *host = "localhost";
    const char *user = "root";
    const char *passwd = "root1";
    const char *db = "fgap_config";
    unsigned int port = 3306;
    const char *unix_socket = "/var/run/mysqld/mysqld.sock";

    mysql = mysql_init(mysql);
    if (mysql == NULL) {
        perror("mysql_init error ");
        exit(EXIT_FAILURE);
    }
    mysql = mysql_real_connect(mysql, host, user, passwd, db, port, unix_socket, 0);
    if (!mysql) {
        perror("mysql_real_connect error");
        exit(EXIT_FAILURE);
    } else {
        printf("mysql_real_connect success\n");
    }

    char sql[] = "select * from anti_virus";
//    mysql_real_query(mysql, sql, sizeof(sql));
    if (mysql_real_query(mysql, sql, (unsigned long) strlen(sql))) {
    } else {
        MYSQL_RES *rs = mysql_store_result(mysql);
        MYSQL_ROW row = NULL;
        printf("%-2s %-18s %-5s\n", "ID", "NAME", "VALUE"); // 第一，第二字段
        while ((row = mysql_fetch_row(rs))) { // 打印结果集
            printf("%-2s %-18s %-5s\n", row[0], row[1], row[2]); // 第一，第二字段
        }
    }
    return EXIT_SUCCESS;
}