//
// Created by zhangrongxiang on 2018/2/27 14:11
// File type
//

#include <stdio.h>
#include <stdint.h>

typedef uint32_t UL;
typedef struct _DB_LOG {
    int id;
    int level;
    int result;
    int time;
    unsigned char content[64];
} DB_LOG;

typedef struct _LOG {
    UL id;
    UL level;
    UL result;
    time_t create_time;
    unsigned char content[64];
} DB_LOG2;

int main() {
    printf("sizeof DB_LOG is %d\n", (int) sizeof(DB_LOG));//80
    printf("sizeof DB_LOG2 is %d\n", (int) sizeof(DB_LOG2));//88
    printf("%d\n", (int) sizeof(uint32_t));
    printf("%d\n", (int) sizeof(int));
    printf("%d\n", (int) sizeof(time_t));//8
    return 0;
}