//
// Created by zhangrongxiang on 2017/9/18 15:51
//

#include <stdlib.h>
#include <stdio.h>


/*
 *
 * fread（从文件流读取数据）
 * 定义函数 size_t fread(void * ptr,size_t size,size_t nmemb,FILE * stream);
 * 函数说明 fread()用来从文件流中读取数据。参数stream为已打开的文件指针，
 * 参数ptr 指向欲存放读取进来的数据空间，读取的字符数以参数size*nmemb来决定。
 * fread()会返回实际读取到的nmemb数目，
 * 如果此值比参数nmemb 来得小，则代表可能读到了文件尾或有错误发生，这时必须用feof()或ferror()来决定发生什么情况。
 * 返回值 返回实际读取到的num数目，注意：返回num是一个整形，
 * 所以当实际读的数不是一个整形时（小于nmember时，如果返回零，并不代表到了文章末尾），
 * 也会返回一个整形，这时应该用其他函数测出所读取的真正长度。
 */
#define NMEMB 3

int main() {
    struct data {
        char name[20];
        int size;
    } s[NMEMB];
    FILE *stream;
    int i;
    stream = fopen("read.txt", "r");
    fseek(stream, 0, SEEK_END);
    int lSize = ftell(stream);
    rewind(stream);
    fread(s, sizeof(struct data), (int) (lSize / sizeof(struct data)), stream);
    fclose(stream);
//    for (i = 0; i < NMEMB; i++)
//        printf("name[%d]=%-20s:size[%d]=%d\n", i, s->name, i, s->size);
//    printf("%s",s->name);
}
