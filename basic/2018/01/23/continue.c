//
// Created by zhangrongxiang on 2018/1/23 9:25
// File continue
//

#include <stdio.h>

int main() {
    int i, j = 0;
    printf("---------------------------------------\n");
    while (++i) {
        j += 1;
        if (i == 100) {
            printf("i == 100\n");
            break;
        }
        if (i == 50) {
            printf("i == 50\n");
            continue;
        }
        if (i > 10) {
            if (j == 30) {
                printf("j == 20\n");
                continue;
            }
            printf("--> i == %d  j == %d \n", i, j);
            if (j == 60)
                break;
        }
    }
}