//
// Created by zhangrongxiang on 2017/10/19 9:05
// File main
//

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/**
 * sqlite3 → The database connection object. Created by sqlite3_open() and destroyed by sqlite3_close().
 * sqlite3_stmt → The prepared statement object. Created by sqlite3_prepare() and destroyed by sqlite3_finalize().
 * sqlite3_open() → Open a connection to a new or existing SQLite database. The constructor for sqlite3.
 * sqlite3_prepare() → Compile SQL text into byte-code that will do the work of querying or updating the database. The constructor for sqlite3_stmt.
 * sqlite3_bind() → Store application data into parameters of the original SQL.
 * sqlite3_step() → Advance an sqlite3_stmt to the next result row or to completion.
 * sqlite3_column() → Column values in the current result row for an sqlite3_stmt.
 * sqlite3_finalize() → Destructor for sqlite3_stmt.
 * sqlite3_close() → Destructor for sqlite3.
 * sqlite3_exec() → A wrapper function that does sqlite3_prepare(), sqlite3_step(), sqlite3_column(), and sqlite3_finalize() for a string of one or more SQL statements.
 */
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

static int result(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%d\n", argc);
        printf("%s\n", argv[argc]);
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");

//    printf("..............%d\n",argc);
//    printf("..............%d\n",argv[1]);
    if (argv[argc] > 0) {
        printf("table already exists\n");
        return -1;
    } else {
        printf("table no exists\n");
        return 0;
    }
}

int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    /* Open database */
    rc = sqlite3_open("test.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    sql = "SELECT COUNT(*) FROM sqlite_master where type='table' and name='USER'";
    printf("-----> %d\n", sqlite3_exec(db, sql, result, 0, &zErrMsg));
    if (sqlite3_exec(db, sql, result, 0, &zErrMsg) == 0) {
        /* Create SQL statement */
        sql = "DROP TABLE IF EXISTS"\
         "CREATE TABLE USER("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL );";

        /* Execute SQL statement */
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            fprintf(stdout, "Table created successfully\n");
        }
    }
    /* Create SQL statement */
    sql = "INSERT INTO USER (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO USER (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO USER (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO USER (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL insert error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }
    sqlite3_close(db);
    return 0;
}