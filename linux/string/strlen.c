//
// Created by zing on 2018/2/7 10:41
// File strlen
//

#include <stdio.h>
#include <string.h>

//Software is like sex: it"s better when it"s free.
//My name is Linus, and I am your God
//Linux is obsolete.
//Linux is not Unix

int main() {
    char *str = "My name is Linus, and I am your God";
    size_t length = strlen(str);
    printf("%s --> length is %d\n", str, (int) length);

    char *str2 = "一切皆文件";
    length = strlen(str2);
    printf("%s  -- length --> %d\n", str2, (int) length); //15 = 3 * 15
    printf("%s  -- sizeof --> %d\n", str2, (int) sizeof("一切皆文件")); //16 = 3 * 5 + 1

    char str3[] = "万物皆对象";
    printf("%s  -- sizeof --> %d\n", str3, (int) sizeof(str3)); //16 = 3 * 5 + 1

    char *s = "😍";
    printf("%ld\n", strlen(s));
    printf("%s\n", s);
    printf("%x\n", s[0]);

    for (int i = 0; i < strlen(s); i++) {
        printf("%d %x\t", s[i], s[i]);
    }
    printf("\n");
    char s2[] = {-16, -97, -104, -115, 0};
    printf("%s\n", s2);
    char s3[] = {-16, -97, -104, -116, 0};
    printf("%s\n", s3);
    return 0;
}