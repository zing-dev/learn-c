//
// Created by zing on 6/4/2020.
//


#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int ret = mkdir("test", ALLPERMS);
    if (ret == -1) {
        if (errno == EEXIST) {
            printf("文件已经存在\n");
        } else {
            perror("mkdir");
        }
        return errno;
    }
    return 0;
}
