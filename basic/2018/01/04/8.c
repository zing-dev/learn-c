//
// Created by zhangrongxiang on 2018/1/4 17:04
// File 8
//

#include <stdio.h>

typedef struct STU {
    int id;
    char *name;
} Stu;

int main() {

    Stu *stu = NULL;
    struct STU *stu1;
    printf("%d\n", (struct stu *) 2);
    printf("%d\n", (struct stu1 *) 3);
    printf("%d\n", (int *) 4);
    printf("%d\n", (char *) 5);
    printf("%d\n", (char **) 6);

}