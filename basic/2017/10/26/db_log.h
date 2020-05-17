//
// Created by zhangrongxiang on 2017/10/26 13:50
// File db_log
//

#ifndef LEARN_C_DB_LOG_H
#define LEARN_C_DB_LOG_H

#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

static int isExistsCB(void *data, int argc, char **argv, char **azColName);

void dbCreateTable();

int isExists();

void dbCreateTable() {
    sqlite3 *db;
    char *zErrMsg = 0;
    /* Open database */
    int rc = sqlite3_open("log.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    char *sql = "DROP TABLE IF EXISTS DB_LOG;"\
         "CREATE TABLE DB_LOG("  \
         "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
         "CONTENT           TEXT    NOT NULL," \
         "LEVEL            INT     NOT NULL," \
         "CREATE_TIME      TIMESTAMP NOT NULL DEFAULT (datetime('now','localtime')));";
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
}

static int isExistsCB(void *data, int argc, char **argv, char **azColName) {
    int i;
    fprintf(stderr, "%s: ", (const char *) data);
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int isExists() {
    sqlite3 *db;
    const char *data = "Callback function called";
    char *zErrMsg = 0;
    /* Open database */
    int rc = sqlite3_open("log.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    /* Create SQL statement */
    char *sql = "select count(*)  from sqlite_master where type='table' and name = 'DB_LOG';";
    rc = sqlite3_exec(db, sql, isExistsCB, (void *) data, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);
    return 0;
}


#endif //LEARN_C_DB_LOG_H
