//
// Created by 张荣响 on 2018/2/11.
//

#include <string.h>
#include <stdio.h>
int main() {
    char str[] = "i am the god";
    char str2[sizeof(str)];
    printf("%d\n", (int) sizeof(str));
    printf("%s\n", str);
    memset(str2, 'A', 12);
    puts(str2);
    printf("%s\n", str2);
    printf("%d\n", (int) sizeof(str2));
    memset(str, 92, sizeof(str) - 1);//
    printf("%s\n", str);
    printf("%d\n", 0 == NULL);//1
    printf("%d\n", 0 == '\0');//1
    printf("%d\n", NULL == '\0');//1
    return 0;
}