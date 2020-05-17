//
// Created by zhangrongxiang on 2017/9/18.
// today is my birthday!!
//


//测试gets最多读取字符是否超过1024
#include <stdio.h>
#include <string.h>

/*
 * gets函数原型：char*gets(char*buffer);//读取字符到数组：gets(str);str为数组名。
 * gets函数功能：从键盘上输入字符，直至接受到换行符或EOF时停止，并将读取的结果存放在buffer指针所指向的字符数组中。
 * 读取的换行符被转换为null值，做为字符数组的最后一个字符，来结束字符串。
 */
int main() {
    char str[2048];       //听说gets最多可以读取1024个字符，我们设定一个2048的数组
    gets(str);            //从键盘输入大于1024个字符
    int cnt;
    printf("cnt = %d\n", (int) strlen(str));   //cnt的值就是数组元素个数，是否大于1024呢？？？
    return 0;
}

