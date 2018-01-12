//
// Created by zhangrongxiang on 2018/1/12 17:57
// File fwrite_struct
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int age;
    char name[30];
} people;

int main() {
    FILE *pFile;
    int i;
    people per[3];
    per[0].age = 20;
    strcpy(per[0].name, "li");
    per[1].age = 18;
    strcpy(per[1].name, "wang");
    per[2].age = 21;
    strcpy(per[2].name, "zhang");

    if ((pFile = fopen("myfile.txt", "wb")) == NULL) {
        printf("cant open the file");
        exit(0);
    }

    for (i = 0; i < 3; i++) {
        if (fwrite(&per[i], sizeof(people), 1, pFile) != 1)
            printf("file write error\n");
    }
    fclose(pFile);
    return 0;
}

