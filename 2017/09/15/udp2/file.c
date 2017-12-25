//
// Created by zhangrongxiang on 2017/9/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *
 * 方式      含义
 * "r" 打开，只读；
 * "w" 打开，文件指针指到头，只写；
 * "a" 打开，指向文件尾，在已存在文件中追加；
 * "rb" 打开一个二进制文件，只读；
 * "wb" 打开一个二进制文件，只写；
 * "ab" 打开一个二进制文件，进行追加 ；
 * "r+" 以读/写方式打开一个已存在的文件；
 * "w+" 以读/写方式建立一个新的文本文件 ；
 * "a+" 以读/写方式打开一个文件文件进行追加 ；
 * "rb+" 以读/写方式打开一个二进制文件；
 * "wb+" 以读/写方式建立一个新的二进制文件 ；
 * "ab+" 以读/写方式打开一个二进制文件进行追加 ；
 * 当用fopen()成功的打开一个文件时，该函数将返回一个FILE指针，如果文件打开失败，将返回一个NULL指针。
 * 当用fclose()关闭了文件，则返回一个0值，否则返回一个非0值
 *
 */



/*
 * 读写文件中字符的函数(一次只读写文件中的一个字符)：
 * int fgetc(FILE *stream);
 * int getchar(void);
 * int fputc(int ch,FILE *stream);
 * int putchar(int ch);
 * int getc(FILE *stream);
 * int putc(int ch,FILE *stream);
 */
int main() {
    FILE *fp, *fout;
    char ch;
    char buf[1024];
    if ((fout = fopen("out.txt", "w")) == NULL) {
        printf("open file error");
        exit(-1);
    }
    if ((fp = fopen("file.c", "r")) == NULL) {
        printf("file cannot be opened/n");
        exit(1);
    }
    /**************int fgetc(FILE *stream);********************/
    /*
        while ((ch = fgetc(fp)) != EOF)
        fputc(ch, stdout);
     */

    /**************int getchar(void);********************/
    /*while ((ch = getchar()) != '\0') {
        putchar(ch);
    }
    */
    /**************int getc(void);********************/
    /*while ((ch = getc(fp)) != EOF){
        putc(ch,stdout);
//        putc(ch,fout);
    }
     */

    /*
    do{
        if(buf[strlen(buf) -1 ] == '\n'){
            buf[strlen(buf) -1 ] = '\0';
        }
        if(buf[strlen(buf)] == EOF)
            break;
        printf("%s\n",buf);
    }while (fgets(buf, 1024, fp));
     */

    while (fgets(buf, 1024, fp)) {
        printf("%s", buf);
    }
    fclose(fp);
}