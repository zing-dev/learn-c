//
// Created by zhangrongxiang on 2018/2/22 11:41
// File flag
//

#include <stdio.h>
#include <mem.h>

#define flag
#define flag2 flag

#define out
#define in

void in input(in char *string) {
    printf("%s\n", string);
}

void out output(out char *string) {
    char *str = "Hello World\n";
    memcpy(string, str, strlen(str));
}

void flag flag test() {
    printf("---test---\n");
}

void flag2 t2() {
    printf("---test2---\n");
}

int main(flag) {
    test();
    t2();
    flag;
    flag2
    input("hello world");//hello world
    char str[16];
    output(str);
    printf("%s\n", str);//Hello World
    return 0;
}