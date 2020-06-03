//
// Created by zhangrongxiang on 2018/2/6 11:18
// File strpbrk
//

#include <stdio.h>
#include <string.h>

//依次检验字符串 str1 中的字符，当被检验字符在字符串 str2 中也包含时，则停止检验，并返回该字符位置。
//检索字符串 str1 中第一个匹配字符串 str2 中字符的字符，不包含空结束字符。
/* Find the first occurrence in S of any character in ACCEPT.  */
int main() {
    int i = 0;
    const char str1[] = "abcde2fghi3jk4l";
    const char str2[] = "34";
    const char *str3 = "Life is short,I use C";
    char *ret;

    ret = strpbrk(str1, str2);
    if (ret) {
        printf("Number one is : %c\n", *ret);//3
    } else {
        printf("No");
    }

    ret = strpbrk(str1, str3);
    if (ret) {
        printf("Number one is : %c\n", *ret);//e
    } else {
        printf("No");
    }
    printf("\n");
    size_t len = strlen(str1);
    char *ch = 0;
    int index = 0;
    char all[20] = {0};

    //获取两个字符串的字符交集
    for (; i < len; ++i) {
        ret = strpbrk((str1 + sizeof(char) * (index + 1)), str3);
        if (ret) {
            ch = strrchr(str1, *ret);
            index = (int) (ch - str1);
            printf("Number one is : %c\n", *ret);
            all[i] = *ret;
        } else {
            printf("No");
        }
    }
    printf("\n");
    for (i = 0; i < 20; ++i) {
        if (all[i] == 0)
            break;
        printf("%c ", all[i]); //e f h i
    }
    printf("\n");
    //单词统计
    const char *str = "hello world, friend of mine!";
    const char *sep = " ,!";

    unsigned int cnt = 0;
    do {
        str = strpbrk(str, sep); // 寻找分隔符
//        printf("%s\n",str);
        if (str) {
            str += strspn(str, sep); // 跳过分隔符
            printf("%s\n", str);
        }
        ++cnt; // 增加词计数
    } while (str && *str);

    printf("There are %d words\n", cnt); // 5
    return 0;
}