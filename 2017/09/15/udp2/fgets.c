//
// Created by zhangrongxiang on 2017/9/15.
//

#include<string.h>
#include<stdio.h>

/**
 * 从文件结构体指针stream中读取数据，每次读取一行
 * @return
 */
int main(void) {
    FILE *stream;
    char string[] = "1\n2\n3\n4\n5\n6\n";
    char msg[20];
    /*open a file for update*/
    stream = fopen("test", "w+");
    /*write a string into the file*/
    fwrite(string, strlen(string), 1, stream);
    /*seek to the start of the file*/
    fseek(stream, 0, SEEK_SET);
    /*read a string from the file*/
    fgets(msg, strlen(string) + 1, stream);
    printf("%s", msg);
    fgets(msg, strlen(string) + 1, stream);
    /*display the string*/
    printf("%s", msg);


    /////////////////////////////////////////////////////
    fseek(stream, 0, SEEK_SET);
    while (fgets(msg, 20, stream))
        printf("%s", msg);

    fclose(stream);
    return 0;
}