//
// Created by zhangrongxiang on 2017/11/23 17:37
// File 2
//

#include <stdio.h>
#include <string.h>

int main() {
    unsigned int ids[100] = {0}, *pids;
    unsigned char cids[400], *pcids;
    unsigned int *tmp;
    int i = 0, j = 0;
    for (; i < 100; ++i) {
        ids[i] = i * i;
    }
    pcids = cids;
    pids = ids;
    /*
    for (i = 0; i < 400; ++i) {
//        tmp = (int *)(pcids + i * sizeof(int));
        pcids[i] = (pids + i * sizeof(char));
        printf("%8x  ----  %8x\n",(pids + i * sizeof(char)),pcids[i]);
    }
    for (i = 0; i < 400; i += 4) {
        char s[4];
        for (j = 0; j < 4; j++) {
            s[j] = *((char *) &ids[i] + j);
        }
        cids[i] = s[0];
        cids[i + 1] = s[1];
        cids[i + 2] = s[2];
        cids[i + 3] = s[3];
    }
     */
    memcpy(cids, ids, sizeof(ids));
    printf("----------------------\n");

    for (i = 0; i < 100; ++i) {
//        printf("%d\n", (int) *(pcids + i * sizeof(int)));
        tmp = (unsigned int *) (pcids + sizeof(unsigned int) * i);
        printf("%d\n", *tmp);
    }
    printf("unsigned int   --> %d\n", sizeof(unsigned int));
    printf("unsigned char  --> %d\n", sizeof(unsigned char));

}