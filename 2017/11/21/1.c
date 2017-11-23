//
// Created by zhangrongxiang on 2017/11/21 13:41
// File 1
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate(char *string) {
    char buff[3];
    int i;
    int length = strlen(string);
    char desc[200] = {0};
    for (i = length - 1; i >= 0; i--) {
        sprintf(buff, "%2X", string[i]);
        strcat(desc, buff);
    }
    long long data = strtol(desc, NULL, 16);
    printf("%-10s   <====>  %ld\n", (char *) (&data), data);
}

int main() {
    generate("u SB");
    generate("fuck u");
    generate("WTF");
    generate("TKS");
    return 0;
}