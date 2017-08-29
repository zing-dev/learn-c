#include<stdio.h>
#include<mysql/mysql.h>


int main(int argc, const char *argv[])
{
    MYSQL mysql;
    if (mysql_init(&mysql) == NULL) {
        printf("mysql_init() : %s\n", mysql_error(&mysql));
        return -1;
    }

    if (mysql_real_connect(&mysql, argv[1], argv[2], argv[3], "demo", 0, NULL, 0) == NULL) {
        printf("mysql_real_connect() : %s\n", mysql_error(&mysql));
        return -1;
    }

    printf("connect success!!!\n");
    return 0;
}
