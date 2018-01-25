//
// Created by zhangrongxiang on 2018/1/24 15:37
// File md5
//

#include<stdio.h>
#include<openssl/md5.h>
#include<string.h>

int main( int argc, char **argv )
{
    //定义资源句柄
    MD5_CTX ctx;
    unsigned char *data= (unsigned char *) "hello world";
    unsigned char md[16];
    char buf[33]={'\0'};
    char tmp[3]={'\0'};
    int i;
    //初始化
    MD5_Init(&ctx);
    //更新数据（加密数据）
    MD5_Update(&ctx,data,strlen(data));
    //返回MD5值
    MD5_Final(md,&ctx);

    for( i=0; i<16; i++ ){
        sprintf(tmp,"%02X",md[i]);
        strcat(buf,tmp);
    }
    printf("%s\n",buf);
    return 0;
}

//gcc md5.c -o md5.out  -lcrypto