//
// Created by zhangrongxiang on 2018/2/24 13:57
// File pointer2
//

#include <stdio.h>
#include <string.h>

int main() {
    char a = 'a';
    char b = 'b';
    char c = 'c';
    char d = 'd';
    char str[] = {a, b, c, d, '\0'};
    char str2[5] = {a, b, c, d,};
    printf("%s\n", str);
    printf("%s\n", str2);
    char arr[][10] = {
            "abc", "def", "123"
    };
    printf("%s\n", arr[0]);
    char arr2[3][10];
    char (*arr3)[10] = arr;
    char (*arr4)[10] = {NULL};
//    arr2[0] = arr[0];
//    arr2[1] = arr[1];
    memcpy(arr2, arr, sizeof(arr));
    printf("%s%s%s\n", arr2[0], arr2[1], arr2[2]);
//    arr3 = arr;
    printf("--> %s%s%s\n", arr3[0], arr3[1], arr3[2]);
    return 0;
}