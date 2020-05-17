//
// Created by zhangrongxiang on 2017/12/14 9:15
// File arrayQueue
//

/**
* C语言顺序结构队列的实现
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Point2D {
    int x;
    int y;
} ElemType;      //元素结构

typedef struct {
    ElemType **rear;    //队尾
    ElemType *front;    //队头
    int len;            //队列长度
    int size;           //队列总容量
} ArrQueue;      //队列结构

//声明队列方法

ArrQueue *CreateQueue(int nLen);          //创建初始长度为 nLen 队列
void DestroyQueue(ArrQueue *pQueue);      //销毁队列pQueue
void ClearQueue(ArrQueue *pQueue);        //清空队列内元素
int GetLength(ArrQueue *pQueue);          //获取队列长度
int GetSize(ArrQueue *pQueue);            //获取队列总容量
int IsEmpty(ArrQueue *pQueue);            //检测队列是否为空
int GetHead(ArrQueue *pQueue, ElemType **pe);      //获取队头元素
int EnQueue(ArrQueue *pQueue, ElemType *pe);       //将元素插入到队尾
int DeQueue(ArrQueue *pQueue, ElemType **pe);      //将队头元素出队
void ForEachQueue(ArrQueue *pQueue, void (*func)(ElemType *pe));      //从对尾到队头依次执行 func

//队列方法实现

/**
* 创建初始长度为 nLen 的队列
*
* @param nLen 队列的初始长度
*
* @return 返回指向新创建的队列的指针
*/
ArrQueue *CreateQueue(int nLen) {
    ArrQueue *pQueue = (ArrQueue *) malloc(sizeof(ArrQueue));
    pQueue->rear = (ElemType **) calloc(nLen, sizeof(ElemType **));
    pQueue->front = pQueue->rear[0];
    pQueue->len = 0;
    pQueue->size = nLen;

    return pQueue;
}

/**
* 销毁队列
*
* @param pQueue 指向待销毁的队列的指针
*/
void DestroyQueue(ArrQueue *pQueue) {
    free(pQueue->rear);
    free(pQueue);

    pQueue = NULL;
}

/**
* 清空队列内元素
*/
void ClearQueue(ArrQueue *pQueue) {
    pQueue->front = pQueue->rear[0];

    pQueue->len = 0;
}

/**
* 获取队列长度
*
* @param 指向待获取长度的队列的指针
*
* @return 返回队列当前长度
*/
int GetLength(ArrQueue *pQueue) {
    return pQueue->len;
}

/**
* 获取队列总容量
*
* @param pQueue 指向待获取容量的队列
*
* @return 返回队列当前总容量
*/
int GetSize(ArrQueue *pQueue) {
    return pQueue->size;
}

/**
* 检测队列是否为空
*
* @param pQueue 指向待检测的队列
*
* @return 若为空, 则返回 TRUE, 否则返回 FALSE
*/
int IsEmpty(ArrQueue *pQueue) {
    return pQueue->len == 0 ? TRUE : FALSE;
}

/**
* 获取队头元素
*
* @param pQueue 指向待获取队头元素的队列
*
* @param pe 指向接收元素的指针的指针
*
* @return 返回队头在队列中的位置(位置由 0 计起)
*/
int GetHead(ArrQueue *pQueue, ElemType **pe) {
    if (pQueue->len == 0) {
        *pe = NULL;
        return -1;
    }

    *pe = pQueue->rear[pQueue->len - 1];

    return pQueue->len - 1;
}

/**
* 将元素 pe 插入到队尾
*
* @param pQueue 指向待插入元素的队列
* @param pe 指向待插入的元素
*
* @return 返回成功插入后队列的长度
*/
int EnQueue(ArrQueue *pQueue, ElemType *pe) {
    ///检测是否需要扩容
    if (pQueue->len == pQueue->size) {   //需要扩容
        pQueue->rear = realloc(pQueue->rear, 2 * pQueue->size * sizeof(ElemType *));
        pQueue->size = 2 * pQueue->size;
    }

    int i = 0;
    for (i = pQueue->len; i > 0; --i) {
        pQueue->rear[i] = pQueue->rear[i - 1];
    }
    pQueue->rear[0] = pe;
    pQueue->front = pQueue->rear[pQueue->len];

    return ++pQueue->len;
}

