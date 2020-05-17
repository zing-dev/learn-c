//
// Created by zhangrongxiang on 2017/9/15.
//
#include <stdio.h>
#include <string.h>

int main() {
    long long a = 128782101083494l;
//    a = 140728790530240;
    a = 128782101083494;
    puts((char *) &a);
    printf("%p\n", &a);
    printf("-->  %16lX\n", a);
    // printf(" -->  %s\n",(char *)a);
    printf("%2d\n", (char) (a));

    printf("---------------------------------------\n");
    long long aa = 0x676e697a;
//    1735289210
    printf("%ld\n", aa);
    long aaa = 1735289210;
    printf("%s\n", (char *) (&aaa));



    /**
    long long i;
    for ( i = 0; i < 12878210108349412878210; ++i) {
        if(strcmp("i love you",(char *)&i) == 0)
            printf("%lld\n",i);
        if(strcmp("fuck u",(char *)&i) == 0){
            printf("------->>>>>>>>>>>%lld\n",i);
            break;
        }

        if(i % 100000000 == 0)
            printf("----------%lld--------\n",i);
    }

     */
    return 0;
}