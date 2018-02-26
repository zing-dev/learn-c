//
// Created by zhangrongxiang on 2018/2/26 13:58
// File getlogin
//

#include <stdio.h>
#include <unistd.h>

int main() {
    char *login = getlogin();
    if (login) {
        printf("%s\n", login);//vagrant
    }
    return 0;
}