//
// Created by zhangrongxiang on 2018/1/16 10:28
// File 7
//

#include <stdio.h>
//删除每个输入行末尾的空格及制表符，并删除完全是空格的行
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

int remove_(char s[]) {
    int i;
    i = 0;
    while (s[i] != '\n')
        ++i;
    --i;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if (i >= 0) {
        s[++i] = '\n';
        s[++i] = '\0';
    }
    return i;
}

int main() {
    char line[256];
    while (getline_(line, 256) > 0) {
        if (remove_(line) > 0)
            printf("%s", line);
    }
}