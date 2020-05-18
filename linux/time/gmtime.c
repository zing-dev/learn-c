//
// Created by zing on 5/18/2020.
//

#include <time.h>
#include <stdio.h>

#define BST (+1)
#define CCT (+8)

int main(int argc, char *argv[]) {
    time_t time1;
    time(&time1);
    struct tm *info = gmtime(&time1);
    printf("当前的世界时钟：\n");
    printf("伦敦：%2d:%02d\n", (info->tm_hour + BST) % 24, info->tm_min);
    printf("中国：%2d:%02d\n", (info->tm_hour + CCT) % 24, info->tm_min);
    char buffer[8];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);
    printf("%s",buffer);
    return 0;
}
