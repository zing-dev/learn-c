//
// Created by zhangrongxiang on 2017/9/26 11:06
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv) {
    char f[20], ch[20], *str;
    FILE *file;
    if (argc >= 2) {
        if ((file = fopen(argv[1], "r")) == NULL) {
            perror("fopen error");
            exit(-1);
        }
        strcpy(f, argv[1]);
        str = strtok(f, ".");
        if (argc == 3) {
            sprintf(ch, "gcc %s -o %s.out -l%s", argv[1], rm
            f, argv[2]);
        } else {
            sprintf(ch, "gcc %s -o %s.out", argv[1], f);
        }
        system(ch);
    }
    return 0;
}