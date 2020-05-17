//
// Created by zhangrongxiang on 2018/2/2 10:29
// File strncpy
//


#include<stdio.h>
#include<string.h>

int main(void) {
    char dest1[20];
    char src1[] = "abc";
    int n1 = 3;
    strncpy(dest1, src1, n1);  // n1小于strlen(str1)+1，不会追加'\0'
    printf("dest1 = %s\n", dest1);
//    dest1 = abc


    char dest2[20] = "********************";
    char src2[] = "abcxyz";
    int n2 = strlen(src2) + 1;
    strncpy(dest2, src2, n2);  // n2等于strlen(str2)+1，恰好可以把src2末尾的'\0'拷贝到dest2
    printf("dest2 = %s, dest2[15]= %c \n", dest2, dest2[10]);
//    dest2 = abcxyz, dest2[15]= *

    char dest3[100] = "http://man7.org/tlpi/";
    char src3[6] = "abcxyz";  // 没有'\0'
    int n3 = 20;
    strncpy(dest3, src3, n3);  // n3大于strlen(str3)+1，循环拷贝str3
    printf("dest3 = %s\n", dest3);


//    char *strncpy(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
    char string[10]={0};
    char *string2 = "Hello World";
    //_Count < sizeof(string) - 1
    strncpy(string, string2, 2);
    printf("%s\n", string); //He
    memset(string, 0, sizeof(string));
    //_Count > sizeof(string) - 1
    strncpy(string, string2, strlen(string2));
    printf("%s\n", string); // Hello Worldb  结果不可预测
    memset(string, 0, sizeof(string));
    //_Count = sizeof(string) - 1
    strncpy(string, string2, sizeof(string) - 1);
    printf("%s\n", string); //Hello Wor
}