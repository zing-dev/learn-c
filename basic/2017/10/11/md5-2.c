//
// Created by zhangrongxiang on 2017/10/11 13:34
// File md5
//

#include<stdio.h>
#include<openssl/md5.h>
#include<string.h>


//-lcrypto
int main(int argc, char **argv) {
    unsigned char *data = "1234";
    unsigned char md[16];
    int i;
    char tmp[3] = {'\0'}, buf[33] = {'\0'};
    MD5(data, strlen(data), md);
    for (i = 0; i < 16; i++) {
        sprintf(tmp, "%2.2x", md[i]);
        strcat(buf, tmp);
    }
    printf("%s\n", buf);
    return 0;
}