//
// Created by zhangrongxiang on 2018/2/27 9:57
// File fread
//

#include <stdio.h>
#include <string.h>

void fread1(){
    FILE *file = fopen("./test.txt", "r");
    char buf[16];
    if (file != NULL) {
        while (!feof(file)) {
            memset(buf, 0, sizeof(buf));
            size_t i = fread(buf, 1, sizeof(buf), file);
//            printf("-%d-\n",(int) i);
            printf("%s", buf);
        }
    } else {
        perror("fopen");
    }
}

void fread2() {
    FILE *fp;
    char c[] = "hello world,hello clang";
    char buffer[20];

    /* 打开文件用于读写 */
    fp = fopen("file.txt", "w+");

    /* 写入数据到文件 */
    fwrite(c, strlen(c) + 1, 1, fp);

    /* 查找文件的开头 */
    fseek(fp, 0, SEEK_SET);

    /* 读取并显示数据 */
    fread(buffer, strlen(c) + 1, 1, fp);
    printf("%s\n", buffer);
    fclose(fp);

}

int main() {
    fread2();
    return 0;
}