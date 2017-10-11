//
// Created by zhangrongxiang on 2017/10/11 11:31
// File md5
//

#include <stdio.h>
#include <openssl/md5.h>
#include <string.h>

//gcc md5.c -o md5.out  -lcrypto
int main(int argc, char **argv) {
    MD5_CTX ctx;
    unsigned char *data = "1234";
    unsigned char md[16];
    char buf[33] = {'\0'};
    char tmp[3] = {'\0'};
    int i;

    MD5_Init(&ctx);
    MD5_Update(&ctx, data, strlen(data));
    MD5_Final(md, &ctx);

    for (i = 0; i < 16; i++) {
        sprintf(tmp, "%02x", md[i]);
        strcat(buf, tmp);
    }
    printf("%s\n", buf);
    return 0;
}