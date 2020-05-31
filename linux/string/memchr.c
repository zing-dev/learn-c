//
// Created by zhangrongxiang on 2018/2/8 14:10
// File memchr
//

//C 库函数 void *memchr(const void *str, int c, size_t n)
// 在参数 str 所指向的字符串的前 n 个字节中搜索第一次出现字符 c（一个无符号字符）的位置。

#include <string.h>
#include <stdio.h>

/* Search N bytes of S for C.  */
int main() {
    //字符串
    char str[] = "I am your God";
    char *position = (char *) memchr(str, 'y', strlen(str));
    if (position) {
        printf("%s\n", position);//your God
        printf("%d\n", (int) (position - str));//5
        printf("%c\n", str[position - str]); //y
    } else {
        printf("null\n");
    }
    printf("===================================\n");
    //数组
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int *pInt = (int *) memchr(arr, 50, sizeof(arr));
    printf("%d\n", (int) (pInt - arr));//4
    printf("%ld\n",  (pInt - arr));//4
    printf("%d\n", *pInt);//50
    printf("%c\n", *pInt);//2
    printf("%c\n", (unsigned char) 50); //2
    printf("%c\n", (char) 50); //2
    printf("%c\n", 50);//2
    printf("%c\n", (unsigned char) 51); // 3

    return 0;
}