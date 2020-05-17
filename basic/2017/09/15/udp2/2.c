//
// Created by zhangrongxiang on 2017/9/15.
//
#include <stdio.h>
#include <string.h>

int main() {
    char *a = "fuck u";
    int i;
    printf("%s\n", a);
    printf("%lld\n", (long long) &a);
    long long aa;
    for (i = 0; i < strlen(a); ++i) {
        aa += a[i] << (8 * i);
    }
    printf("%lld\n", aa);
    printf("%lld\n", 128782101083494l);
    return 0;
}