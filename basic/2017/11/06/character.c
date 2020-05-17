//
// Created by zhangrongxiang on 2017/11/6 15:38
// File character
//
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "你好你好你好你好";
    printf("%s\n", str);
    printf("%d\n", strlen(str));
    char str_log[1000], *filename = "/a/vb/d/s/哈哈哈.txt";
    sprintf(str_log, "{\"type\":\"receive\",\"path\":\"%s\",\"result\":0}", filename);
    printf("%s\n", str_log);
    printf("%d\n", strlen(str_log));
    return 0;
}