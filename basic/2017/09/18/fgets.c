//
// Created by zhangrongxiang on 2017/9/18.
//

#include <stdio.h>
#include <string.h>

#define N 5


/*
 *
 *
 * fgets函数原型：char *fgets(char *s, int n, FILE *stream);
 * //我们平时可以这么使用：fgets(str, sizeof(str), stdin);
 * 其中str为数组首地址，sizeof(str)为数组大小，stdin表示我们从键盘输入数据。
 * fgets函数功能：从文件指针stream中读取字符，存到以s为起始地址的空间里，知道读完N-1个字符，或者读完一行。
 * 注意：调用fgets函数时，最多只能读入n-1个字符。读入结束后，系统将自动在最后加'\0'，并以str作为函数值返回。
 *
 *
 */
int main() {
    char s1[N];
    char s2[N];
    fgets(s1, N, stdin);
//    gets(s1);
    if (s1[strlen(s1) - 1] == '\n') {      // 去掉换行符
        s1[strlen(s1) - 1] = '\0';
    }

    fflush(stdin);                               //清空缓冲区
    fgets(s2, N, stdin);
//    gets(s2);
    if (s2[strlen(s2) - 1] == '\n') {      // 去掉换行符
        s2[strlen(s2) - 1] = '\0';
    }

    printf("\n%s %s\n", s1, s2);

    return 0;
}