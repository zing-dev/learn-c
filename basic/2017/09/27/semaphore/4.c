//
// Created by zhangrongxiang on 2017/9/27 11:39
// File 4
//

#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>


int number; // 被保护的全局变量
sem_t sem_id1, sem_id2;

/*
 * 无名信号量的常见用法是将要保护的变量放在sem_wait和sem_post中间所形成的临界区内，这样该变量就会被保护起来
 */
void *thread_one_fun(void *arg) {
    sem_wait(&sem_id1);
    printf("thread_one have the semaphore\n");
    for (int i = 0; i < 100000; ++i) {
//        number++;
        printf("thread_one_fun ---->  number = %d\n", number++);
    }
    sem_post(&sem_id2);
}

void *thread_two_fun(void *arg) {
    sem_wait(&sem_id2);
    printf("thread_two have the semaphore \n");
    for (int i = 0; i < 100000; ++i) {
//        number++;
        printf("thread_two_fun ---->  number = %d\n", number++);
    }
    sem_post(&sem_id1);
}

int main(int argc, char *argv[]) {
    number = 1;
    pthread_t id1, id2;

    sem_init(&sem_id1, 0, 1); // 空闲的
    sem_init(&sem_id2, 0, 0); // 忙的

    pthread_create(&id1, NULL, thread_one_fun, NULL);
    pthread_create(&id2, NULL, thread_two_fun, NULL);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    printf("main,,,\n");
    return 0;
}