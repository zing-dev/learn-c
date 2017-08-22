//
// Created by zhangrongxiang on 2017/8/22 17:01.
// Copyright (c) 2017 ZRX . All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#define INIT(t, ...) { (t) = malloc(sizeof(*(t)));*(t) = (typeof(*(t))){ __VA_ARGS__ }; printf("%s\n",t->c);}
typedef struct test t;
typedef struct test_t tt;

struct test_t{
    int i;
    char* ch;
};
struct test {
    int	i;
    char c[10];
    tt tt1;
};

int main()
{
    t *t1;
    INIT(t1,
         .i = 10,
         .c = "WHAT",
         .tt1 = {
             .i = 100,
             .ch = "hello"
         }
    );
    printf("%d\n",t1->i);
    printf("%s\n",t1->c);
    printf("%s\n",t1->tt1.ch);
    typeof(t1) t2;
    t2 = malloc(sizeof(*t2));
    t2->tt1.ch = "SHIT";
    printf("%s\n",t2->tt1.ch);
}
