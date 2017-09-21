//
// Created by zhangrongxiang on 2017/9/20 14:41
//

#include <stdio.h>

int main() {
    char ch[] = "char";
    char *a = ch, *b = ch;
    int i = 10;
    printf("%d\n", a + i - b);

}