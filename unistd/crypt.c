//
// Created by zhangrongxiang on 2018/2/26 9:09
// File crypt
//

#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(){
    char *str = "hello";
    char *salt = "abc";
    char *rs;
    crypt(str,salt);//crypt.c:(.text+0x27): undefined reference to `crypt'
    if(rs != NULL){
        printf("%s\n",rs);
    } else{
        printf("%s\n",strerror(errno));
    }
    return 0;
}