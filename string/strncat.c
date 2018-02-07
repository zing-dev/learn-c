//
// Created by zhangrongxiang on 2018/2/7 17:36
// File strncat
//

#include <stdio.h>
#include <string.h>
//C 库函数 char *strncat(char *dest, const char *src, size_t n) 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾，直到 n 字符长度为止。
int main() {
    char src[50], dest[50];
    strcpy(src, "This is source");
    strcpy(dest, "This is destination");
    char *str = strncat(dest, src, 15);
    printf("%s\n", dest);
    printf("%s\n", str);
    printf("%d\n",str == dest);
    return 0;
}