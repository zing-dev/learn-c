//
// Created by zhangrxiang on 17-8-24.
//

#include <stddef.h>
#include <stdio.h>

struct address {
    char name[50];
    char street[50];
    int phone;
    long l;
};

int main() {
//    该宏返回值的类型是size_t，该类型成员的偏移值。
    /**
     * C库宏offsetof(type, member-designator)
     * 结果在一个常数整数 size_t 类型是一个结构成员的结构从一开始的字节偏移。
     * 构件由下式给出部件指示符，是由于在不同的结构的名称。
     */
    //name offset = 0 byte in address structure.
    printf("name offset = %ld byte in address structure.\n", offsetof(
    struct address, name));

    //street offset = 50 byte in address structure.
    printf("street offset = %ld byte in address structure.\n", offsetof(
    struct address, street));

    //phone offset = 100 byte in address structure.
    printf("phone offset = %ld byte in address structure.\n", offsetof(
    struct address, phone));

    //l offset = 104 byte in address structure.
    printf("l offset = %ld byte in address structure.\n", offsetof(
    struct address, l));

    return (0);
}