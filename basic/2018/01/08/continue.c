//
// Created by zhangrongxiang on 2018/1/8 16:55
// File continue
//

#include <stdio.h>

int main() {
    int i = 0;
    int public;
    int this;
    while (1) {
        i++;
        if (i > 100)
            break;
        if (i == 10) {
            continue;
        } else if (i == 20) {
            continue;
        }
        printf("%d\n", i);
    }
    printf("%d\n", i);
    return 0;
}