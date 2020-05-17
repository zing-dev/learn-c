//
// Created by zhangrongxiang on 2018/1/12 17:53
// File fread_int
//

#include <stdio.h>
#include <stdlib.h>

/**
 * 　(1)size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
 * 其中，ptr：指向保存结果的指针；size：每个数据类型的大小；count：数据的个数；stream：文件指针
 * 函数返回读取数据的个数。
 *
 * 　(2)size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );　　　　
 * 其中，ptr：指向保存数据的指针；size：每个数据类型的大小；count：数据的个数；stream：文件指针
 * 函数返回写入数据的个数。
 * @return
 */
int main() {
    FILE *pFile;
    int buffer[] = {1, 2, 3, 4};
    if ((pFile = fopen("myfile.txt", "wb")) == NULL) {
        printf("cant open the file");
        exit(0);
    }
    //可以写多个连续的数据(这里一次写4个)
    fwrite(buffer, sizeof(int), 4, pFile);
    fclose(pFile);
    return 0;
}