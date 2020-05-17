//
// Created by zhangrongxiang on 2017/10/17 10:12
// File mkdir
//
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PATH_MAX 255

int main() {
    createdir("./data/test");
}

int _createdir(const char *sPathName) {
    char DirName[PATH_MAX];
    strcpy(DirName, sPathName);
    int i, len;
    len = strlen(DirName);
    if (DirName[len - 1] != '/')
        strcat(DirName, "/");

    len = strlen(DirName);
    for (i = 1; i < len; i++) {
        if (DirName[i] == '/') {
            DirName[i] = 0;
            if (access(DirName, 0) != 0) {
                if (mkdir(DirName, 0755) == -1) {
                    printf("mkdir error");
                    return -1;
                }
            }
            DirName[i] = '/';
        }
    }

    return 0;
}

int createdir(char *file) {
    char pathname[PATH_MAX];
    memset(pathname, 0, PATH_MAX);
    strcpy(pathname, file);

    int i;
    for (i = strlen(file); i > 0; i--) {
        if ('/' == pathname[i]) {
            pathname[i + 1] = '\0';
            break;
        }
    }
    _createdir(pathname);
    return 0;
}