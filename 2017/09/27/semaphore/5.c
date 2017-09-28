//
// Created by zhangrongxiang on 2017/9/27 13:48
// File 5
//

#include <semaphore.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char **argv) {
    int fd, i, count = 0, nloop = 10, zero = 0, *ptr;
    sem_t mutex;
//open a file and map it into memory
    fd = open("log.txt", O_RDWR | O_CREAT, S_IRWXU);
    write(fd, &zero, sizeof(int));
    ptr = mmap(NULL, sizeof(int), PROT_READ |
                                  PROT_WRITE, MAP_SHARED, fd, 0);
//    EACCES：访问出错
//    EAGAIN：文件已被锁定，或者太多的内存已被锁定
//    EBADF：fd不是有效的文件描述词
//    EINVAL：一个或者多个参数无效
//    ENFILE：已达到系统对打开文件的限制
//    ENODEV：指定文件所在的文件系统不支持内存映射
//    ENOMEM：内存不足，或者进程已超出最大内存映射数量
//    EPERM：权能不足，操作不允许
//    ETXTBSY：已写的方式打开文件，同时指定MAP_DENYWRITE标志
//    SIGSEGV：试着向只读区写入
//    SIGBUS：试着访问不属于进程的内存区
    printf("%d\n", *ptr);
    close(fd);
/* create, initialize semaphore */
    if (sem_init(&mutex, 1, 1) < 0) //
    {
        perror("semaphore initilization");
        exit(0);
    }
    if (fork() == 0) { /* child process*/
        for (i = 0; i < nloop; i++) {
            sem_wait(&mutex);
            printf("child: %d\n", ptr++);
            sem_post(&mutex);
        }
        exit(0);
    }
/* back to parent process */
    for (i = 0; i < nloop; i++) {
        sem_wait(&mutex);
        printf("parent: %d\n", ptr++);
        sem_post(&mutex);
    }
    exit(0);
}