
#include <stdlib.h>
#include <stdio.h>
#include <mysql/mysql.h>
#ifndef MAX_SQL_LEN
#define MAX_SQL_LEN 256
#endif

extern int database_init_and_connect(MYSQL *mysql);

