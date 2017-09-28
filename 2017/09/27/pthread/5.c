//
// Created by zhangrongxiang on 2017/9/27 10:40
//

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
//#include <sys/sem.h>


#define MAXSIZE 10

int stack[MAXSIZE];
int size = 0;
sem_t sem;

// 生产者
void provide_data(void) {
    int i;
    for (i = 0; i < MAXSIZE; i++) {
        stack[i] = i;
        sem_post(&sem); //为信号量加1
    }
}

// 消费者
void handle_data(void) {
    int i;
    while ((i = size++) < MAXSIZE) {
        sem_wait(&sem);
        printf("乘法: %d X %d = %d\n", stack[i], stack[i], stack[i] * stack[i]);
        sleep(1);
    }
}

int main(void) {

    pthread_t provider, handler;

    sem_init(&sem, 0, 0); //信号量初始化
    pthread_create(&provider, NULL, (void *) handle_data, NULL);
    pthread_create(&handler, NULL, (void *) provide_data, NULL);
    pthread_join(provider, NULL);
    pthread_join(handler, NULL);
    sem_destroy(&sem); //销毁信号量

    return 0;
}