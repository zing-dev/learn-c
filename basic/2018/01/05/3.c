//
// Created by zhangrongxiang on 2018/1/5 10:13
// File 3
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd1;
    int fd2;

    // 打开文件
    fd1 = open("1.txt", O_CREAT | O_WRONLY, 0666);
    if (fd1 < 0) {
        perror("open");
        exit(-1);
    }
    printf("fd1 ============== %d\n", fd1);

    // 通过 fd1 复制出 fd2, 最终 fd1, fd2 都指向 1.txt
    fd2 = dup(fd1);
    printf("fd2 ============== %d\n", fd2);

    char *buf1 = "this is a test for fd1\n";
    // 操作 fd1 文件描述符
    write(fd1, buf1, strlen(buf1));

    char *buf2 = "this is a test for fd2\n";
    // 操作 fd2 文件描述符
    write(fd2, buf2, strlen(buf2));

    // 关闭文件描述符，两个都得关
    close(fd1);
    close(fd2);

    return 0;
}
