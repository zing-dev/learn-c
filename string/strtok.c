//
// Created by zhangrongxiang on 2017/8/15 10:59.
// Copyright (c) 2017 ZRC . All rights reserved.
//

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void strtoktest() {
    char input[16] = "abc=d";
    char *p;
    /*strtok places a NULL terminator
    infront of the token,if found*/
    p = strtok(input, "=");
    if (p)
        printf("%s\n", p);
    /*Asecond call to strtok using a NULL
    as the first parameter returns a pointer
    to the character following the token*/
    p = strtok(NULL, "=");
    if (p)
        printf("%s\n", (p));
}

int strtoktest2() {
    char input[27] = "TPROXY_CPORT = 11111";
    char *temp;
    if ((temp = (char *) strtok(input, " "))) {
        printf("-->  %s\n", temp);
    }
    if ((temp = (char *) strtok(NULL, " "))) {
        printf("---->  %s\n", (temp));
    }
//    if ((temp = (char *) strtok (NULL, " "))){
//        printf("---->  %s\n",temp);
//    }



    if (!strcmp(temp, "TPROXY_CPORT")) {
        printf("-------> %d\n", temp);
        if ((temp = (char *) strtok(NULL, " ")) == NULL)
            return 1;
        int GF_TPROXY_CPORT = atoi(temp);
        printf("--> %d\n", temp);
        printf("%d\n", GF_TPROXY_CPORT);
        printf("---------------------end---------------------");
    }
    return 1;
}

int main(void) {
    strtoktest();
//    strtoktest2();
    return 0;
}