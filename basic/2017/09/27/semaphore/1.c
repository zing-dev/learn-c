//
// Created by zhangrongxiang on 2017/9/27 10:54
//

// 在任一时刻只能有一个执行线程访问 代码的临界区域。
// 临界区域是指执行数据更新的代码需要独占式地执行。而信号量就可以提供这样的一种访问机制

/*
 * 由于信号量只能进行两种操作等待和发送信号，即P(sv)和V(sv),他们的行为是这样的：
 * P(sv)：如果sv的值大于零，就给它减1；如果它的值为零，就挂起该进程的执行
 * V(sv)：如果有其他进程因等待sv而被挂起，就让它恢复运行，如果没有进程因等待sv而挂起，就给它加1.
 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//POSIX信号量的引用头文件是“<semaphore.h>”，
//而SYSTEM V信号量的引用头文件是“<sys/sem.h>”。
#include <sys/sem.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *arry;
};
static int sem_id = 0;

static int set_semvalue();

static void del_semvalue();

static int semaphore_p();

static int semaphore_v();

int main(int argc, char *argv[]) {
    char message = 'X';
    int i = 0;
    /* 创建信号量 */
    sem_id = semget((key_t) 1234, 1, 0666 | IPC_CREAT);
    printf("创建信号量。。。。。。。。。。。。。。。。\n");
    if (argc > 1) {
        printf("argc > 1。。。。。。。。。。。。。。。\n");
        /* 程序第一次被调用，初始化信号量 */
        if (!set_semvalue()) {
            fprintf(stderr, "Failed to initialize semaphore\n");
            exit(EXIT_FAILURE);
        }
        /* 设置要输出到屏幕中的信息，即其参数的第一个字符 */
        message = argv[1][0];
        sleep(2);
    }

    for (i = 0; i < 10; ++i) {
        /* 进入临界区 */
        if (!semaphore_p()) {
            exit(EXIT_FAILURE);
        }
        /* 向屏幕中输出数据 */
        printf("%c", message);
        /* 清理缓冲区，然后休眠随机时间 */
        fflush(stdout);
        sleep(rand() % 3);
        /* 离开临界区前再一次向屏幕输出数据 */
        printf("%c", message);
        fflush(stdout);
        /* 离开临界区，休眠随机时间后继续循环 */
        if (!semaphore_v()) {
            exit(EXIT_FAILURE);
        }
        sleep(rand() % 2);
    }
    sleep(10);
    printf("\n%d - finished\n", getpid());

    if (argc > 1) {
        /* 如果程序是第一次被调用，则在退出前删除信号量 */
        sleep(3);
        del_semvalue();
    }
    exit(EXIT_SUCCESS);
}

static int set_semvalue() {
    /* 用于初始化信号量，在使用信号量前必须这样做 */
    union semun sem_union;

    sem_union.val = 1;
    if (semctl(sem_id, 0, SETVAL, sem_union) == -1) {
        return 0;
    }
    return 1;
}

static void del_semvalue() {
    /* 删除信号量 */
    union semun sem_union;

    if (semctl(sem_id, 0, IPC_RMID, sem_union) == -1) {
        fprintf(stderr, "Failed to delete semaphore\n");
    }
}

static int semaphore_p() {
    /* 对信号量做减1操作，即等待P（sv）*/
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1;//P()
    sem_b.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sem_b, 1) == -1) {
        fprintf(stderr, "semaphore_p failed\n");
        return 0;
    }
    return 1;
}

static int semaphore_v() {
    /* 这是一个释放操作，它使信号量变为可用，即发送信号V（sv）*/
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = 1;//V()
    sem_b.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sem_b, 1) == -1) {
        fprintf(stderr, "semaphore_v failed\n");
        return 0;
    }
    return 1;
}