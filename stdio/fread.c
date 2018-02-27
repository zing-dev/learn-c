//
// Created by zhangrongxiang on 2018/2/27 9:57
// File fread
//

#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("./fread.c", "r");
    char buf[16];
    if (file != NULL) {
        while (!feof(file)) {
            memset(buf, 0, sizeof(buf));
            size_t i = fread(buf, 1, sizeof(buf), file);
//            printf("-%d-\n",(int) i);
            printf("%s", buf);
        }
    }
}