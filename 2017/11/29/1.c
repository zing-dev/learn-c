//
// Created by zhangrongxiang on 2017/11/29 11:31
// File 1
//

#include <stdio.h>
#include <string.h>

void get(void *data) {
    int *pInt;
    pInt = (int *) (data);
    printf(">>>>>>>>>>>>>> %d\n", *pInt);
}

int main() {
    unsigned int ii[] = {5, 3, [5] = 10}, iii = 111;
    unsigned char index[sizeof(ii)];
    unsigned char index2[4];

    memcpy(index, ii, sizeof(ii));
    memcpy(index2, &iii, sizeof(iii));
//    memcpy(index3, &iii, sizeof(iii));
    get(index2);
    unsigned int *pInt;

    for (int i = 0; i < (sizeof(ii) / sizeof(unsigned int)); ++i) {
        pInt = (unsigned int *) (index + sizeof(unsigned int) * i);
        printf("%d\n", *pInt);
    }

    printf("-----------------------------------------------------\n");
    printf("sizeof(ii) --> %ld\n", sizeof(ii));
    printf("sizeof(ii) --> %ld\n", sizeof(unsigned int) * 11);
    printf("-----------------------------------------------------\n");
    printf("*(unsigned int *) (index)  --> %d\n", *(unsigned int *) (index));
    printf("-----------------------------------------------------\n");
    //memset(index2, iii, sizeof(unsigned int));
    printf("*(unsigned int *) (index2) --> %d\n", *(unsigned int *) (index2));
//    printf("*(unsigned int *) (index3) --> %d\n", *(unsigned int *) (index3));
    printf("-----------------------------------------------------\n");
    printf("sizeof(int)  -->  %ld\n", sizeof(int));
    printf("sizeof(unsigned int)  -->  %ld\n", sizeof(unsigned int));
}