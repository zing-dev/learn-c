//
// Created by zhangrongxiang on 2018/2/27 9:34
// File fgetc
//

#include <stdio.h>
#include <stdlib.h>

//fgetc - get a byte from a stream
int main() {
    FILE *file = NULL;
    file = fopen("test.txt", "r");
    if (file == NULL) {
        perror("fopen error");
    } else {
        while (!feof(file)) {
            int c = fgetc(file);
            if (c == EOF)
                break;
            printf("%c", c);
        }
        printf("\nread over \n");
    }
    if (fclose(file) == 0)
        printf("fclose file success\n");
    return EXIT_SUCCESS;
}