//
// Created by zhangrongxiang on 2017/12/13 12:47
// File listStack
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct SNODE {
    void *pelm;             //元素指针,数据域
    struct SNODE *next;     //指向下一栈节点
} StackNode;

typedef struct {
    StackNode *btm;      //栈底指针
    StackNode *top;      //指向栈顶元素
    int height;          //栈高度
} mStack;

//栈方法声明

mStack *CreateStack();     //创建一个空的栈
void DestroyStack(mStack *pStack);        //销毁栈
void ClearStack(mStack *pStack);          //清空栈内元素
int GetHeight(mStack *pStack);            //获取栈高度
int IsEmpty(mStack *pStack);              //检测是否为空栈
int Push(mStack *pStack, void *pdata);    //向栈内压入元素
int Pop(mStack *pStack, void **pdata);    //将栈顶元素出栈
int GetTop(mStack *pStack, void **pdata); //获取栈顶元素
void ForEachStack(mStack *pStack, void (*func)(void *pdata));      //从栈顶到栈底的每个元素依次执行 func 函数


//栈方法实现

/**
*  创建一个高度为 nHeight 的栈
*
* @return 返回指向新建的栈的指针
*/
mStack *CreateStack() {
    ///创建一个栈
    mStack *pStack = (mStack *) malloc(sizeof(mStack));

    ///令栈顶指向栈底指向NULL
    pStack->top = pStack->btm = NULL;

    ///初始栈高度为0
    pStack->height = 0;

    return pStack;
}

/**
* 销毁栈 pStack
*
* @param pStack 指向待销毁的栈的指针
*
* @return void
*/
void DestroyStack(mStack *pStack) {
    StackNode *tmp = pStack->top;

    ///释放栈内节点
    while (tmp != NULL) {
        printf("%d free\n",*(int *)tmp->pelm);
        tmp = tmp->next;
        free(pStack->top);
        pStack->top = tmp;
    }

    ///释放栈
    free(pStack);
}

/**
* 清空栈内元素
*
* pStack 指向待清空元素的栈的指针
*
* @return void
*/
void ClearStack(mStack *pStack) {
    StackNode *tmp = pStack->top;
    while (tmp != NULL) {
        printf("%d clear",*(int *)tmp->pelm);
        tmp = tmp->next;
        free(pStack->top);
        pStack->top = tmp;
    }
    pStack->top = pStack->btm = NULL;
    pStack->height = 0;
}

/**
*  获取栈当前高度
*
* @param 指向待获取高度的栈的指针
*
* @return 返回栈当前高度
*/
int GetHeight(mStack *pStack) {
    return pStack->height;
}

/**
* 检测是否为空栈
*
* @param pStack 指向待检测的栈的指针
*
* @return 若为空, 则返回 TRUE, 否则返回 FALSE
*/
int IsEmpty(mStack *pStack) {
    return pStack->height == 0 ? TRUE : FALSE;
}

/**
* 向栈内压入元素
*
* @param pStack 待压入元素的栈
* @param pdata 指向待压入栈元素的指针
*
* @return 返回成功入栈后栈的高度
*/
int Push(mStack *pStack, void *pdata) {
    ///创建一个栈节点
    StackNode *pNode = (StackNode *) malloc(sizeof(StackNode));

    ///为该节点赋值
    pNode->pelm = pdata;
    pNode->next = pStack->top;

    ///令栈顶指向最新节点
    pStack->top = pNode;

    ++pStack->height;
}

/**
* 将栈顶元素出栈
*
* @param pStack 指向待执行出栈操作的栈的指针
* @param pdata 接收弹出的元素的指针
*
* @return 出栈成功则返回出栈后栈的高度, 否则返回 -1
*/
int Pop(mStack *pStack, void **pdata) {
    ///检测是否为空栈
    if (pStack->top == pStack->btm)
        return -1;

    ///取得栈节点数据元素值
    *pdata = pStack->top->pelm;

    ///将栈顶指针向下退一位
    StackNode *p = pStack->top->next;
    printf("Pop %d free",*(int *) pStack->top->pelm);
    free(pStack->top);
    pStack->top = p;
    return --pStack->height;
}

/**
* 获取栈顶元素到 pt
*
* @param pStack 指向待弹出元素的栈的指针
* @param pdata 指向接收弹出的元素的指针
*
* @return 获取成功则返回栈顶元素的位置, 否则返回 -1
*
* @note 元素位置由 0 计起
*/
int GetTop(mStack *pStack, void **pdata) {
    ///检测是否为空栈
    if (pStack->height == 0)
        return -1;

    *pdata = pStack->top->pelm;

    return pStack->height - 1;
}

/**
* 从栈底到栈顶的每个元素依次执行 func 函数
*
* @param pStack 指向待处理的栈的指针
* @param func 需要执行的函数的指针
*
* @return void
*/
void ForEachStack(mStack *pStack, void (*func)(void *pt)) {
    StackNode *tmp = pStack->top;
    while (tmp != NULL) {
        func(tmp->pelm);
        tmp = tmp->next;
    }
}

void display(void *pn) {
    printf("%d ", *(int *) pn);
}

int main() {
    int a = 10, b = 20, c = 30, n = 0;
    void *pa = NULL;

    ///测试 CreateStack
    mStack *psk = CreateStack();

    ///测试 IsEmpty、GetHeight
    if (IsEmpty(psk) == TRUE)
        printf("Init Height = %d\n", GetHeight(psk));

    ///测试 Push
    printf("压入数字 10\n");
    Push(psk, &a);
    printf("压入数字 20\n");
    Push(psk, &b);
    printf("压入2元素后栈高度 = %d\n", GetHeight(psk));

    ///测试 Pop
    printf("\n测试 Pop:\n");
    n = Pop(psk, &pa);
    if (n != -1)
        printf("Pop = %d\n", *(int *) pa);

    n = Pop(psk, &pa);
    if (n != -1)
        printf("Pop = %d\n", *(int *) pa);

    n = Pop(psk, &pa);
    if (n != -1)
        printf("Pop = %d\n", *(int *) pa);
    else
        printf("Pop none.....\n");

    Push(psk, &a);
    ///测试清空栈
    printf("\n清空栈..");
    ClearStack(psk);
    printf("\n清空后栈高度 = %d\n", GetHeight(psk));

    ///测试 ForEachStack
    printf("\n压入3元素..");
    Push(psk, &a);
    Push(psk, &b);
    Push(psk, &c);
    printf("\n测试 ForEachStack: ");
    ForEachStack(psk, display);

    ///测试GetTop
    printf("\n测试GetTop:\n");
    n = GetTop(psk, &pa);
    if (n != -1)
        printf("GetTop = %d\n", *(int *) pa);

    ///再次输出当前栈高度
    printf("\n当前栈高度Height = %d\n", GetHeight(psk));

    ///测试 DestroyStack
    printf("\n销毁栈..\n");
    DestroyStack(psk);

    return 0;
}