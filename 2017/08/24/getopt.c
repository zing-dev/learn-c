//
// Created by zhangrxiang on 17-8-24.
//

#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int ch;
    if(opterr){
        printf("err.........................\n");
    }
    opterr = 0;
    while ((
        ch = getopt(argc, argv, "a:bcde")
    ) != -1) {
        switch (ch) {
            case 'c':
                printf("xxxtest");
            case 'a':
                printf("option a:’%s’\n", optarg);
                break;
            case 'b':
                printf("option b :b\n");
                break;
            default:
                printf("other option :%c\n", ch);
        }
        printf("optopt +%c\n", optopt);
    }
    if(argc != 2){
        printf("input a argv!!!\n");
        exit(1);
    }
    return 0;

//    getopt() 所设置的全局变量包括：
//    char *optarg——当前选项参数字串（如果有）。
//    int optind——argv的当前索引值。当getopt()在while循环中使用时，循环结束后，剩下的字串视为操作数，在argv[optind]至argv[argc-1]中可以找到。
//    int opterr——这个变量非零时，getopt()函数为“无效选项”和“缺少参数选项，并输出其错误信息。
//    int optopt——当发现无效选项字符之时，getopt()函数或返回'?'字符，或返回':'字符，并且optopt包含了所发现的无效选项字符。

}