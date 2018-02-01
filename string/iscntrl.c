//
// Created by zhangrongxiang on 2018/2/1 15:14
// File iscntrl
//

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
    unsigned char c = '\x94'; // ISO-8859-1 的控制码 CCH
    printf("In the default C locale, \\x94 is %sa control character\n",
           iscntrl(c) ? "" : "not ");
    //In the default C locale, \x94 is not a control character
    setlocale(LC_ALL, "en_GB.iso88591");
    printf("In ISO-8859-1 locale, \\x94 is %sa control character\n",
           iscntrl(c) ? "" : "not ");

    int i = 0;
    char str[] = "first line \n second line \n";
    while (!iscntrl(str[i])) {
        putchar(str[i]);
        i++;
    }
    //first line
    return 0;
}