//
// Created by zhangrongxiang on 2017/10/30 10:46
// File s1
//

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdint.h>

#define LEN sizeof(struct Matrix)
struct Matrix {
    int serial;
    int row;
    int coloum;

};
typedef uint32_t UL;

void two(struct Matrix *matrix[]);

void three(char **string);

int main() {

    char *string = NULL;
    three(&string);
    printf("%s\n", string);
    printf("--------> UL %d\n", sizeof(UL));

//    struct Matrix *matrix[] = {0};
//    two(matrix);
//    int i = 0;
//    for (; i < 10; ++i) {
//        printf("--->  %d\n",matrix[i]->serial);
//    }

    return 0;
}

void three(char **string) {
//    *string = (char *) malloc(sizeof(char) * 1000);
    *string = "ssssssssssssssssssssssssssssssssssssssssssssssssss";
}

void two(struct Matrix *matrix[]) {
//    matrix = (struct Matrix*) malloc(sizeof(struct Matrix) * 10);
//    int i = 0;
//    for (; i < 10; ++i) {
//        matrix[i]->coloum = 1;
//        matrix[i]->row = 2;
//        matrix[i]->serial = 3;
//    }
}

void one() {
    int len, i;
    struct Matrix *pArr;
    printf("请输入数组的元素个数：\n");
    scanf("%d", &len);
    pArr = (struct Matrix *) malloc(len * LEN);//为结构体分配存储空间
    printf("为数组赋值：\n");
    for (i = 0; i < len; i++) {

        pArr[i].serial = i + 1;
        printf("第%d个元素：", pArr[i].serial);
        scanf("%d %d", &pArr[i].row, &pArr[i].coloum);
    }
    printf("数组输出：\n");
    for (i = 0; i < len; i++) {
        printf("%4d%4d%4d\n", pArr[i].serial, pArr[i].row, pArr[i].coloum);
    }
}