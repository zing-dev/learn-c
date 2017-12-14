//
// Created by zhangrongxiang on 2017/12/14 10:43
// File queue
//

#include <stdio.h>
#include <time.h>

#define QueueSize 20
typedef int DataType;
//#define DataType int
typedef struct {
    DataType data[QueueSize];
    int front;
    int rear;
    int count;
} Queue;

//初始化队列
void InitQueue(Queue *Q) {
    Q->front = 0;
    Q->rear = 0;
    Q->count = 0;
    printf("初始化队列\n");
}

//队列是否为空
int QueueEmpty(Queue *Q) {
    return (Q->count == 0);
}

//队列是否满
int QueueFull(Queue *Q) {
    return (Q->count == QueueSize);
}

//入队
void EnQueue(Queue *Q, DataType v) {
    if (QueueFull(Q)){
        printf("Error, the queue is full!\n");
        return;
    }
    Q->data[Q->rear] = v;
    Q->rear = (Q->rear + 1) % QueueSize; //循环，防止rear大于QueueSize；
    printf("%-5d 入队\n", v);
    Q->count++;
}

//出队
DataType DeQueue(Queue *Q) {
    DataType i;
    if (QueueEmpty(Q))
        printf("Error, the queue is empty");
    i = Q->data[Q->front];
    printf("%-5d 出队\n", i);
    Q->front = (Q->front + 1) % QueueSize; //循环
    Q->count--;
    return i;
}

//读队头元素，不改变对状态
DataType ReadQueue(Queue *Q) {
    DataType i;
    if (QueueEmpty(Q))
        printf("Error, the queue is empty");
    i = Q->data[Q->front];
    printf("%-5d 对头\n", i);
    return i;
}

void print(Queue Q) {
    printf("打印队列:\t");
    int i = Q.front;
    if (QueueEmpty(&Q)) {
        printf("空队列.\n");
        return;
    }
    while (Q.count > 0) {
        printf("%d\t", Q.data[i++]);
        i = i % QueueSize;
        Q.count--;
    }
    printf("\n");
}

int main() {
    Queue Q, *Q1;
    int i = 1;
    srand((unsigned) time(NULL));

    InitQueue(&Q);
    while (i <= 21) {
        EnQueue(&Q, rand() % 100 + 1);
        i++;
    }
    print(Q);
    DeQueue(&Q);
    DeQueue(&Q);
    DeQueue(&Q);
    DeQueue(&Q);
    print(Q);
    ReadQueue(&Q);
    DeQueue(&Q);
    ReadQueue(&Q);

    EnQueue(&Q, 111);
    EnQueue(&Q, 112);
    EnQueue(&Q, 113);
    EnQueue(&Q, 114);
    EnQueue(&Q, 115);
    EnQueue(&Q, 116);
    print(Q);
    while (!QueueEmpty(&Q))
        DeQueue(&Q);
    Q1 = &Q;
    printf("队列长度: %d\n", Q1->count);

    return 0;
}