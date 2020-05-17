//
// Created by zhangrongxiang on 2018/2/23 16:37
// File 1
//

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *fp = NULL;
    if ((fp = (fopen("new.txt", "r"))) == NULL)
        printf("open failure");

    char num[10];
    while (1) {
        if ((fgets(num, 10, fp)) == NULL) {
            if (ferror(fp)) {
                printf("read error\n");
                fclose(fp);
                return -1;
            } else {
                printf("reach to end\n");
                fclose(fp);
                return 0;
            }
        } else {
            printf("%s\n", num);
        }

    }
    fclose(fp);
    return 0;
}