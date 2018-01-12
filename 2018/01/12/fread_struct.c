//
// Created by zhangrongxiang on 2018/1/12 17:59
// File fread_struct
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int age;
    char name[30];
} people;

int main() {
    FILE *fp;
    people per;
    if ((fp = fopen("myfile.txt", "rb")) == NULL) {
        printf("cant open the file");
        exit(0);
    }

    while (fread(&per, sizeof(people), 1, fp) == 1)   //如果读到数据，就显示；否则退出
    {
        printf("%d %s\n", per.age, per.name);
    }
    return 0;.
}

