//
// Created by zhangrongxiang on 2018/2/26 13:36
// File ctermid
//

//ctermid - generate a pathname for controlling terminal

#include <stdio.h>

int main() {
    char string[16];
    char *rs = ctermid(string);
    if (rs) {
        printf("%s\n", rs);//  /dev/tty
        printf("%s\n", string);// /dev/tty
    }
    return 0;
}