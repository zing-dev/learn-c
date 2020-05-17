//
// Created by zhangrongxiang on 2018/3/2 15:04
// File sql2
//


#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

int query(sqlite3 *db, sqlite3_stmt *stmt) {
//    sqlite3 *db;
//    sqlite3_stmt *stmt;

    char *selectSql = "select * from student order by id desc limit 0,10;";
    int res = sqlite3_prepare_v2(db, selectSql, (int) strlen(selectSql), &stmt, 0);
    if (res != SQLITE_OK) {
        printf("sqlite3_prepare_v2 error\n");
        fprintf(stderr, "prepare error %s\n", sqlite3_errmsg(db));
        return -1;
    }
    res = sqlite3_step(stmt);
    /*
    if(res != SQLITE_DONE)
    {
    printf("sqlite3_step error\n");
    return -1;
    }
    */
    int count = sqlite3_column_count(stmt);
    printf("count = %d\n", count);
    int i;
    //#define SQLITE_INTEGER  1
    //#define SQLITE_FLOAT    2
    //#define SQLITE_BLOB     4
    //#define SQLITE_NULL     5
    //#ifdef SQLITE_TEXT
    //# undef SQLITE_TEXT
    //#else
    //# define SQLITE_TEXT     3
    //#endif
    //#define SQLITE3_TEXT     3
    for (i = 0; i < count; i++) {
        printf("column name:%s - type %d\n", sqlite3_column_name(stmt, i), sqlite3_column_type(stmt, i));
    }
    unsigned int id;
    const char *name;
    unsigned int age;
    const char *address;
    while (res == SQLITE_ROW) {
        id = (unsigned int) sqlite3_column_int(stmt, 0);
        name = (char *) sqlite3_column_text(stmt, 1);
        age = (unsigned int) sqlite3_column_int(stmt, 2);
        address = (char *) sqlite3_column_text(stmt, 3);
        printf("id = %d,name = %s,age = %d,address = %s\n", id, name, age, address);
        res = sqlite3_step(stmt);
    }
    if (stmt) {
        sqlite3_finalize(stmt);
        printf("query sqlite3_finalize\n");
    }
    return res;
}

int insert(sqlite3 *db, sqlite3_stmt *stmt, char *name, int age, char *address) {
    char *insertSql = "insert into student(name,age,address) values(?,?,?);";
    int res = sqlite3_prepare_v2(db, insertSql, (int) strlen(insertSql), &stmt, 0);
    if (res != SQLITE_OK) {
        printf("sqlite3_prepare_v2 error\n");
        fprintf(stderr, "prepare error %s\n", sqlite3_errmsg(db));
        return -1;
    }
    sqlite3_bind_text(stmt, 1, name, (int) strlen(name), 0);
    sqlite3_bind_int(stmt, 2, age);
    sqlite3_bind_text(stmt, 3, address, (int) strlen(address), 0);
    res = sqlite3_step(stmt);
    if (res != SQLITE_DONE) {
        printf("sqlite3_step error\n");
        return -1;
    }
    if (stmt) {
        sqlite3_finalize(stmt);
        printf("insert sqlite3_finalize\n");
    }
    return res;
}

int update(sqlite3 *db, sqlite3_stmt *stmt, char *name, int age, char *address) {
    char *maxIDSQL = "select max(id) from student";
    int maxID = 0;
    int res = sqlite3_prepare_v2(db, maxIDSQL, (int) strlen(maxIDSQL), &stmt, 0);
    if (res == SQLITE_OK) {
        res = sqlite3_step(stmt);
        if (res == SQLITE_ROW) {
            maxID = (unsigned int) sqlite3_column_int(stmt, 0);
        }
    }
//    printf("maxID %d\n", maxID);
    if (maxID == 0) {
        maxID = 10;
    }
    char *insertSql = "update student set name=? where id=?";
    sqlite3_prepare_v2(db, insertSql, (int) strlen(insertSql), &stmt, 0);
    sqlite3_bind_text(stmt, 1, name, (int) strlen(name), 0);
    sqlite3_bind_int(stmt, 2, maxID);
    res = sqlite3_step(stmt);
    printf("%s\n", sqlite3_sql(stmt));
    if (res == SQLITE_DONE) {
        printf("update ok \n");
    } else {
        perror("update error");
    }
    if (stmt) {
        sqlite3_finalize(stmt);
        printf("update sqlite3_finalize\n");
    }
    return res;
}

void generate(sqlite3 *db, sqlite3_stmt *stmt) {
    int i = 0;
    for (; i < 10; ++i) {
        char name[16], address[64];
        sprintf(name, "zing-%d", i);
        sprintf(address, "jiansu-wuxi-%d", i);
        insert(db, stmt, name, i + 20, address);
    }
}

int main() {
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    int res = sqlite3_open("test.db", &db);
    if (res != SQLITE_OK) {
        fprintf(stderr, "open error %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }
    printf("open test.db success\n");
//    query(db, stmt);
//    generate(db, stmt);
    update(db, stmt, "zhangrxiang", 0, NULL);
//    query(db, stmt);
    if (db) {
        sqlite3_close(db);
        printf("sqlite3_close success\n");
    }
    return 0;
}