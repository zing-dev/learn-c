//
// Created by zhangrongxiang on 2018/2/24 11:26
// File pointer
//

#include <stdio.h>

int main() {
    char c = 'a';
    printf("%c\n", c);//a
    char *string = "abc";
    printf("%c%c%c\n", string[0], string[1], string[2]); //abc
    printf("%s\n", string); //abc
    char **pString = &string;
    printf("%s\n", *pString); //abc
    printf("%s\n", pString[0]); //abc
    printf("%c\n", pString[0][0]); //abc
    char ***pStr = NULL;
    pStr = &pString;
    printf("%s\n", pStr[0][0]);
    int arr[3][2] = {
            {10, 20},
            {30, 40},
            {50, 60},
    };
    printf("%d\n", arr[2][1]);//60
    printf("%d\n", *(arr[2] + 1));//60
    printf("%d\n", *(*(arr + 2) + 1));//60

    char *str[] = {
            "abc", "cbd", "def"
    };
    char *str2[3][4] = {
            "abc", "def", "123"
    };
    printf("%s\n", str[0]);
    char **pStr2 = str;
    char ***pStr3 = &pStr2;
    printf("%s\n", pStr3[0][0]);
    printf("%s\n", *(*(pStr3)));
    printf("%s\n",str2[0][0]);
    return 0;
}