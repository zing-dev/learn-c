//
// Created by zhangrongxiang on 2017/10/25 16:58
// File snprint
//

/* snprintf example */
#include <stdio.h>

int main() {
    char buffer[100];
    int cx;
    /**
     * 最多从源串中拷贝size－1个字符到目标串中，然后再在后面加一个0。所以如果目标串的大小为size的话，将不会溢出。
     * 若成功则返回欲写入的字符串长度，若出错则返回负值。
     */
    cx = snprintf(buffer, 100, "The half of %d is %d", 60, 60 / 2);
    if (cx >= 0 && cx < 100) {
        snprintf(buffer + cx, 100 - cx, ", and the half of that is %d.", 60 / 2 / 2);
//        , and the half of that is 15.
        printf("%s\n", buffer + cx);
    }   // check returned value
    puts(buffer);
//    The half of 60 is 30, and the half of that is 15.
    return 0;
}