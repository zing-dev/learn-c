//
// Created by zhangrongxiang on 2018/2/26 9:09
// File crypt
//


#include <stdio.h>
#include <memory.h>
#include <errno.h>
#include <crypt.h>

int main() {
    char *str = "hello";
    char *salt = "abc";
    char *rs = NULL;
    rs = crypt(str, salt);//crypt.c:(.text+0x27): undefined reference to `crypt'
    if (rs != NULL) {
        //abl0JrMf6tlhw
        printf("%s\n", rs);
    } else {
        printf("%s\n", strerror(errno));
    }
    return 0;
}