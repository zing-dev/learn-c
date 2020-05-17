//
// Created by zing on 5/17/2020.
//

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char string[32] = {};
    int i = sprintf(string, "hello world,hello %s","c");
    printf("%d\n", i);
    printf("%s\n", string);
    printf("%lu\n", strlen(string));
    printf("%lu\n", sizeof(string));
    return 0;
}
