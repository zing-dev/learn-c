//
// Created by zhangrongxiang on 2018/1/22 11:11
// File 1
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zconf.h>

struct STUDENT{
    char *name;
};

struct STUDENT *init(){
    struct STUDENT *student = malloc(sizeof(struct STUDENT));
    return student;
}
int randNum(){
    srand((unsigned int) time(0));
    return rand() % 2 == 0;
}

struct STUDENT *student;
int main(){
//    for (int i = 0; i < 10; ++i) {
//        sleep(1);
//        printf("%d\n",randNum());
//    }
    if(student == NULL){
        printf("null\n");
    } else{
        printf("not null\n");
    }
    if (randNum()){
        student = init();
        student->name = "zing";
    }

    if(student == NULL){
        printf("null\n");
    } else{
        printf("not null\n");
        printf("%s\n",student->name);
        free(student);
    }
}