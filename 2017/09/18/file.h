//
// Created by zhangrongxiang on 2017/9/18.
//

/**************************************************************************
Filename       :file.h
Description     :文件操作的头文件
**************************************************************************/
/*将安全检查警报设置为失效,必须放在第一行*/
#pragma warning(disable:4996)
#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>    //注意文件操作相关函数的头文件是stdio.h
#include<stdlib.h>    //为了使用system函数
#include <string.h>   //字符串操作所用到的头文件
#include<Windows.h>   //使用休眠函数时用到的头文件
#include <crtdbg.h>   //做内存泄露检测所需的头文件

/*************************************************************
Function         :getFileRow
Description      :获得文件的中记录的行数
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）
path             :表示的是文件的路径
Output           :输出的信息为空
Return           :返回文件中的行数
Others           :其它说明
*************************************************************/
int getFileRow(const char *path);

/*************************************************************
Function         :main_view
Description      :查看菜单信息
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

Output           :输出的信息为空
Return           :返回值为void
Others           :其它说明
*************************************************************/
void main_view();

/*************************************************************
Function         :getFileSize
Description      :获得文件的大小（字节数）
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

path             :表示的文件路径
Output           :输出的信息为空
Return           :文件的字节大小
Others           :其它说明
*************************************************************/
int getFileSize(const char *path);

/*************************************************************
Function         :loadFile
Description      :加载文件
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

path             :表示的是文件路径
rowSize          :表示的是文件中信息由多少行
Output           :输出的信息为空
Return           :返回值为int,如果加载成功返回1，如果加载失败返回0
Others           :其它说明
*************************************************************/
int loadFile(const char *fPath, const int rowSize);

/*************************************************************
Function         :findStringByKeyword
Description      :通过关键字的方式进行查找
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

keyword          :通过关键字查找信息
rowSize          :表示的是文件中信息由多少行
Output           :输出的信息为空
Return           :如果查找失败返回0，查找成功返回1
Others           :其它说明
*************************************************************/
int findStringByKeyword(const char *keyword, const int rowSize);

/*************************************************************
Function         :freeMemory
Description      :释放内存空间
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pp               :存储文件信息的二重指针
rowSize          :表示的行大小
Output           :输出的信息为空
Return           :返回值为void
Others           :其它说明
*************************************************************/
void freeMemory(char **pp, const int rowSize);

/*************************************************************
Function         :writeStr2File
Description      :将字符串拼接的方式写入文件
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pFilePath        :要写入的文件路径
pStr             :要写入的字符串
mode             :表示写入的模式,0:表示直接追击   1:表示换行追加
Output           :输出的信息为空
Return           :如果写入成功返回1，如果写入失败返回0
Others           :其它说明
*************************************************************/
int writeStr2File(const char *pFilePath, const char *pStr, int mode);

/*************************************************************
Function         :copy()
Description      :将一个文件拷贝到另外一个文件
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pDestFile        :要写入的文件
pOriginalFile    :原始文件
mode             :表示写入的模式,0:表示直接追击   1:表示换行追加
Output          :输出的信息为空
Return           :如果写入成功返回1，如果写入失败返回0
Others           :其它说明
*************************************************************/
int copy(const char *pDestFile, const char *pOriginalFile);

/*************************************************************
Function         :encryptFileByChar()
Description      :将文件按照ch进行加密，并将文件输出到指定文件中
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pDestFile        :要写入的文件
pOriginalFile    :原始文件
ch               :用于加密的字符
Output           :输出的信息为空
Return           :如果写入成功返回1，如果写入失败返回0
Others           :其它说明
*************************************************************/
int encryptFileByChar(const char *pDestFile,
                      const char *pOriginalFile, const char ch);

/*************************************************************
Function         :deCodeFileByChar()
Description      :通过ch进行解密文件，并将文件输出到指定的文件中
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pDestFile        :要写入的文件
pOriginalFile    :原始文件
ch               :用于解密的字符
Output           :输出的信息为空
Return           :如果写入成功返回1，如果写入失败返回0
Others           :其它说明
*************************************************************/
int deCodeFileByChar(const char *pDestFile,
                     const char *pOriginalFile, const char ch);

/*************************************************************
Function         :stringEncrypt()
Description      :将字符串变成字符串加密后的字符串
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pwdStr           :将字符串变成加密后的字符串
str              :要加密的字符串
Output           :输出的信息为空
Return           :返回加密后的字符串地址
Others           :其它说明
*************************************************************/
char *str2EncryptString(char *pwdStr, char *str);

/*************************************************************
Function         :str2DecodedString()
Description      :将字符串变成解密之后的文件
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pwdStr           :将字符串变成加密后的字符串
str              :要解密的字符串
Output           :输出的信息为空
Return           :返回解密后的字符串地址
Others           :其它说明
*************************************************************/
char *str2DecodedString(char *pwdStr, char *str);

