//
// Created by zhangrongxiang on 2017/10/16 18:32
// File sql
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h>


//https://dev.mysql.com/doc/refman/5.6/en/c-api-function-overview.html
int main(int argc, const char *argv[]) {
//    char *host = "192.168.33.13";
    char *host = "127.0.0.1";
    char *user = "root";
    char *password = "root";
    char *database = "fgap_config";
    int isUp = 0;
    MYSQL mysql;

    MYSQL_RES *rs;
    MYSQL_ROW row;

    if (mysql_init(&mysql) == NULL) {
        printf("mysql_init() : %s\n", mysql_error(&mysql));
        return -1;
    }

    /**
     * MYSQL *mysql_real_connect(
     *      MYSQL *mysql,
     *      const char *host,
     *      const char *user,
     *      const char *passwd,
     *      const char *db,
     *      unsigned int port,
     *      const char *unix_socket,
     *      unsigned long client_flag
     *      )
     */
    if (mysql_real_connect(&mysql, host, user, password, database, 0, NULL, 0) == NULL) {
        printf("mysql_real_connect() : %s\n", mysql_error(&mysql));
        return -1;
    }

    printf("connect success!!!\n");
    char *sql = "SELECT `value` FROM `anti_virus` WHERE `name` = 'status'";
    if (mysql_real_query(&mysql, sql, strlen(sql))) {
        printf("%d: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(-1);
    }
    rs = mysql_store_result(&mysql);
    while ((row = mysql_fetch_row(rs))) { // 打印结果集
        if (strcmp(row[0], "up") == 0) {
            isUp = 1;
        }
    }
    printf("virus is %d\n", isUp);
    mysql_free_result(rs); // 释放结果集
    mysql_close(&mysql); // 关闭链接

    return 0;
}
