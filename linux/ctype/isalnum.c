//
// Created by zing on 2018/1/31 13:33
// File isalnum
//

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

/*isalnum*/

int main() {

    ///////////////////////////////////////////////////////////////////////////////////
    unsigned char c = '\xdf'; // ISO-8859-1 中的德文字母 ß
    printf("isalnum('\\xdf') in default C locale returned %d\n", c, !!isalnum(c));
    if (setlocale(LC_CTYPE, "de_DE.iso88591"))
        printf("isalnum('\\xdf') in ISO-8859-1 locale returned %d\n", !!isalnum(c));
    if (setlocale(LC_CTYPE, "en_US.UTF-8"))
        //isalnum('\xdf') in UTF-8 locale returned 0
        printf("isalnum('\\xdf') in UTF-8 locale returned %d\n", !!isalnum(c));


    ///////////////////////////////////////////////////////////////////////////////////
    int var1 = 'd';
    int var2 = '2';
    int var3 = '\t';
    int var4 = ' ';

    if (isalnum(var1)) {
        printf("var1 = |%c| 是字母数字\n", var1);
    } else {
        printf("var1 = |%c| 不是字母数字\n", var1);
    }
    if (isalnum(var2)) {
        printf("var2 = |%c| 是字母数字\n", var2);
    } else {
        printf("var2 = |%c| 不是字母数字\n", var2);
    }
    if (isalnum(var3)) {
        printf("var3 = |%c| 是字母数字\n", var3);
    } else {
        printf("var3 = |%c| 不是字母数字\n", var3);
    }
    if (isalnum(var4)) {
        printf("var4 = |%c| 是字母数字\n", var4);
    } else {
        printf("var4 = |%c| 不是字母数字\n", var4);
    }
//  var1 = |d| 是字母数字
//  var2 = |2| 是字母数字
//  var3 = |	| 不是字母数字
//  var4 = | | 不是字母数字

    ///////////////////////////////////////////////////////////////////////////////////
    int i;
    char str[] = "c3po...";
    i = 0;
    while (isalnum(str[i])) i++;
    //The first 4 characters are alphanumeric.
    printf("The first %d characters are alphanumeric.\n", i);
    return 0;

}