/*************************************************************
Function         :encryptAndDecodeFileByString()
Description      :通过字符串str来加解密文件
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pDestFile        :要写入的文件
pOriginalFile    :原始文件
pwdString        :用于加解密的字符
Output           :输出的信息为空
Return           :如果写入成功返回1，如果写入失败返回0
Others           :其它说明
*************************************************************/
int encryptAndDecodeFileByString(const char *pDestFile,
                                 const char *pOriginalFile, const char *pwdString);


#endif

//2.文件操作的实现函数

#define _CRT_SECURE_NO_WARNINGS

#include "file.h"

char **pp = NULL;   //存储指针数组的地址
int flag = 0;

/*************************************************************
Function         :getFileRow
Description      :获得文件的中记录的行数
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）
path             :表示的是文件的路径
Output           :输出的信息为空
Return           :返回文件中的行数
Others           :其它说明
*************************************************************/
int getFileRow(const char *path) {
    FILE *pf;
    pf = fopen(path, "r");
    if (pf == NULL) {
        //代表获取失败
        fclose(pf);
        return -1;
    } else {
        int i = 0;
        //是否到文件末尾，如果到了返回1，没有到的时候返回0
        while (!feof(pf)) {
            char str[275];
            //读取一行
            fgets(str, 275, pf);
            i++;
        }
        fclose(pf);
        return i;
    }
}

/*************************************************************
Function         :main_view
Description      :查看菜单信息
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

Output           :输出的信息为空
Return           :返回值为void
Others           :其它说明
*************************************************************/
void main_view() {
    system("cls");
    printf("\n******************当当用户信息查询系统*******************\n");
    printf("\t1.载入数据至内存(-l)\n");
    printf("\t2.查找字符串(-s)\n");
    printf("\t3.释放内存(-f)\n");
    printf("\n*************************0.退出**************************\n");
}

/*************************************************************
Function         :getFileSize
Description      :获得文件的大小（字节数）
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

path             :表示的文件路径
Output           :输出的信息为空
Return           :文件的字节大小
Others           :其它说明
*************************************************************/
int getFileSize(const char *path) {
    //定义一个文件指针
    FILE *pf = NULL;
    pf = fopen(path, "r");
    if (pf == NULL) {
        //代表获取文件失败
        fclose(pf);
        return -1;
    } else {
        //fseek():Moves the file pointer to a specified location.
        fseek(pf, 0, SEEK_END);
        //ftell( FILE*stream ):文件开头到当前位置有多少个字节
        int num = ftell(pf);
        //关闭文件
        fclose(pf);
        return num;
    }
}

/*************************************************************
Function         :loadFile
Description      :加载文件
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

path             :表示的是文件路径
rowSize          :表示的是文件中信息由多少行
Output           :输出的信息为空
Return           :返回值为int,如果加载成功返回1，如果加载失败返回0
Others           :其它说明
*************************************************************/
int loadFile(const char *fPath, const int rowSize) {
    printf("加载文件后，请稍后....");
    FILE *pf;
    pp = (char **) malloc(sizeof(char *) * rowSize);
    pf = fopen(fPath, "r");
    if (pf == NULL) {
        printf("对不起，加载文件失败!");
        fclose(pf);
        return 0;
    } else {
        int i;
        for (i = 0; i < rowSize; i++) {
            //读取字符串的缓冲区
            char str[275] = {0};
            //*fgets(char*string,int n,FILE *stream);
            //从文件中逐行读取字符串
            fgets(str, sizeof(str), pf);
            //获取要分配的字符串长度，最后加一是因为'\0'
            int strlength = strlen(str) + 1;
            //分配内存
            char *px = (char *) malloc(sizeof(char) * strlength);
            //拷贝字符串
            strcpy(px, str);
            //设定最后一个字符串'\0'
            px[strlength - 1] = '\0';
            //存储字符串的首地址到指针数组
            pp[i] = px;
        }
    }
    return 1;
}

/*************************************************************
Function         :findStringByKeyword
Description      :通过关键字的方式进行查找
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

keyword          :通过关键字查找信息
rowSize          :表示的是文件中信息由多少行
Output           :输出的信息为空
Return           :如果查找失败返回0，查找成功返回1
Others           :其它说明
*************************************************************/
int findStringByKeyword(const char *keyword, const int rowSize) {
    if (pp == NULL) {
        printf("对不起，您还没有加载文件，请您先加载文件\n");
        return 0;
    } else {
        int i;
        for (i = 0; i < rowSize; i++) {
            //遍历所有的指针数组的地址，字符串查找
            char *pTemp = strstr(pp[i], keyword);
            if (pTemp != NULL) {
                printf("\n%s", pp[i]);
            }
        }
    }
    return 1;
}

