//
// Created by zhangrongxiang on 2017/10/30 9:52
// File struct
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void createPerson(Person **pPerson);

typedef struct PERSON {
    char *name;
    int age;
} Person;

void createPerson();

void createPerson2(Person *person);

int main() {
//    Person *p[] =
//            createPerson(10);
    Person *person = NULL;
    createPerson2(person);
    int i = 0;
//    printf("%d\n", sizeof(person));
//    for (; i < 10; ++i) {
//        printf("%s -- \n",*(person + i * sizeof(person))->name);
//    }
}

void createPerson2(Person *person) {
//    Person person[length];
    int length = 10;
//    person = (Person **)malloc(sizeof(person) * 10);
    Person *p2 = malloc(sizeof(Person) * 1000);
    int i = 0;
    char *Ptr = NULL;
    Ptr = (char *) malloc(100 * sizeof(char));
    printf("-------->>  %d\n", sizeof(p2));
    printf("-------->>  %d\n", sizeof(Ptr));
//    printf("%d\n", sizeof(person));

//    for (; i < length; ++i) {\
//        strcpy(person[i].name,"zing");
//        person[i].age = 10 + length;
//    }
//    for (; i < 10; ++i) {
//        printf("%s -- \n",*(person + i * sizeof(person))->name);
//    }
}

void createPerson(int length) {
    Person person[length];
    int i = 0;
    for (; i < length; ++i) {
        strcpy(person[i].name, "zing");
        person[i].age = 10 + length;
    }
//    return person;
}