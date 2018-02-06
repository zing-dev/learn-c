//
// Created by zhangrongxiang on 2018/2/6 9:12
// File strrchr
//

#include <stdio.h>
#include <string.h>

//该函数返回 str 中最后一次出现字符 c 的位置。如果未找到该值，则函数返回一个空指针。
int main() {
    const char str[] = "https://github.com/zhangrxiang/learn-c";
    const char str2[] = "D:\\WorkSpace\\clionProjects\\learn-c\\string\\strrchr.c";
    const char ch = '/';
    const char ch2 = '\\';
    char *ret;

    ret = strrchr(str, ch);
//    |/| ------ |/learn-c|
    printf("|%c| ------ |%s|\n", ch, ret);
    printf("%c\n", ret[0]);// /
    printf("%ld\n", ret - str + 1);//number 31
    printf("%ld\n", ret - str);//index 30

    ret = strrchr(str2, ch2);
//    |\| ------ |\strrchr.c|
    printf("|%c| ------ |%s|\n", ch2, ret);
    printf("%c\n", ret[0]); /*** \ */
    printf("%c\n", str2[ret - str2]);/*** \ */
    printf("%ld\n", ret - str2 + 1);//42
    printf("%d\n", (int) strlen(ret));//10
    printf("%s\n", ret + 1);//strrchr.c
    printf("%c\n", *ret); /***   \   */
    printf("%c\n", *(ret + sizeof(char)));//s
    printf("%c\n", *(ret + sizeof(char) * 2));//t
    printf("%s\n", &(*ret));// \strrchr.c
    printf("%s\n", &*(ret + sizeof(char)));//strrchr.c

    ret = strrchr(str,'A');
    if (ret){
        printf("exists A\n");
    } else{
//        no exists A
        printf("no exists A\n");
    }
    return 0;
}