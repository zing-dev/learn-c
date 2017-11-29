//
// Created by zhangrongxiang on 2017/11/29 11:31
// File 1
//

#include <stdio.h>
#include <string.h>

int main() {
    int ii[] = {2, 3, [10] = 10};
    unsigned char index[4];
    //memcpy(index, ii, sizeof(int) * 2);
    memcpy(index, ii, sizeof(ii));
    unsigned int *pInt;
    for (int i = 0; i < 11; ++i) {
        pInt = (unsigned int *) (index + sizeof(unsigned int) * i);
        printf("%d\n", *pInt);
    }
}