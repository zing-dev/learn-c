//
// Created by zhangrongxiang on 2017/12/12 10:54
// File staticlink
//

/*************************************
                静态链表
数据结构：每个数组节点都有值和游标.
游标表示下一个节点，节点分为已用节点和备用节点
第一个节点和最后节点保留：
第一个节点游标表示备用节点起始位置
最后一个节点游标表示已用节点的起始位置
已用节点的最后一个元素的游标指向0，表示末尾。
*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ERROR 0
#define OK 1
#define MAX 100     //声明数组的最大长度

typedef int Status, ElemType;
typedef struct {
    int data;    //数据
    int cur;     //游标
} component, staticlink[MAX]; //定义结构体数组

/**********************************
         初始化链表
输入值：链表的指针
输出值：状态码
功能：  将所以节点的游标指向后一个节点
 ***********************************/
Status initLink(staticlink space) {
    int i;
    for (i = 0; i < (MAX - 1); i++) {  //遍历所有节点
        space[i].cur = i + 1;     //将节点的游标指向下个节点
    }
    space[MAX - 1].cur = 0;    //最后一个节点的游标指向第一个节点
    return OK;
}

/*********************************
         分配备用空间
输入值：链表的指针
输出值：备用节点的下标
功能：  将备用节点的分配出来使用
 *********************************/
int mallocSpace(staticlink space) {
    int i;
    i = space[0].cur; //取出第一个备用节点
    if (space[0].cur)  //如果取出成功
        space[0].cur = space[i].cur;    //第一个节点的指针往后移动
    return i;
}

/********************************
         获取长度
输入值：链表的指针
输出值：长度值
功能：  将链表中已用的节点个数返回
 ********************************/
int getLength(staticlink space) {
    int mov = MAX - 1;
    int j = 0;
    while (space[mov].cur) {
        //遍历所有已用节点
        mov = space[mov].cur;
        j++;
    }
    return j;
}

/*********************************
          创建值
输入值：链表的指针，初始值个数
输出值：状态码
功能：  为链表初始指定个数的随机值
 *********************************/
Status createValue(staticlink space, int num) {
    srand(time(0));
    int i, mov = MAX - 1;
    space[mov].cur = 1;
    for (i = 0; i < num; i++) {
        mov = space[mov].cur;            //移动游标
        space[mov].data = rand() % 100 + 1;  //初始化随机值
    }
    space[0].cur = space[mov].cur;     //第一节点游标指向备用节点
    space[mov].cur = 0;                  //最后一个已用节点指向第一个节点
    return OK;
}

/*********************************
          插入节点
输入值：链表的指针，插入位置(从1开始)，插入位置
输出值：状态码
功能：  在指定的位置插入指定的值
 *********************************/
Status insertNode(staticlink space, int index, ElemType e) {
    int new_space, mov, i;
    if (index < 1 || index > getLength(space))
        return ERROR;  //不可以超过已用节点个数

    mov = MAX - 1;
    new_space = mallocSpace(space);

    if (new_space) {
        space[new_space].data = e;   //创建新节点
        for (i = 1; i < index; i++)//定位插入节点的前一节点
            mov = space[mov].cur;

        space[new_space].cur = space[mov].cur;    //连后
        space[mov].cur = new_space; //接前
        return OK;
    }
    return ERROR;
}

/************************************
          删除节点
输入值：链表的指针，删除位置(从1开始)
输出值：状态码
功能：  删除指定的节点
 ************************************/
Status deleteNode(staticlink space, int index) {
    if (index < 1 || index > getLength(space))return ERROR;
    int mov, next, i;

    mov = MAX - 1;
    for (i = 1; i < index; i++)        //定位删除节点的前一节点
        mov = space[mov].cur;

    next = space[mov].cur;      //获取被删节点
    space[mov].cur = space[next].cur; //前一节点连接被删节点的游标
    freeNode(space, next);      //释放被删节点
    return OK;
}

/***********************************
          释放节点
输入值：链表的指针，释放节点的位置
输出值：状态码
功能:   将已用节点释放成备用节点
 ***********************************/
Status freeNode(staticlink space, int target) {
    space[target].cur = space[0].cur;        //释放节点连接第一备用节点
    space[0].cur = target;     //第一节点连接释放节点
    return OK;
}

/**********************************
          输出链表
输入值：链表的指针
输出值：状态码
功能：  将链表的值一一输出
 **********************************/
Status printLink(staticlink space) {
    int mov = MAX - 1;
    while (space[mov].cur) {
        mov = space[mov].cur;
        printf("[%d] ", space[mov].data);
    }
    printf("\n");
    return OK;
}

int main() {
    int num, value, index;
    staticlink L;
    initLink(L);

    printf("[create]enter num:");
    scanf("%d", &num);
    createValue(L, num);
    printLink(L);

    printf("[insert]enter index:");
    scanf("%d", &index);
    printf("[insert]enter value:");
    scanf("%d", &value);
    insertNode(L, index, value);
    printLink(L);

    printf("[delete]enter index:");
    scanf("%d", &index);
    deleteNode(L, index);
    printLink(L);
    return 0;
}