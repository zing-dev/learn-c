//
// Created by zhangrongxiang on 2017/11/22 11:00
// File 1
//


#include <stdio.h>
#include <time.h>
#include <stdint.h>


typedef uint32_t UL;
typedef struct _LOG {
    UL id;
    UL level;
    UL result;
    time_t create_time;
    unsigned char content[64];
} DB_LOG;

typedef struct _DB_LOG {
    int id;
    int level;
    int result;
    time_t time;
    unsigned char content[64];
} DB_LOG2;

int main() {

    printf("%d\n", sizeof(DB_LOG));
    printf("%d\n", sizeof(DB_LOG2));
    printf("%d\n", sizeof(time_t));
    time_t now = 1111111;
    printf("%d\n", now);
}