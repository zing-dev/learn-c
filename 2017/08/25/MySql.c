//
// Created by zhangrxiang on 17-8-25.
//


#include <stdio.h>
#include <mysql/mysql.h>

int database_init_and_connect(MYSQL *mysql)
{
    const char *host = "localhost";
    const char *user = "root";
    const char *pass = "root";
    const char *db   = "fgap_config";

    mysql_init(mysql);
    if (!mysql_real_connect(mysql, host, user, pass, db, 0, NULL, 0))
    {
        printf("%s", mysql_error(mysql));
        return -1;
    }
    else{}
    printf("connect success .... ");
    return 0;
}

int main()
{
    MYSQL *mysql;
    database_init_and_connect(mysql);
}