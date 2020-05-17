//
// Created by zhangrongxiang on 2018/2/26 17:02
// File creat
//
//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *path = "./test.txt";
    int fd = creat(path, O_APPEND);
    if (fd != -1) {
        printf("creat file success!\n");
        char buf[] = "Hello World\n";
        write(fd, buf, (int) strlen(buf));
    } else {
        perror("creat error");
        exit(EXIT_FAILURE);
    }
    close(fd);
    return EXIT_SUCCESS;
}