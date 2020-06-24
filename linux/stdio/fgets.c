//
// Created by zing on 2018/2/27 9:51
// File fgets
//

#include <stdio.h>
#include <stdlib.h>

//fgets - get a string from a stream

int main() {
    char buf[16];
    FILE *file = fopen("fgets.c", "w+");
    if (file == NULL) {
        fprintf(stderr, "fopen file error\n");
        exit(EXIT_FAILURE);
    } else {
        fputs("hello world",file);
        fseek(file,0,SEEK_SET);
        while (!feof(file)) {
            char *string = fgets(buf, sizeof(buf), file);
            printf("%s", string);
        }
        printf("\nfgets over \n");
    }
    fclose(file);
    return EXIT_SUCCESS;
}