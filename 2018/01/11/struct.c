//
// Created by zhangrongxiang on 2018/1/11 17:45
// File struct
//
#include <stdio.h>

struct {
    char *name;
    int age;

    int *(*p)(int *, int *);

    void *(*setAge)(struct Student *student, int age);
}Student;

int *max(int *pa, int *pb) {
    if (*pa >= *pb)
        return pa;
    else
        return pb;
}

void *setAge(struct Student *student, int age) {
    student->age = age;
}

int main() {
    struct Student *student;
    setAge(&student, 10);
    student->setAge = setAge;
    student->setAge(&student, 20);
    printf("age %d\n", student->age);
    int a = 10, b = 20;
    student->p = max;
    int *c = student->p(&a, &b);
    printf("c %d\n", *c);
    return 0;
}