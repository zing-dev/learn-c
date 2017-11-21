//
// Created by zhangrongxiang on 2017/11/21 15:20
// File 7
//

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    wchar_t wt = L'张';
    wprintf(L"%c\n", wt); //输出wt（单个字符）
    wchar_t wts[] = L"哈哈哈";
    wprintf(L"%s\n", wts); //输出 wts （字符串）
    return 0;
}