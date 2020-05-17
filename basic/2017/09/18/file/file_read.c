//
// Created by zhangrongxiang on 2017/9/18.
//

#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *file;

    if ((file = fopen("freopen.c", "r")) == NULL) {
        perror("file open error");
        exit(-1);
    }

    /*
     * FILE * freopen(const char * pathconst char * mode,FILE * stream);
     * 函数说明 参数path字符串包含欲打开的文件路径及文件名，参数mode请参考fopen()说明。
     * 参数stream为已打开的文件指针。Freopen()会将原stream所打开的文件流关闭，然后打开参数path的文件。
     * 返回值 文件顺利打开后，指向该流的文件指针就会被返回。如果文件打开失败则返回NULL，并把错误代码存在errno 中。
     */
    if ((file = freopen("freopen.c", "r", file)) == NULL) {
        perror("file reopen error");
        exit(-1);
    }

    printf("freopen success..\n");


    /*
     * 定义函数 FILE * fdopen(int fildes,const char * mode);
     * 函数说明 fdopen()会将参数fildes 的文件描述词，转换为对应的文件指针后返回。
     * 参数mode 字符串则代表着文件指针的流形态，此形态必须和原先文件描述词读写模式相同。
     * 返回值 转换成功时返回指向该流的文件指针。失败则返回NULL，并把错误代码存在errno中。
     */
    FILE *fp = fdopen(0, "w+");
    fprintf(fp, "%s", "hello!\n");
    printf("fileno is %d\n", fileno(fp));
    printf("file fileno is %d\n", fileno(file));

    /*
     *  clearerr（清除文件流的错误旗标）
     *  相关函数 feof
     *  定义函数 void clearerr(FILE * stream);
     *  函数说明 clearerr（）清除参数stream指定的文件流所使用的错误旗标。
     */

    /*
     * fgetc（由文件中读取一个字符）　　
     * int fgetc(FILE * stream);
     * 　函数说明 fgetc()从参数stream所指的文件中读取一个字符。
     * 若读到文件尾而无数据时或出错都返回EOF，
     * 为了区分这两种情况，必须调用ferror()或feof()。返回值 getc()会返回读取到的字符或EOF。
     *
     */
    printf("%c", fgetc(file));
    printf("%c", fgetc(file));
    printf("%c", fgetc(file));
    printf("%c", fgetc(file));
    printf("\n-------------------------------------------------------\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
        if (feof(file))
            printf("file read is over! \n");
        if (ferror(file))
            printf(" read fail!\n");
    }
    if (feof(file))
        printf("\nfile read is over! \n");
    printf("\n-------------------------------------------------------\n");

    fclose(fp);
    /*
     * close()用来关闭先前fopen()打开的文件。会刷新缓冲区内的数据，并释放系统所提供的文件资源。
     * 返回值 若关文件动作成功则返回0，有错误发生时则返回EOF(-1)并把错误代码存到errno。
     */
    if (fclose(file) == EOF) {
        perror("fclose error...");
    }
}