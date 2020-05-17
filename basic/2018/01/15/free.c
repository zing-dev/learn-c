//
// Created by zhangrongxiang on 2018/1/15 16:13
// File free
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MYSQL {
    char *user;
    char *pwd;
    char *host;
} MySQL;


int main() {
    char user[] = "root";
    char *pUser = (char *) malloc(sizeof(char) * 10);
    memcpy(pUser, user, sizeof(user));
    printf("-------------------hello world---------------------\n");
    MySQL *mySQL = (MySQL *) malloc(sizeof(MySQL));
    mySQL->user = pUser;
    printf("%s\n", mySQL->user);
    free(mySQL->user);
    free(pUser);
    if (pUser != NULL) {
        printf("--> %s\n", pUser);
        free(pUser);
        int i = 0;
        for (; i < strlen(pUser); ++i) {
//            free(pUser[i]);
            printf("%c\t",pUser[i]);
        }
    }
    if (mySQL->user != NULL) {
        printf("%s\n", user);
        printf("%s\n", pUser);
    } else {
        printf("not free");
    }
    free(mySQL);
    return 0;
}