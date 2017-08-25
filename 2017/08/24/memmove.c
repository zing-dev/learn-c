//
// Created by zhangrxiang on 17-8-24.
//

#include <stdio.h>
#include <string.h>
int main(void)
{

//    由src所指内存区域复制count个字节到dest所指内存区域。
//    src和dest所指内存区域可以重叠，但复制后dest内容会被更改。函数返回指向dest的指针。
    /**
     * memmove的处理措施：
     *（1）当源内存的首地址等于目标内存的首地址时，不进行任何拷贝
     *（2）当源内存的首地址大于目标内存的首地址时，实行正向拷贝
     *（3）当源内存的首地址小于目标内存的首地址时，实行反向拷贝
     */
    char s[] = "Golden Global View";
    printf("old len is %ld\n", strlen(s));
//    memmove(s, s + 7, strlen(s) + 1 - 7);//+1是取'\0',可以去掉看下结果
    memmove(s, s + 7, sizeof(s) -7);//+1是取'\0',可以去掉看下结果
    printf("%s\n", s);
    printf("now len is %ld\n", strlen(s));
    printf("now sizeof() is %ld\n", sizeof(s));
    return 0;
}