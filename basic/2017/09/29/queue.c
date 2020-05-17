//
// Created by zhangrongxiang on 2017/9/29 9:58
// File queue
//

#include "queue.h"

int main(int argc, const char *argv[]) {
    LinkQueue queue;
    puts("初始化队列 queue");
    initQueue(&queue);
    traversal(queue);

    puts("队尾依次插入0 1 2 3");
    insertQueue(&queue, 0);
    insertQueue(&queue, 1);
    insertQueue(&queue, 2);
    insertQueue(&queue, 3);
    traversal(queue);

    puts("先进先出，删除队列从头开始， 0 ");
    deleteQueue(&queue);
    traversal(queue);

    puts("先进先出，删除队列从头开始， 1 ");
    deleteQueue(&queue);
    traversal(queue);

    puts("先进先出，删除队列从头开始， 2 ");
    deleteQueue(&queue);
    traversal(queue);

    puts("先进先出，删除队列从头开始， 3");
    deleteQueue(&queue);
    traversal(queue);

    destoryQueue(&queue);
    return 0;
}