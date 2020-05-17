//
// Created by zhangrongxiang on 2017/10/26 15:19
// File 2
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

int main() {

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    /* 数据库创建或打开 */
    rc = sqlite3_open("test.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    char sql5[256];
    char *tname = "ttt";
    sprintf(sql5, "create table if not exists %s ("\
                    "id int not null," \
                    "name text not null);", tname);
    printf("%s\n", sql5);

    /* 创建表 */
    rc = sqlite3_exec(db, sql5, NULL, NULL, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    char *sql = "insert into ttt (id, name) values(22,'fuck')";
    rc = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table insert data successfully\n");
    }
    sqlite3_close(db);

}