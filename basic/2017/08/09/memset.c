//
// Created by 张荣响 on 2017/8/9.
//

#include <stdio.h>
#include <string.h>

int main() {
//  函数解释：将s中当前位置后面的n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
    char buffer[] = "Helloworld\n";
    printf("Buffer before memset:%s\n", buffer);
    memset(buffer, '*', strlen(buffer));
    printf("Buffer after memset:%s\n", buffer);
    return 0;

}