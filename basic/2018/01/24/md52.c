//
// Created by zhangrongxiang on 2018/1/25 10:04
// File md52
//

#include<stdio.h>
#include<openssl/md5.h>
#include<string.h>

int main(int argc, char **argv) {
    unsigned char *data = "hello world";
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

//1.sprintf时的格式，%02X和%2.2格式是一样的，强制输出两位，比如十进制的8，十六进制也是8，这个格式是控制输出两位，08。
// 如果加密结果要小写字母显示，就是"%2.2x",大写就是"2.2X"。

//2.一定要使用unsigned char,虽然是char，其实就是个int,当然，它只有一个字节，和char的区别是，unsigned char 0~255 ,char -127~127。使用char会出问题。
// 这个md5加密函数，返回16个十进制数，范围在0～255间，把它format为十六进制就是32为md5编码了。

//3.gcc编译的时候，后面加上参数 -lcrypto 如果系统没有安装libcrypto，是不能用这个方法的。