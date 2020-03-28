//
// Created by zhangrongxiang on 2018/2/8 16:57
// File memcmp
//

#include <stdio.h>
#include <string.h>

//C 库函数 int memcmp(const void *str1, const void *str2, size_t n)) 把存储区 str1 和存储区 str2 的前 n 个字节进行比较。
//比较按字典序进行。
typedef struct {
    char *name;
} Stu;

int main() {
    char *str = "abc";
    char *str2 = "abC";
    int cmp = memcmp(str, str2, strlen(str) > strlen(str2) ? strlen(str) : strlen(str2));
    printf("%d\n", cmp); // windows mingw -> 1  linux gcc 32

    int i = 0;
    int i2 = 10;
    cmp = memcmp(&i, &i2, sizeof(int));
    printf("%d\n", cmp);//windows mingw -> -1  linux gcc -10
    printf("%d\n", (int) sizeof(short));//2

    Stu stu = {.name = "zing"};
    Stu stu2 = {.name = "zing"};
    Stu stu3 = {.name = "Zing"};
    Stu stu4 = {.name = "aing"};

    /***********************************************/
    printf("%d\n", (int) sizeof(Stu)); //8
    printf("%d\n", (int) sizeof(stu.name)); //8
    printf("%d\n", (int) strlen(stu.name)); //4
    printf("%d\n", (int) sizeof(char *)); //8
    printf("%d\n", (int) sizeof(int *)); //8
    printf("%d\n", (int) sizeof(long *)); //8
    /***********************************************/

    cmp = memcmp(&stu, &stu2, sizeof(Stu));
    printf("struct %d \n", cmp);//0
    cmp = memcmp(&stu, &stu3, sizeof(Stu));
    //printf("struct %d \n", cmp);//-5 具有不确定性 --> 内存对齐知识
    cmp = memcmp(stu.name, stu3.name, sizeof(Stu));
    printf("struct %d \n", cmp); // windows mingw -> -1  linux gcc 32
    cmp = memcmp(stu.name, stu4.name, sizeof(Stu));
    printf("struct %d \n", cmp); // windows mingw -> -1  linux gcc 25

    cmp = memcmp(&"abC", &"abc", sizeof(char *));
    printf("%d\n", cmp);//-32
    printf("a -> %d;A -> %d \n", 'a', 'A');//a -> 97;A -> 65
    printf("z -> %d;a -> %d \n", 'z', 'a');//z -> 122;a -> 97
    return 0;
}