/*************************************************************
Function         :freeMemory
Description      :释放内存空间
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pp               :存储文件信息的二重指针
rowSize          :表示的行大小
Output           :输出的信息为空
Return           :返回值为void
Others           :其它说明
*************************************************************/
void freeMemory(char **pp, const int rowSize) {
    int i;
    for (i = 0; i < rowSize; i++) {
        free(pp[i]);
    }
    free(pp);
    flag = 0;
}

/*************************************************************
Function         :writeStr2File
Description      :将字符串拼接的方式写入文件
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pFilePath        :要写入的文件路径
pStr             :要写入的字符串
mode             :表示写入的模式,0:表示直接追击   1:表示换行追加
Output           :输出的信息为空
Return           :如果写入成功返回1，如果写入失败返回0
Others           :其它说明
*************************************************************/
int writeStr2File(const char *pFilePath, const char *pStr, int mode) {
    FILE *pf;
    //a+表示以追加的方式写文件，如果
    pf = fopen(pFilePath, "a+");
    if (pf == NULL) {
        //表示文件打开失败
        fclose(pf);
        return 0;
    } else {
        if (mode) {
            fputs(pStr, pf);
            //通过加入'\r'的方式换行，如果隔行输出使用'\r\n'
            fprintf(pf, "\r");
        } else {
            fprintf(pf, pStr);
        }
        fclose(pf);
    }
    //写入成功返回1
    return 1;
}

/*************************************************************
Function         :copy()
Description      :将一个文件拷贝到另外一个文件
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pDestFile        :要写入的文件
pOriginalFile    :原始文件
mode             :表示写入的模式,0:表示直接追击   1:表示换行追加
Output           :输出的信息为空
Return           :如果写入成功返回1，如果写入失败返回0
Others           :其它说明
*************************************************************/
int copy(const char *pDestFile, const char *pOriginalFile) {
    FILE *pfr, *pfw;
    //以代开二进制文件的方式打开
    pfr = fopen(pOriginalFile, "r");
    //要写入的文件
    pfw = fopen(pDestFile, "w");
    if (pfr == NULL || pfw == NULL) {
        fclose(pfr);
        fclose(pfw);
        return 0;
    } else {
        int length = getFileSize(pOriginalFile);
        //分配内存，读取文件
        char *p = (char *) malloc(length * sizeof(char));
        //读取文件到内存
        fread(p, sizeof(char), length, pfr);
        //写入文件
        fwrite(p, sizeof(char), length, pfw);

        //关闭文件
        fclose(pfr);
        fclose(pfw);
    }
    return 1;
}

/*************************************************************
Function         :encryptFileByChar()
Description      :将文件按照ch进行加密，并将文件输出到指定文件中
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pDestFile        :要写入的文件
pOriginalFile    :原始文件
ch               :用于加密的字符
Output           :输出的信息为空
Return           :如果写入成功返回1，如果写入失败返回0
Others           :其它说明
*************************************************************/
int encryptFileByChar(const char *pDestFile,
                      const char *pOriginalFile, const char ch) {
    FILE *pfr, *pfw;
    //以读的方式写入文件
    pfr = fopen(pOriginalFile, "r");
    //以写的方式写入文件中
    pfw = fopen(pDestFile, "w");
    if (pfr == NULL || pfw == NULL) {
        //表示加载失败
        fclose(pfr);
        fclose(pfw);
        return 0;
    } else {
        //读取原始文件中的大小（通过这种方式获得字节数大小）
        int length = getFileSize(pOriginalFile);
        //分配内存，读取文件
        char *p = (char *) malloc(sizeof(char) * length);
        //读取文件到内存中
        fread(p, sizeof(char), length, pfr);
        int i;
        for (i = 0; i < length; i++) {
            //加密方法是，于指定字符串进行异或操作
            p[i] ^= ch;
        }
        //写入文件
        fwrite(p, sizeof(char), length, pfw);
        fclose(pfr);
        fclose(pfw);
    }
    return 1;
}

/*************************************************************
Function         :deCodeFileByChar()
Description      :通过ch进行解密文件，并将文件输出到指定的文件中
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pDestFile        :要写入的文件
pOriginalFile    :原始文件
ch               :用于解密的字符
Output           :输出的信息为空
Return           :如果写入成功返回1，如果写入失败返回0
Others           :其它说明
*************************************************************/
int deCodeFileByChar(const char *pDestFile,
                     const char *pOriginalFile, const char ch) {
    FILE *pfr, *pfw;
    pfr = fopen(pOriginalFile, "r");
    pfw = fopen(pDestFile, "w");
    if (pfr == NULL || pfw == NULL) {
        fclose(pfr);
        fclose(pfw);
        //如果是成功，则
        return 0;
    } else {
        //读取原始文件的大小
        int length = getFileSize(pOriginalFile);
        //分配内存，读取文件
        char *p = (char *) malloc(sizeof(char) * length);
        //读取文件到内存中
        fread(p, sizeof(char), length, pfr);
        int i;
        for (i = 0; i < length; i++) {
            //解密方法是，于指定字符串进行异或操作
            p[i] ^= ch;
        }
        fwrite(p, sizeof(char), length, pfw);
        //关闭文件
        fclose(pfr);
        fclose(pfw);
    }

    return 1;
}

