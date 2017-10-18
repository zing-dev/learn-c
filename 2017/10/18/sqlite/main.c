//
// Created by zhangrongxiang on 2017/10/18 16:33
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
int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
}