//
// Created by zing on 5/20/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <utils.h>

/*
 *
   The  realloc()  function  changes the size of the memory block pointed to by ptr to size bytes.  The contents
   will be unchanged in the range from the start of the region up to the minimum of the old and new  sizes.
   If the new size is larger than the old size, the added memory will not be initialized.
   If ptr is NULL, then the call is equivalent to malloc(size), for all values of size;
   if size is equal to zero, and ptr  is  not  NULL, then  the call is equivalent to free(ptr).
   Unless ptr is NULL, it must have been returned by an earlier call
   to malloc(), calloc(), or realloc().  If the area pointed to was moved, a free(ptr) is done.
 */

void realloc1() {
    int *p = (int *) malloc(sizeof(int *));
    printf("%d\n", *p);
    p = realloc(p, sizeof(int) * 3);
    p[1] = 20;
    printf("%d\n", *(p + 1));
    p[2] = 30;
    printf("%d\n", *(p + 2));
    printf("%d\n", *(p + 3));
}

void realloc2() {
    char *str = (char *) malloc(6);;
    strcpy(str, "hello");
    str = realloc(str, sizeof(char) * 10);
    printf("length:%zd, %s\n", strlen(str), str);
    strcat(str, " world");
    printf("length:%zd, %s\n", strlen(str), str);
    int index = 0;
    char *tmp = str;
    while (*tmp) {
        printf("%c\t", *tmp);
        tmp++;
        index++;
    }
    ln();
    printf("%d\n", index);

    str[strlen(str)] = 'A';
    strcat(str, "Hello Clang");
    printf("length:%zd, %s\n", strlen(str), str);
    tmp = str;
    while (*tmp) {
        printf("%c\t", *tmp);
        tmp++;
        index++;
    }
    ln();
}

int main(int argc, char *argv[]) {
    realloc1();
    realloc2();
    return 0;
}
