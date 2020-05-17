//
// Created by zhangrongxiang on 2017/10/31 16:39
// File 2
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PATH 256

int main() {
    int count = 0;
    char Buffer[MAX_PATH] = {0x00}, *ptr = NULL;
    char *servicename = "cipherserver";
    FILE *fp;

    fp = popen(" ps -e | grep nginx", "r");
    memset(Buffer, 0x00, sizeof(MAX_PATH));
    fgets(Buffer, MAX_PATH, fp);
    pclose(fp);
    printf("%s\n", Buffer);
    if (Buffer[0] != '\0') {
        perror("error");
        return -1;
    }
    count = readlink("/proc/self/exe", Buffer, MAX_PATH);
    ptr = strstr(Buffer, "nginx");
    memset(ptr, 0x00, MAX_PATH - (ptr - Buffer) - 1);
    strcpy(ptr, servicename);
    printf("%s\n", ptr);
}