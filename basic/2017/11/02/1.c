//
// Created by zhangrongxiang on 2017/11/2 17:23
// File 1
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
} Person;

Person *getInstance();

int main() {
    Person *p = getInstance();
    p = getInstance();
    getInstance();
    getInstance();
    p->name = "haha";
    p = getInstance();
    printf("%s\n", p->name);
}

Person *getInstance() {
    static Person *person;
    if (person == NULL) {
        printf("NULL---->");
        person = malloc(sizeof(Person));
        person->name = "zing";
        return person;
    }
    return person;
}