/**
* 将队头元素出队
*
* @param pQueue 指向待出队的队列
* @param pe 指向接收元素的指针的指针
*
* @return 成功出队则返回出队后队列的长度, 否则返回 -1
*/
int DeQueue(ArrQueue *pQueue, ElemType **pe) {
    if (pQueue->len == 0) {
        *pe = NULL;
        return -1;
    }
    *pe = pQueue->front;
    --pQueue->len;
    pQueue->front = pQueue->rear[pQueue->len - 1];

    return pQueue->len;
}

/**
* 从队尾到队头每个元素一次执行 func
*
* @param pQueue 指向待处理的队列
* @param  func 回调函数指针
*/
void ForEachQueue(ArrQueue *pQueue, void (*func)(ElemType *pe)) {
    int i = 0;
    for (i = 0; i < pQueue->len; ++i) {
        func(pQueue->rear[i]);
    }
}

//测试
void display(ElemType *pe) {
    printf("(%d,%d) ", pe->x, pe->y);
}

int main() {
    ElemType t1 = {10, 20};
    ElemType t2 = {30, 40};
    ElemType t3 = {50, 60};
    ElemType t4 = {70, 80};
    ElemType t5 = {99, 99};
    ElemType t6 = {99, 99};
    ElemType t7 = {99, 939};
    ElemType t8 = {99, 99};
    ElemType t9 = {919, 99};
    ElemType t10 = {99, 99};
    ElemType t11 = {99, 99};
    ElemType t12 = {959, 949};
    ElemType t13 = {939, 929};
    ElemType t14 = {919, 199};

    ///测试 CreateQueue
    ArrQueue *pque = CreateQueue(3);

    ///测试入队
    EnQueue(pque, &t1);
    EnQueue(pque, &t2);
    EnQueue(pque, &t3);
    EnQueue(pque, &t4);
    EnQueue(pque, &t5);
    EnQueue(pque, &t6);
    EnQueue(pque, &t7);
    EnQueue(pque, &t8);
    EnQueue(pque, &t9);
    EnQueue(pque, &t10);
    EnQueue(pque, &t11);
    EnQueue(pque, &t12);
    EnQueue(pque, &t13);
    EnQueue(pque, &t14);

    ///测试 ForEachQueue
    ForEachQueue(pque, display);

    ///测试 IsEmpty、GetSize、GetLength
    if (IsEmpty(pque) != TRUE)
        printf("\n队列总容量:%d, 当前长度:%d\n", GetSize(pque), GetLength(pque));

    ElemType *p;
    DeQueue(pque, &p);
    printf("当前出队:(%d,%d), 剩余队列长为:%d\n", p->x, p->y, GetLength(pque));
    DeQueue(pque, &p);
    printf("当前出队:(%d,%d), 剩余队列长为:%d\n", p->x, p->y, GetLength(pque));
    DeQueue(pque, &p);
    printf("当前出队:(%d,%d), 剩余队列长为:%d\n", p->x, p->y, GetLength(pque));

    ///测试全部出队
    printf("\n测试全部出队:\n");
    while (DeQueue(pque, &p) != -1) {
        printf("当前出队:(%d,%d), 剩余队列长为:%d\n", p->x, p->y, GetLength(pque));
    }

    ///测试 ClearQueue
    printf("\n再次入队2元素..\n");
    EnQueue(pque, &t1);
    EnQueue(pque, &t2);
    ForEachQueue(pque, display);
    printf("\n清空队列..\n");
    ClearQueue(pque);
    printf("队列总容量:%d, 当前长度:%d\n", GetSize(pque), GetLength(pque));

    ///测试 GetHead
    printf("\n再次入队2元素..\n");
    EnQueue(pque, &t1);
    EnQueue(pque, &t2);
    ForEachQueue(pque, display);
    GetHead(pque, &p);
    printf("\n获取队头元素:(%d,%d)\n", p->x, p->y);
    printf("队列总容量:%d, 当前长度:%d\n", GetSize(pque), GetLength(pque));

    ///销毁队列
    DestroyQueue(pque);

    return 0;
}