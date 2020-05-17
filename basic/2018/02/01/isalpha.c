//
// Created by zhangrongxiang on 2018/2/1 14:54
// File isalpha
//

#include <ctype.h>
#include <stdio.h>
#include <locale.h>

int main(void) {
    unsigned char c = '\xdf'; // ISO-8859-1 的德文字母 ß
    printf("isalpha('\\xdf') in default C locale returned %d\n", !!isalpha(c));  //0
    setlocale(LC_CTYPE, "de_DE.iso88591");
    printf("isalpha('\\xdf') in ISO-8859-1 locale returned %d\n", !!isalpha(c));//0

    int i = 0;
    char str[] = "I Love My Country!!";
    while (str[i]) {
        if (isalpha(str[i])) printf("character %c is alphabetic\n", str[i]);
        else printf("character %c is not alphabetic\n", str[i]);
        i++;
    }
    return 0;
}