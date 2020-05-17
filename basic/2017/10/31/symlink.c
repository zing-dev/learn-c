//
// Created by zhangrongxiang on 2017/10/31 16:09
// File symlink
//

#include <stdio.h>
#include <unistd.h>

int main(void) {
    char actualpath[] = "symlink.c";
    char sympath[] = "/tmp/mysymlink";

//    int symlink(const char *actualpath, const char *sympath);
    if (symlink(actualpath, sympath) == -1)
        printf("symlink error for %s\n", sympath);
    else
        printf("symlink succeed for %s\n", sympath);

    return 0;

}