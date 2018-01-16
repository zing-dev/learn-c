//
// Created by zhangrongxiang on 2018/1/16 10:31
// File 8
//

#include <stdio.h>
//编写函数rverse(s)将字符串s中的字符顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序。
int getline_(char s[], int lim) {
    int c;
    int i;
    i = 0;
    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = (char) c;
    }
    if (c == EOF && i == 0)
        return -1;
    if (c == '\n')
        s[i++] = (char) c;
    s[i++] = '\0';
    return i;
}

void reverse_(char s[]) {
    int i, j;
    char c;
    i = 0;
    while (s[i] != '\0')
        i++;
    i--;
    if (s[i] == '\n')
        i--;
    j = 0;
    while (j < i) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        j++;
        i--;
    }
}

int main() {
    char line[256];
    while (getline_(line, 256) > 0) {
        reverse_(line);
        printf("%s", line);
    }
}