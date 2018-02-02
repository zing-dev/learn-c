//
// Created by zhangrongxiang on 2018/2/2 16:09
// File md5
//

#ifndef LEARC_C_MD5_H
#define LEARC_C_MD5_H

#define _DEBUG
#ifdef _DEBUG
#define DEBUG_PRINT(arg...) \
    do{\
        printf("[debug]:%s:%s:%d --> ",__FILE__,__FUNCTION__,__LINE__);\
        printf(arg);\
        fflush(stdout);\
    }while(0)

#else
#define DEBUG_PRINT(arg...) {}
#endif

char* hmac_md5(char* text, char* key);
char* MDString (char *string);
char* MDFile (char *string);

#endif
//LEARC_C_MD5_H
