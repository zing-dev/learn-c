//
// Created by zhangrongxiang on 2017/8/16 16:38.
// Copyright (c) 2017 ZRC . All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main()
{
    char *str[3] = {
        "Hello,this is a sample!",
        "Hi,good morning.",
        "Hello World"
    };
    char s[80];
    strcat(s, str[0]); //也可写成 strcpy(s,*str);
    strcat(s, str[1]); //也可写成 strcpy(s,*(str+1));
    strcat(s, str[2]); //也可写成 strcpy(s,*(str+2));
    printf("%s\n", s);

    printf("%s\n", *(str + 0));
    printf("%s\n", *(str + 1));
    printf("%s\n", *(str + 2));

    printf("%c\n", **str);
    printf("%c\n", *(*(str + 0) + 1));
    printf("%c\n", *(*(str + 1) + 1));

}