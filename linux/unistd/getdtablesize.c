//
// Created by zhangrongxiang on 2018/2/26 13:46
// File getdtablesize
//


#include <stdio.h>
//getdtablesize - get the file descriptor table size (LEGACY)
int main(){
    int size = getdtablesize();
    printf("%d\n",size);//65536
    return 0;
}
