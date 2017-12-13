//
// Created by zhangrongxiang on 2017/12/13 10:20
// File stack
//
#include <stdio.h>
#include <stdlib.h>

//预定义常量
#define OK 1
#define OVERFLOW -2
#define ERROR 0

#define STACK_INIT_SIZE 100 //存储空间的初始分配量
#define STACKINCREMENT 10   //存储空间的分配增量stackincrement

typedef int SElemType;

//栈的顺序存储表示
typedef struct {
    SElemType *base;//在栈构造之前和销毁后值是NULL
    SElemType *top;
    int stacksize; //已分配的存储空间
} SqStack;

//栈的初始化操作

int InitStack(SqStack *S) {
    S->base = (int *) malloc(STACK_INIT_SIZE * sizeof(SqStack));
    if (!S->base) {
        exit(OVERFLOW);//分配空间失败
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//进栈操作
int Push(SqStack *S, int e) {
    if (S->top - S->base >= S->stacksize) {//栈空间已经满
        S->base = (int *) realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SqStack));
        if (!S->base) {
            exit(OVERFLOW);//分配失败
        }
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;
    return OK;
}

//出栈
int Pop(SqStack *S, int *e) {
    if (S->top != S->base) {
        *e = *(--S->top);
        return OK;
    } else {
        exit(OVERFLOW);
    }
}

//得到顶部元素
void GetElem(SqStack S, int *e) {
    if (S.top != S.base) {
        *e = *(S.top - 1);
    } else {
        exit(OVERFLOW);
    }
}

//打印出栈各个元素
void PrintfStack(SqStack S) {
    while (*(S.top - 1) && S.top != S.base) {//证明不是空栈,且有值
        S.top = S.top - 1;
        printf("%d ", *S.top);
    }
    printf("\n");
}

int IsEmpty(SqStack S){
    return S.top == S.base;
}
int main() {
    int e, i;
    int TextData[6] = {9, 2, 8, 1, 7, 6};
    SqStack Sa, Sb;
    InitStack(&Sa);//初始化栈Sa;
    for (i = 0; i < 6; i++) {
        Push(&Sa, TextData[i]);
    }
    printf("**************栈基本操作*************\n");
    //初始化数据
    printf("初始化后的Sa：");
    PrintfStack(Sa);

    //得到栈顶元素
    GetElem(Sa, &e);
    printf("Sa栈顶元素是：%d\n", e);

    //初始化数据
    printf("顶部出栈后Sa：");
    Pop(&Sa, &e);
    PrintfStack(Sa);
    Push(&Sa,1);
    Push(&Sa,124);
    Push(&Sa,102);
    Push(&Sa,12);
    Push(&Sa,121);
    printf("all: ");
    PrintfStack(Sa);
    int top;
    printf("出栈: ");
    while (!IsEmpty(Sa)){
        Pop(&Sa,&top);
        printf("%d ",top);
    }
    printf("\n");
}