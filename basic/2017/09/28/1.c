//
// Created by zhangrongxiang on 2017/9/28 14:01
// File 1
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    char buf[10] = "";
    fread(buf, 9, 1, stdin); /* 从标准输入 stdin 读入字符 */
    write(1, buf, strlen(buf));
    return 0;
}