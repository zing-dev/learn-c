//
// Created by zhangrongxiang on 2017/11/21 13:41
// File 1
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = "u SB", buff[3];
    int i;
    int length = strlen(str);
    char desc[200] = {0};
    for (i = length - 1; i >= 0; i--) {
        sprintf(buff, "%2X", str[i]);
        strcat(desc, buff);
    }
    long data = strtol(desc, NULL, 16);
    printf("%d\n", data);
    printf("%s\n", (char *) (&data));
    return 0;
}