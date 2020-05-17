//
// Created by 张荣响 on 2018/2/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    char str[30] = "2030300 This is test";
    char *ptr;
    long ret;

    ret = strtol(str, &ptr, 10);
    printf("%ld\n", ret);//2030300
    printf("%s\n", ptr);
    // This is test%

    ret = strtol("hello", &ptr, 10);
    printf("%ld\n", ret);//0
    printf("%s\n", ptr);//hello


    ret = strtol("10hello", &ptr, 16);
    printf("%ld\n", ret);//16?
    printf("%s\n", ptr);//hello
    //////////////////////////////////////////////
    // 带错误处理的剖析
    const char *p = "10 200000000000000000000000000000 30 -40 junk";
    printf("Parsing '%s':\n", p);
    char *end;
    for (long i = strtol(p, &end, 10);
         p != end;
         i = strtol(p, &end, 10))
    {
        printf("'%.*s' -> ", (int)(end-p), p);
        p = end;
        if (errno == ERANGE){
            printf("range error, got ");
            errno = 0;
        }
        printf("%ld\n", i);
    }

    // 不带错误处理的剖析
    printf("\"1010\" in binary  --> %ld\n", strtol("1010",NULL,2));
    printf("\"12\" in octal     --> %ld\n", strtol("12",NULL,8));
    printf("\"A\"  in hex       --> %ld\n", strtol("A",NULL,16));
    printf("\"junk\" in base-36 --> %ld\n", strtol("junk",NULL,36));
    printf("\"012\" in auto-detected base  --> %ld\n", strtol("012",NULL,0));
    printf("\"0xA\" in auto-detected base  --> %ld\n", strtol("0xA",NULL,0));
    printf("\"junk\" in auto-detected base -->  %ld\n", strtol("junk",NULL,0));
    return 0;
}