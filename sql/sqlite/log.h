//
// Created by zhangrongxiang on 2017/10/26 15:26
// File log
//

#ifndef LEARN_C_LOG_H
#define LEARN_C_LOG_H

#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

sqlite3 *db;
char *zErrMsg = 0;
int rc;

typedef struct _DB_LOG_TAG {
    char name[16];
    int priority;
} DB_LOG_TAG;

typedef struct LOG {
    int id;
    char content[512];
    int level;
    time_t time;
} DB_LOG;

//调试级别
#define DB_LEVEL_ERROR    0
#define DB_LEVEL_WARN    1
#define DB_LEVEL_NOTE    2
#define DB_LEVEL_INFO    3
#define DB_LEVEL_DEBUG    4
#define DB_LEVEL_BASE    5    //always logging less than this value.
DB_LOG_TAG db_log_tag[DB_LEVEL_BASE + 1] = {
        {"ERROR",   DB_LEVEL_ERROR,},
        {"WARN",    DB_LEVEL_WARN,},
        {"NOTE",    DB_LEVEL_NOTE,},
        {"INFO",    DB_LEVEL_INFO,},
        {"DEBUG",   DB_LEVEL_DEBUG,},
        {"INVALID", DB_LEVEL_BASE},
};

void createTable();

void insert(DB_LOG db_log);

int selectTable();

int getLength();

int getMoreLogs(void *data, int *num);

void createTable() {

    rc = sqlite3_open("test.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    char *sql = "CREATE TABLE IF NOT EXISTS DB_LOG("\
         "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
         "CONTENT           TEXT    NOT NULL," \
         "LEVEL            INT     NOT NULL," \
         "CREATE_TIME      INTEGER NOT NULL);";
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
}

void insert(DB_LOG db_log) {
    char sql[100];
    sprintf(sql, "INSERT INTO DB_LOG (CONTENT,LEVEL,CREATE_TIME) VALUES('%s',%d, %d)", db_log.content, db_log.level,
            (int) db_log.time);
    rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
//        fprintf(stdout, "INSERT INTO DB_LOG successfully\n");
    }
}

int selectTable() {
    int nrow = 0, ncolumn = 0;
    char **azResult = 0;
    int i = 0;
    int j = 0;
    char sql[100];
    char *zErrMsg;
    int db_len = getLength();
    if (db_len > 50) {
        db_len = 20;
    }
    printf("------%d-------\n", db_len);
    sprintf(sql, "SELECT * FROM DB_LOG  order  by id desc  limit %d", db_len);
    if (SQLITE_OK != sqlite3_get_table(db, sql, &azResult, &nrow, &ncolumn, &zErrMsg)) {
        printf("operate failed: %s\n", zErrMsg);
    }
    printf("row:%d column = %d\n", nrow, ncolumn);
    DB_LOG db_log[nrow];
    memset(db_log, 0, sizeof(db_log[50]));
    printf("The result of querying is :\n");
    for (i = 0; i < (nrow + 1) * ncolumn; i++) {
        if (i % ncolumn == 0 && i >= ncolumn) {
            db_log[j].id = atoi(azResult[i]);
            strcpy(db_log[j].content, azResult[i + 1]);
            db_log[j].level = atoi(azResult[i + 2]);
            db_log[j].time = (time_t) atoi(azResult[i + 3]);
            j++;
        }
    }
    for (j = 0; j < nrow; ++j) {
        char buffer[20] = {0};
        char *level = db_log_tag[db_log[j].level].name;
        struct tm *times = localtime(&db_log[j].time);
        strftime(buffer, 20, "%x - %I:%M%p", times);
        printf("id : %d, content : %s , level %s, time %d ---> %s\n",
               db_log[j].id, db_log[j].content, level, times->tm_year + 1900, buffer);
    }
    sqlite3_free_table(azResult);
    return 0;
}

int getLength() {
    int nrow = 0, ncolumn = 0;
    char **azResult = 0;
    int i = 0;
    int j = 0;
    char *sql;
    char *zErrMsg;
    sql = "SELECT count(*) FROM DB_LOG";
    if (SQLITE_OK != sqlite3_get_table(db, sql, &azResult, &nrow, &ncolumn, &zErrMsg)) {
        printf("operate failed: %s\n", zErrMsg);
    }
    sqlite3_free_table(azResult);
    return atoi(azResult[1]);
}

int getMoreLogs(void *data, int *num) {
    int nrow = 0, ncolumn = 0;
    char **azResult = 0;
    int i = 0;
    int j = 0;
    char sql[100];
    char *zErrMsg;
    DB_LOG *db_log;

    int db_len = getLength();
    if (db_len > 50) {
        db_len = 20;
    }
    *num = db_len;
    sprintf(sql, "SELECT * FROM DB_LOG  order  by id desc  limit %d", db_len);
    if (SQLITE_OK != sqlite3_get_table(db, sql, &azResult, &nrow, &ncolumn, &zErrMsg)) {
        printf("operate failed: %s\n", zErrMsg);
    }
    for (i = 0; i < nrow; i++) {
        db_log = (DB_LOG *) (data + i * sizeof(DB_LOG));
        db_log->id = atoi(azResult[(i + 1) * 4]);
        memcpy(db_log->content, azResult[(i + 1) * 4 + 1], strlen(azResult[(i + 1) * 4 + 1]));
        db_log->level = atoi(azResult[(i + 1) * 4 + 2]);
        db_log->time = atol(azResult[(i + 1) * 4 + 3]);
    }
    sqlite3_free_table(azResult);
    return 1;
}
#endif //LEARN_C_LOG_H
