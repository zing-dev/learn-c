//
// Created by zhangrongxiang on 2017/10/27 11:53
// File rand
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    char *content[] = {
            "管理员登陆",
            "添加用户",
            "删除用户",
            "修改用户",
            "修改密码",
            "删除密码",
            "备份密码",
            "管理员退出"
    };
    char **c = content;
    printf("%s\n", *content);
    printf("%s\n", *(content + 1));
    printf("%s\n", content[0]);
    printf("%d\n", (int) strlen(content[0]));
    int i;
    for (i = 0; i < 8; ++i) {
        printf("%s ------%s \n", *(content + i), *(c + i));
    }
    while (i++) {
        if (i == 100)
            break;
        printf("%d --->  %s \n", i, *(c + rand() % 8));
        sleep(1);
    }
    return 0;
}