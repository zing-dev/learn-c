//
// Created by zhangrxiang on 17-8-15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//指针的运算

void one() {
    int a = 5;
    int *p = &a;

    int b = *p;
    *p = 9;

    printf("p = %p, &a = %p, &p = %p\n", p, &a, &p);
    // a = 9, b = 5
    printf("a = %d, b = %d\n", a, b);

}

void func(char **p, int num) {
    *p = (char *) malloc(num);
}

void two() {
    char *str = NULL;
    func(&str, 20);
    printf("str length is %ld\n", sizeof(str));
    strcpy(str, "hello world!");
    printf("%s\n", str);
    free(str);

}

void three() {
    int a[] = {18, 17, 16, 15, 14, 13, 12, 11};
    int *start = a, *end = &a[7];
    printf("address start = %p, end = %p\n", start, end);
    printf("*(start+2) = %d, *(--end) = %d\n", *(start + 2), *(--end));
    printf("(--end) - (start+2) = %ld\n", (--end) - (start + 2));
}

int main() {
//    two();
    three();
    return 0;
}