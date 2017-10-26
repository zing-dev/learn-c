//
// Created by zhangrongxiang on 2017/10/26 17:42
// File struct
//

#include <stdio.h>
#include <string.h>
#include <time.h>

struct PERSON {
    char name[10];
    int age;
    time_t time;
};
typedef struct PERSON person;

int main() {

    person p[10];
    memset(p, 0, sizeof(p[10]));
    int i;
    for (i = 0; i < 10; ++i) {
        time_t now;
        time(&now);
        strcpy(p[i].name, "fuck---");
        p[i].age = 10 + i;
        p[i].time = now;
    }

    for (i = 0; i < 10; ++i) {
        struct tm *tm1 = localtime(&p[i].time);
//        printf("%d\n",p[i].time);
        printf("name :%s, age :%d, time %d\n", p[i].name, p[i].age, tm1->tm_year + 1900);
//        printf("name :%s, age :%d, time \n",p[i].name,p[i].age);
    }

    return 0;
}