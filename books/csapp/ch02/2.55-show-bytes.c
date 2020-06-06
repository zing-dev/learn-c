//
// Created by zing on 5/17/2020.
//


/*
 * show-bytes.c
 */

#include <stdio.h>

typedef unsigned char *byte_pointer;
void size();
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

//大端模式，是指数据的高字节保存在内存的低地址中，而数据的低字节保存在内存的高地址中，这样的存储模式有点儿类似于把数据当作字符串顺序处理：地址由小向大增加，而数据从高位往低位放；这和我们的阅读习惯一致。
//小端模式，是指数据的高字节保存在内存的高地址中，而数据的低字节保存在内存的低地址中，这种存储模式将地址的高低和数据位权有效地结合起来，高地址部分权值高，低地址部分权值低。
int main(int argc, char *argv[]) {
    int test_num = 328;

    test_show_bytes(test_num);

    unsigned char c = 125;
    show_bytes(&c, 1);
    unsigned int i = 257;
    show_bytes((byte_pointer) &i, sizeof(int));
    size();
    return 0;
}

void size() {
    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(short));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(long));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));
    char *pChar = NULL;
    printf("%lu\n", sizeof(pChar));
    int *pInt = NULL;
    printf("%lu\n", sizeof(pInt));
}
