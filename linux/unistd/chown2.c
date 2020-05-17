//
// Created by zhangrongxiang on 2018/2/22 10:17
// File chown2
//

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
//    printf("%s\n",argv[0]);
//    printf("%s\n",argv[1]);
//    printf("%s\n",argv[2]);
//    printf("%d\n",atoi(argv[1]));
    if (argc != 3 || argv[1][0] == '\0') {
        fprintf(stderr, "%s <owner> <file>\n", argv[0]);
    } else{
        int id = atoi(argv[1]);
        printf("id -> %d\n",id);
        int r = chown(argv[2], id, id);
        if (r != -1){
            printf("chown success\n");
        } else{
            printf("chown error\n");
        }
    }
    return 0;
}