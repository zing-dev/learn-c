//
// Created by zhangrongxiang on 2017/11/2 10:14
// File parse2
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "iniparser.h"

typedef struct MYSQL_CONF {
    char *host;
    char *user;
    char *pass;
    char *db;
    char *sock;
} MYSQLConf;

dictionary *getInstance(char *name);

int getSQL(MYSQLConf *mysqlConf);

void print(const char *string);

MYSQLConf *getCONF();

int main(int argc, char *argv[]) {
    dictionary *ini = getInstance("conf1.ini");
    MYSQLConf mysqlConf = {
            mysqlConf.host = "localhost"
    };
    MYSQLConf mysqlConf2;
    MYSQLConf *mysqlConf3;
    mysqlConf2.host = "fuck";
    printf("host %s\n", mysqlConf.host);
    printf("host %s\n", mysqlConf2.host);
    const char *a = iniparser_getstring(ini, "test:pass", "-----");
    printf("a --->  %s\n", a);
    mysqlConf3 = (MYSQLConf *) malloc(sizeof(MYSQLConf));
    getSQL(mysqlConf3);
    printf("%s\n", mysqlConf3->host);
    printf("%s\n", mysqlConf3->user);
    print(mysqlConf3->user);
    print("-----------------------------");
    MYSQLConf *mysqlConf4 = getCONF();
    print(mysqlConf4->user);
    print(mysqlConf4->sock);
    iniparser_freedict(ini);
    return 0;
}

dictionary *getInstance(char *name) {
    dictionary *ini;
    ini = iniparser_load(name);
    if (ini == NULL) {
        ini = iniparser_load("conf.ini");
    }
    return ini;
}

int getSQL(MYSQLConf *mysqlConf) {
    mysqlConf->host = "fuck";
    mysqlConf->pass = "heihei";
    mysqlConf->user = "root";
    mysqlConf->db = "haha";
    mysqlConf->sock = "lalal";
    return 1;
}

MYSQLConf *getCONF() {
    MYSQLConf *mysqlConf;
//    memset(&mysqlConf, 0x00, sizeof(mysqlConf));
    mysqlConf = (MYSQLConf *) malloc(sizeof(MYSQLConf));
    getSQL(mysqlConf);
    return mysqlConf;
}

void print(const char *string) {
    printf("%s\n", string);
}