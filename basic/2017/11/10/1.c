//
// Created by zhangrongxiang on 2017/11/10 16:29
// File 1
//

#include <stdio.h>
#include <string.h>

#define name "zing"

int main() {
    printf(name);
    printf("%s\n", name);
    printf("-------------------------------------------------------------\n");

//    char *string;
    char string[100];
    sprintf(string, "--- %s ---\n", "test");
    printf("%s\n", string);

    char sql[200];
    sprintf(sql, "CREATE TABLE IF NOT EXISTS %s("\
         "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
         "CONTENT           TEXT    NOT NULL," \
         "LEVEL            INT     NOT NULL," \
         "RESULT            INT     NOT NULL," \
         "CREATE_TIME      INTEGER NOT NULL);", name);

    printf(sql);
    return 0;
}