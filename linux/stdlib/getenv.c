//
// Created by zhangrongxiang on 2018/2/28 9:28
// File getenv
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char *env = getenv("PATH");
    printf("%s\n", env);
    printf("--------------------------------------------------\n");
    char *result = env;
    char target = ';';
    while ((result = strchr(result, target)) != NULL) {
        printf("%s\n", result);
        ++result; // result 自增，否则我们会找到相同位置的目标
    }
    return 0;
}