//
// Created by zhangrongxiang on 2017/9/27 15:43
// File 6
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define BUFF_SIZE 10
char buffer[BUFF_SIZE];
int count; // 缓冲池里的信息数目
sem_t sem_mutex; // 生产者和消费者的互斥锁
sem_t p_sem_mutex; // 空的时候，对消费者不可进
sem_t c_sem_mutex; // 满的时候，对生产者不可进
void *Producer() {
    while (1) {
        printf("Producer\n");
        sem_wait(&p_sem_mutex); //当缓冲池未满时
        sem_wait(&sem_mutex); //等待缓冲池空闲
        printf("Producer ---> %d\n", count);
        count++;
        sem_post(&sem_mutex);
        if (count < BUFF_SIZE)//缓冲池未满
            sem_post(&p_sem_mutex);
        if (count > 0) //缓冲池不为空
            sem_post(&p_sem_mutex);
    }
}

void *Consumer() {
    while (1) {
        printf("Consumer\n");
        sem_wait(&c_sem_mutex);//缓冲池未空时
        sem_wait(&sem_mutex); //等待缓冲池空闲
        printf("Consumer ---> %d\n", count);
        count--;
        sem_post(&sem_mutex);
        if (count > 0)
            sem_post(&c_sem_mutex);
    }
}

//有一个长度为N的缓冲池为生产者和消费者所共有，只要缓冲池未满，生产者便可将
//消息送入缓冲池；只要缓冲池未空，消费者便可从缓冲池中取走一个消息。生产者往缓冲池
//放信息的时候，消费者不可操作缓冲池，反之亦然。
int main() {
    pthread_t ptid, ctid;
    count = 5;
//initialize the semaphores
    sem_init(&sem_mutex, 0, 0);
    sem_init(&p_sem_mutex, 0, 1);
    sem_init(&c_sem_mutex, 0, 0);
    printf("------------------------------------\n");
//creating producer and consumer threads
    if (pthread_create(&ptid, NULL, Producer, NULL)) {
        printf("\n ERROR creating thread 1");
        exit(1);
    }
    if (pthread_create(&ctid, NULL, Consumer, NULL)) {
        printf("\n ERROR creating thread 2");
        exit(1);
    }
    if (pthread_join(ptid, NULL)) /* wait for the producer to finish */
    {
        printf("\n ERROR joining thread");
        exit(1);
    }
    if (pthread_join(ctid, NULL)) /* wait for consumer to finish */
    {
        printf("\n ERROR joining thread");
        exit(1);
    }
    sem_destroy(&p_sem_mutex);
    sem_destroy(&c_sem_mutex);
//exit the main thread
    pthread_exit(NULL);
    return 1;
}
