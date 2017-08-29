//
// Created by zhangrongxiang on 2017/8/29 14:21.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include <database.h>

int database_init_and_connect(MYSQL *mysql)
{
    const char *host = "localhost";
    const char *user = "root";
    const char *pass = "root";
    const char *db   = "demo";

    mysql_init(mysql);
    if (!mysql_real_connect(mysql, host, user, pass, db, 0, NULL, 0))
    {
        printf("%s", mysql_error(mysql));
        return -1;
    }
    return 0;
}
