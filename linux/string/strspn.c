//
// Created by zing on 2018/2/5 17:28
// File strspn
//

#include <stdio.h>
#include <string.h>

//C 库函数 size_t strspn(const char *str1, const char *str2)
// 检索字符串 str1 中第一个不在字符串 str2 中出现的字符下标。

/* Return the length of the initial segment of S which
   consists entirely of characters in ACCEPT.  */
int main() {
    size_t len;
    const char str1[] = "ABCDEFG02018ABCDEFG02018";
    const char str2[] = "ABCD";
    const char str3[] = "2018";
    const char str4[] = "AB";
    const char str5[] = "AC";
    const char str6[] = "aC";
    len = strspn(str1, str2);
    printf("%d\n", (unsigned int) len); //4
    len = strspn(str1, str3);
    printf("%d\n", (unsigned int) len); //0
    len = strspn(str1, str4);
    printf("%d\n", (unsigned int) len); //2
    len = strspn(str1, str5);
    printf("%d\n", (unsigned int) len); //1
    len = strspn(str1, str6);
    printf("%d\n", (unsigned int) len); //0

    char strtext[] = "129th";
    char cset[] = "1234567890";

    len = strspn(strtext, cset);
    printf("The initial number has %d digits.\n", (int) len);//3

    const char *string = "abcde312$#@";
    const char *low_alpha = "qwertyuiopasdfghjklzxcvbnm";

    len = strspn(string, low_alpha);
    printf("%d\n", (int) len);//5
    //After skipping initial lowercase letters from 'abcde312$#@'
    printf("After skipping initial lowercase letters from '%s'\n"
           "The remainder is '%s'\n", string, string + len);//The remainder is '312$#@'

    return (0);
}