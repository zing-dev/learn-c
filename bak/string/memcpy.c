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
int main() {

    int i = 0;
// 简单用法
    char source[] = "once upon a midnight dreary...", dest[4];
    memcpy(dest, source, sizeof dest);
    //printf("%s\n", dest);//未定义，不含\0
    //printf("length -> %d\n", (int) strlen(dest));
    for (i = 0; i < sizeof dest; ++i)
        putchar(dest[i]);

    printf("\n");
// 设置分配的内存的有效类型为 int
    int *p = malloc(3 * sizeof(int));   // 分配的内存无有效类型
    int arr[3] = {5, 2, 3};
    memcpy(p, arr, 3 * sizeof(int));      // 分配的内存现在拥有有效类型
    for (i = 0; i < 3; ++i) {
        printf("%d == %d \n", *(p + i), p[i]);
    }

///////////////////////////////////////////////////////////////////////////////////////////
// reinterpreting data
    double d = 0.1;
//    int64_t n = *(int64_t*)(&d); // 严格别名使用违规
    int64_t n;
    memcpy(&n, &d, sizeof d); // OK
    printf("\n%a is %" PRIx64 " as an int64_t\n", d, n);

////////////////////////////////////////////////////////////////////////////////////////////
    char myname[] = "Pierre de Fermat";

    /* using memcpy to copy string: */
    memcpy(person.name, myname, strlen(myname) + 1);
    person.age = 46;
    /* using memcpy to copy structure: */
    memcpy(&person_copy, &person, sizeof(person));
    printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);

    return 0;
}