/*************************************************************
Function         :stringEncrypt()
Description      :将字符串变成字符串加密后的字符串
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pwdStr           :将字符串变成加密后的字符串
str              :要加密的字符串
Output           :输出的信息为空
Return           :返回加密后的字符串地址
Others           :其它说明
*************************************************************/
char *str2EncryptString(char *pwdStr, char *str) {
    //获取加密长度
    int pwdStrLength = strlen(pwdStr);
    //获取字符串的长度
    int strLength = strlen(str);
    if (strLength % pwdStrLength) {
        int times = strLength / pwdStrLength;
        int i, j;
        //循环次数
        for (i = 0; i < times; i++) {
            for (j = 0; j < pwdStrLength; j++) {
                str[pwdStrLength * i + j] ^= pwdStr[j];
            }
        }
    } else {
        //获取循环次数
        int times = strLength / pwdStrLength;
        int i, j;
        for (i = 0; i < times; i++) {
            //循环密码
            for (j = 0; j < pwdStrLength; j++) {
                str[pwdStrLength * i + j] ^= pwdStr[j];
            }
        }
        //剩下的长度
        int lastLength = strLength % pwdStrLength;
        for (i = 0; i < lastLength; i++) {
            str[pwdStrLength * (strLength / pwdStrLength) + i] ^= pwdStr[i];
        }
    }
    return str;
}

/*************************************************************
Function         :str2DecodedString()
Description      :将字符串变成解密之后的文件
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pwdStr           :将字符串变成加密后的字符串
str              :要解密的字符串
Output           :输出的信息为空
Return           :返回解密后的字符串地址
Others           :其它说明
*************************************************************/
char *str2DecodedString(char *pwdStr, char *str) {
    //获取加密长度
    int pwdStrLength = strlen(pwdStr);
    //获取字符串的长度
    int strLength = strlen(str);
    if (strLength % pwdStrLength) {
        int times = strLength / pwdStrLength;
        int i, j;
        //循环次数
        for (i = 0; i < times; i++) {
            for (j = 0; j < pwdStrLength; j++) {
                str[pwdStrLength * i + j] ^= pwdStr[j];
            }
        }
    } else {
        //获取循环次数
        int times = strLength / pwdStrLength;
        int i, j;
        for (i = 0; i < times; i++) {
            //循环密码
            for (j = 0; j < pwdStrLength; j++) {
                str[pwdStrLength * i + j] ^= pwdStr[j];
            }
        }
        //剩下的长度
        int lastLength = strLength % pwdStrLength;
        for (i = 0; i < lastLength; i++) {
            str[pwdStrLength * (strLength / pwdStrLength) + i] ^= pwdStr[i];
        }
    }
    return str;
}

/*************************************************************
Function         :encryptAndDecodeFileByString()
Description      :通过字符串str来加解密文件
Calls            :被本函数调用的函数清单
CalledBy        :调用本函数的函数清单
TableAccessed   :被访问的表（此项仅对于牵扯到数据库操作的程序）
TableUpdated    :被修改的表（此项对于牵扯到数据库操作的程序）

pDestFile        :要写入的文件
pOriginalFile    :原始文件
pwdString        :用于加解密的字符
Output           :输出的信息为空
Return           :如果写入成功返回1，如果写入失败返回0
Others           :其它说明
*************************************************************/
int encryptAndDecodeFileByString(const char *pDestFile,
                                 const char *pOriginalFile, const char *pwdString) {
    FILE *pfr, *pfw;
    //读取
    pfr = fopen(pOriginalFile, "r");
    //写入
    pfw = fopen(pDestFile, "w");
    if (pfr == NULL || pfw == NULL) {
        fclose(pfw);
        fclose(pfr);
        return 0;
    } else {
        int length = getFileSize(pOriginalFile);
        char *newstr = (char *) malloc(sizeof(char) * (length + 1));
        int i;
        for (i = 0; i < length; i++) {
            //获取一个字符
            char ch = fgetc(pfr);
            //不断存入字符
            newstr[i] = ch;
        }
        //字符串处理为'\0'
        newstr[length] = '\0';
        //加密字符串
        str2EncryptString(pwdString, newstr);

        for (i = 0; i < length; i++) {
            //挨个写入字符
            fputc(newstr[i], pfw);
        }
    }
    fclose(pfr);
    //关闭文件
    fclose(pfw);

    return -1;
}

#endif