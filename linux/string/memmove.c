//
// Created by zhangrongxiang on 2018/2/10.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Copy N bytes of SRC to DEST, guaranteeing correct behavior for overlapping strings.  */
int main() {
    char str[32] = "I am your GOD";
    char str2[32] = "Hello World";
    char str3[] = "void * memmove ( void * destination, const void * source, size_t num );";
    memmove(str2, str, strlen(str) + 1);
    printf("%s\n", str2);//I am your GOD
    memmove(str2, "hi\0hi", sizeof(str2));
    printf("%s\n", str2);//hi
    printf("%c%c%c%c\n", str2[3], str2[4], str2[5], str2[6]);//hi\0\0
    memmove(str, str3, sizeof(str) - 1);
    for (int i = 0; i < sizeof(str); ++i) {
        printf("%c", str[i]);
    }//void * memmove ( void * destina%
/////////////////////////////////////////////////////////////////////
    char str4[] = "1234567890";
    puts(str4);//1234567890
    memmove(str4 + 4, str4 + 3, 3); // 从 [4,5,6] 复制到 [5,6,7]
    puts(str4);//1234456890
////////////////////////////////////////////////////////////////////
    // 设置分配的内存的有效类型为 int
    int *p = malloc(3 * sizeof(int));   // 分配的内存无有效类型
    int arr[3] = {1, 2, 3};
    memmove(p, arr, 3 * sizeof(int));     // 分配的内存现在拥有有效类型
    printf("%d%d%d\n", p[0], p[1], p[2]);//123
    printf("%d%d%d\n", *p, *(p + 1), *(p + 2));//123

    char s1[] = "hello";
    char s2[] = "hello world";
    memmove(s1, s2, strlen(s2));
    printf("%s\n", s1);
    printf("%lu\n", sizeof(s1)); //6
    printf("%lu\n", strlen(s1)); //11
    printf("%s\n", s2);
    printf("%lu\n", sizeof(s2)); //12
    printf("%lu\n", strlen(s2)); //11
    return 0;
}