//
// Created by zing on 2018/2/12.
//

#include <string.h>
#include <stdio.h>

/* Find the first occurrence of C in S.  */
int main() {
    char str[] = "I love this world!";
    char *p = strchr(str, 'I');
    printf("%s\n", p);//字符串 I love this world!
    printf("%c\n", *p);//字符值 I
    printf("%d\n", (int) (p - str));//索引 0
    p = strchr(str, 'l');
    printf("%s\n", p);//字符串 love this world!
    printf("%c\n", *p);//字符值 l
    printf("%d\n", (int) (p - str));//索引 2

    const char *str2 = "Try not. Do, or do not. There is no try.";
    char target = 'T';
    const char *result = str2;

    while ((result = strchr(result, target)) != NULL) {
        //Found 'T' starting at 'Try not. Do, or do not. There is no try.'
        //Found 'T' starting at 'There is no try.'
        printf("Found '%c' starting at '%s'\n", target, result);
        ++result;
    }
    return 0;
}