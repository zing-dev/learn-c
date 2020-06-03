//
// Created by zhangrongxiang on 2018/2/9 10:32
// File memcpy
//
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

struct {
    char name[40];
    int age;
} person, person_copy;

//C 库函数 void *memcpy(void *str1, const void *str2, size_t n) 从存储区 str2 复制 n 个字符到存储区 str1。
/* Copy N bytes of SRC to DEST.  */
int main() {
    char source[] = "once upon a midnight dreary...", dest[20];
    memcpy(dest, source, sizeof dest - 1);
    for (int i = 0; i < sizeof dest; ++i)
        putchar(dest[i]);
    printf("\n");

    // 设置分配的内存的有效类型为 int
    int *p = malloc(3 * sizeof(int));   // 分配的内存无有效类型
    int arr[3] = {5, 2, 3};
    memcpy(p, arr, 3 * sizeof(int));      // 分配的内存现在拥有有效类型
    for (int i = 0; i < 3; ++i) {
        printf("%d == %d \n", *(p + i), p[i]);
    }

///////////////////////////////////////////////////////////////////////////////////////////
// reinterpreting data
//    double d = 0.1;
//    int64_t n = *(int64_t*)(&d); // 严格别名使用违规
//    int64_t n;
//    memcpy(&n, &d, sizeof d); // OK
//    printf("\n%a is %" PRIx64 " as an int64_t\n", d, n);

////////////////////////////////////////////////////////////////////////////////////////////
    char myname[] = "Pierre de Fermat";

    /* using memcpy to copy string: */
    memcpy(person.name, myname, strlen(myname) + 1);
    person.age = 46;
    /* using memcpy to copy structure: */
    memcpy(&person_copy, &person, sizeof(person));
    printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);

    char str[] = "hello";
    char str2[] = "world world";
    strcpy(str2, str);
    printf("%s\n", str); //hello
    printf("%s\n", str2); //hello world

    char array[] = {51, 52, 53, 54, 0};
    printf("%s\n", array);
    printf("%lu\n", sizeof(array));
    char char_arr[sizeof(array)];
    memset(char_arr, 0, sizeof(char_arr));
    printf("%lu\n", strlen(char_arr));
    printf("%lu\n", sizeof(char_arr));
    memcpy(char_arr, array, sizeof(array));
    for (int i = 0; i < sizeof(char_arr); i++) {
        printf("%c %d\t", char_arr[i], char_arr[i]);
    }
    printf("\n");
    printf("%lu\n", strlen(char_arr));
    printf("%s\n", char_arr);
    return 0;
}