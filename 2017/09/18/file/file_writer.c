//
// Created by zhangrongxiang on 2017/9/18 14:51
//

#include <stdlib.h>
#include <stdio.h>

#define L 100

int main() {
    const char *f = "test.txt";
    const char *s = "file_writer.c";
    char buf[L], ch, *buff;
    FILE *file, *source;
    if ((file = fopen(f, "a+r")) == NULL) {
        perror("fopen file error");
        exit(-1);
    } else {
        printf("fopen file success!!\n");
    }
    if ((source = fopen(s, "r")) == NULL) {
        perror("fopen file error");
        exit(-1);
    }

    printf("----------------------------s------------------------------\n");
    /*
     * fgets（由文件中读取一字符串）
     * 定义函数 har * fgets(char * s,int size,FILE * stream);
     * 函数说明 fgets()用来从参数stream所指的文件内读入字符并存到参数s所指的内存空间，
     * 直到出现换行字符、读到文件尾或是已读了size-1个字符为止，最后会加上NULL作为字符串结束。
     * 返回值 fgets()若成功则返回s指针，返回NULL则表示有错误发生或已到了文章末尾。
     */
    while (fgets(buf, L, source) != NULL) {
        /*
         * fputs（将一指定的字符串写入文件内）
         * 定义函数 int fputs(const char * s,FILE * stream);
         * 函数说明 fputs()用来将参数s所指的字符串写入到参数stream所指的文件内，
         * 字符串终止符null不写出。
         * 返回值 若成功则返回写出的字符个数，返回EOF则表示有错误发生。
         */
        if (fputs(buf, file) == EOF) {
            perror("fputs error ...");
            exit(-1);
        }
    }
    printf("----------------------------c------------------------------\n");
    while ((ch = fgetc(file)) != EOF) {
        if (feof(file))
            printf("file read is over! ");
        if (ferror(file))
            printf(" read fail!");
        /*
         *  fputc（将一指定字符写入文件流中）　　
         *  定义函数 int fputc(int c,FILE * stream);
         *  函数说明 fputc 会将参数c 转为unsigned char 后写入参数stream 指定的文件中。
         *  返回值 fputc()会返回写入成功的字符，即参数c。若返回EOF则代表写入失败。
         */
        if (fputc(ch, file) == EOF) {
            perror("writer error ....");
        }
    }


    /*
     *
     *fread（从文件流读取数据）
     * 定义函数 size_t fread(void * ptr,size_t size,size_t nmemb,FILE * stream);
     * 函数说明 fread()用来从文件流中读取数据。参数stream为已打开的文件指针，
     * 参数ptr 指向欲存放读取进来的数据空间，读取的字符数以参数size*nmemb来决定。
     * fread()会返回实际读取到的nmemb数目，
     * 如果此值比参数nmemb 来得小，则代表可能读到了文件尾或有错误发生，这时必须用feof()或ferror()来决定发生什么情况。
     * 返回值 返回实际读取到的num数目，注意：返回num是一个整形，
     * 所以当实际读的数不是一个整形时（小于nmember时，如果返回零，并不代表到了文章末尾），
     * 也会返回一个整形，这时应该用其他函数测出所读取的真正长度。
     */
    // obtain file size:
    fseek(file, 0, SEEK_END);
    int lSize = ftell(file);
    rewind(file);
    buff = (char *) malloc(sizeof(char) * lSize);
    while (fread(buff, 1, lSize, file)) {
        printf("%s", buff);
        if (feof(file)) {
            printf("file over\n");
            break;
        }
        if (ferror(file)) {
            printf(" read fail!");
            break;
        }
        /*
         * fwrite（将数据写至文件流）
         * 定义函数 size_t fwrite(const void * ptr,size_t size,size_t nmemb,FILE * stream);
         * 函数说明 fwrite()用来将数据写入文件流中。
         * 参数stream为已打开的文件指针，参数ptr 指向欲写入的数据地址，总共写入的字符数以参数size*nmemb来决定。
         * fwrite()会返回实际写入的nmemb数目。
         * 返回值 返回实际写入的nmemb数目，所以当用fwrite()来处理fread()读取的数据时，
         * 有可能不能一次全部将fread()读来的数据都写进去，所以最好用while()来处理。
         */
        if (fwrite(buff, 1, lSize, file) == 0) {
            perror("fwrite error");
            exit(-1);
        }
    }

    /*
     *
     * feof（检查文件流是否读到了文件尾）
     *  相关函数 fopen，fgetc，fgets，fread
　　 * 表头文件 #include<stdio.h>
　　 * 定义函数 int feof(FILE * stream);
　　 * 函数说明 feof()用来侦测是否读取到了文件尾，尾数stream为fopen（）所返回之文件指针。如果已到文件尾则返回非零值，其他情况返回0。
　　 * 返回值 返回非零值代表已到达文件尾。

　　 * fflush（更新缓冲区）
　　 * 相关函数 write，fopen，fclose，setbuf
　　 * 表头文件 #include<stdio.h>
　　 * 定义函数 int fflush(FILE* stream);
　　 * 函数说明 fflush()会强迫将缓冲区内的数据写回参数stream指定的文件中。如果参数stream为NULL，fflush()会将所有打开的文件数据更新。
　　 * 返回值 成功返回0，失败返回EOF，错误代码存于errno中。
　　 * 错误代码 EBADF 参数stream 指定的文件未被打开，或打开状态为只读。其它错误代码参考write（）。

　　 * fseek（移动文件流的读写位置）
　　 * 相关函数 rewind，ftell，fgetpos，fsetpos，lseek
　　 * 表头文件 #include<stdio.h>
　　 * 定义函数 int fseek(FILE * stream,long offset,int whence);
　　 * 函数说明 fseek()用来移动文件流的读写位置。参数stream为已打开的文件指针，参数offset为根据参数whence来移动读写位置的位移数。
　　 * 参数 whence为下列其中一种:
　　 * SEEK_SET从距文件开头offset位移量为新的读写位置。SEEK_CUR 以目前的读写位置往后增加offset个位移量。
　　 * SEEK_END将读写位置指向文件尾后再增加offset个位移量。
　　 * 当whence值为SEEK_CUR 或SEEK_END时，参数offset允许负值的出现。
　　 * 下列是较特别的使用方式:
　　 * 1) 欲将读写位置移动到文件开头时:fseek(FILE *stream,0,SEEK_SET);
　　 * 2) 欲将读写位置移动到文件尾时:fseek(FILE *stream,0,0SEEK_END);
　　 * 返回值 当调用成功时则返回0，若有错误则返回-1，errno会存放错误代码。
　　 * 附加说明 fseek()不像lseek()会返回读写位置，因此必须使用ftell()来取得目前读写的位置。
     *
     */
    return 0;
}