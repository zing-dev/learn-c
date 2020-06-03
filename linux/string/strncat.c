//
// Created by zhangrongxiang on 2018/2/7 17:36
// File strncat
//

#include <stdio.h>
#include <string.h>

//C 库函数 char *strncat(char *dest, const char *src, size_t n)
// 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾，直到 n 字符长度为止。
/* Copy no more than N characters of SRC to DEST.  */
int main() {
    char src[50], dest[50];
    strcpy(src, "This is source");
    strcpy(dest, "This is destination");
    printf("%d\n", (int) strlen(src));//14
    int old = (int) strlen(dest);//19
    printf("%d\n", old);
    if (dest[old] == '\0') {
        printf("NULL\n");//true
    }
    char *str = strncat(dest, src, strlen(src));
    printf("%s\n", dest);//This is destinationThis is source
    printf("%s\n", str);//This is destinationThis is source
    printf("%d\n", str == dest);//1
    //33 == 33 == 33
    printf("%d == %d == %d\n", (int) strlen(dest), (int) strlen(str), (int) (old + strlen(src)));
    printf("%c\n", str[old]);//T
    printf("%s\n", &str[old]);//This is source
    return 0;
}