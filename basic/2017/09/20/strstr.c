//
// Created by zhangrongxiang on 2017/9/20 15:04
//

/* strstr example */
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "This is a simple string";
    char *pch, *pch2;
    pch = strstr(str, "simple");
    pch2 = strstr(str, "a");
    puts(pch);
    puts(pch2);
//    strncpy(pch, "sample", 6);
//    puts(str);
//    puts(pch);


    return 0;
}