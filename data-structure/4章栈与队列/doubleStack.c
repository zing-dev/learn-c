//
// Created by zhangrongxiang on 2017/12/13 12:23
// File doubleStack
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

/**
 * 共享栈，即是两个栈使用同一段存储空间。
 * 第一个栈从数组头开始存储，第二个栈从数组尾开始，两个栈向中间拓展。
 * 当top1+1==top2或者top1==top2-1时，即staock overflow!.
 * 与普通栈一样，共享栈出栈入栈的时间复杂度仍为O(1).
 */
typedef struct shareStack {
    int data[MAXSIZE];
    int top1;
    int top2;
} shareStack;

void createStack(shareStack *ss, int n, int m);

void showStack(shareStack *ss);

int Push(shareStack *ss, int num, int flag);

int Pop(shareStack *ss, int flag);

int main() {
    shareStack *ss = (shareStack *) malloc(sizeof(shareStack));

    createStack(ss, 3, 4);
    showStack(ss);

    if (Push(ss, 6, 1))
        showStack(ss);

    if (Push(ss, 4, 2))
        showStack(ss);

    int n;
    n = Pop(ss, 1);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    n = Pop(ss, 2);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    n = Pop(ss, 1);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    n = Pop(ss, 1);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    n = Pop(ss, 1);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    n = Pop(ss, 1);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    n = Pop(ss, 1);
    if (n >= 0)
        printf("the pop num is:%d\n", n);

    showStack(ss);

    return 0;
}

void createStack(shareStack *ss, int n, int m) {
    int i;
    ss->top1 = -1;
    ss->top2 = MAXSIZE;
    for (i = 0; i < n; i++) {
        ss->top1++;
        ss->data[ss->top1] = 2 * i + 1;
    }
    for (i = 0; i < m; i++) {
        ss->top2--;
        ss->data[ss->top2] = 2 * i + 1;
    }
}

void showStack(shareStack *ss) {
    int i;
    for (i = 0; i < ss->top1 + 1; i++) {
        printf("%d->", ss->data[i]);
    }
    printf("top1-----top2");
    for (i = ss->top2; i < MAXSIZE; i++) {
        printf("<-%d", ss->data[i]);
    }
    printf("\n");
}

int Push(shareStack *ss, int num, int flag) {
    if (ss->top1 + 1 == ss->top2)
        return 0;
    if (flag == 1) {
        ss->data[++ss->top1] = num;
        return 1;
    } else if (flag == 2) {
        ss->data[--ss->top2] = num;
        return 1;
    }
    return 0;
}

/**
 * 该数据，仅存的是非负数，因此如果想要存储更复杂的操作，
 * 可以在判断栈空时，换一种方式，即可。
 *
 * @param ss
 * @param flag
 * @return
 */
int Pop(shareStack *ss, int flag) {
    if (flag == 1) {
        if (ss->top1 == -1)
            return -1;
        return ss->data[ss->top1--];
    } else if (flag == 2) {
        if (ss->top2 == MAXSIZE)
            return -1;
        return ss->data[ss->top2++];
    }
    return -1;
}
