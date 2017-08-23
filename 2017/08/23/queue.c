//
// Created by zhangrongxiang on 2017/8/23 10:06.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct queue
{
    Node *head;
    Node *tail;
} Queue;

void InitQueue(Queue *);
void EnQueue(Queue *, int);
int DeQueue(Queue *queue);
void PrintQueue(Queue *queue);
int IsNull(Queue *queue);
void DelQueue(Queue *queue);

void DelQueue(Queue *queue)
{
    while (queue->head != queue->tail) {
        DeQueue(queue);
    }

}

void PrintQueue(Queue *queue)
{
    if (IsNull(queue)) {
        printf("empty queue.\n");
        return;
    }
    Node *curNode = queue->head->next;
    while (curNode) {
        if (curNode->next != NULL) {
            printf("%d==>", curNode->data);
        }
        else {
            printf("%d ", curNode->data);

        }
        curNode = curNode->next;
    }
    printf("\n");

}

void InitQueue(Queue *queue)
{
    queue->head = queue->tail = (Node *) malloc(sizeof(Node));
    queue->tail->data = -1;
//    queue->head = queue->tail;
    queue->tail->next = NULL;
}
//入队列
void EnQueue(Queue *queue, int data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    queue->tail->next = newNode;//2b 这里漏了。。。导致链表连不上去
    queue->tail = newNode;
}

int DeQueue(Queue *queue)
{
    int popValue = queue->head->data;
    Node *popNode = queue->head;
    queue->head = queue->head->next;
    free(popNode);
    return popValue;
}
//1 means Null
int IsNull(Queue *queue)
{
    return (queue->head == queue->tail);
}

int main(void)
{
    printf("Hello World!..................................................\n");
    Queue queue;
    InitQueue(&queue);
    //printf("IsNull = %d\n", IsNull(&queue));
    printf("enque 4 times and the elems: 1, 2, 3, 4\n");
    EnQueue(&queue, 1);
    //printf("IsNull = %d\n", IsNull(&queue));
    EnQueue(&queue, 2);
    EnQueue(&queue, 3);
    EnQueue(&queue, 4);
    PrintQueue(&queue);
    printf("deque 1 times.\n");
    DeQueue(&queue);
    PrintQueue(&queue);

    printf("IsNull = %d\n", IsNull(&queue));
    DelQueue(&queue);
    printf("DelQueue(&queue).....................\n");
    printf("IsNull = %d\n", IsNull(&queue));

    return 0;
}