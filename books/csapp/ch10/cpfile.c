//
// Created by zing on 2021/3/15.
//

#include "csapp.h"

//P604
int main() {
    int n;
    rio_t rio;
    char buf[MAXLINE];

    Rio_readinitb(&rio, STDIN_FILENO);
    while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0){
        Rio_writen(STDOUT_FILENO, buf, n);
    }
    return 0;
}

