//
// Created by zhangrongxiang on 2017/8/16 10:17.
// Copyright (c) 2017 ZRC . All rights reserved.
//

#include<stdio.h>
void one()
{
    char a[20] = "You_are_a_girl";
    char *p = a;
    char **ptr = &p;
//    printf("p=%d\n",p);
    //printf("ptr=%d\n",ptr);
    //printf("*ptr=%d\n",*ptr);
    printf("**ptr=%c\n", **ptr);
//    ptr++;
    p++;
    p--;
    //printf("ptr=%d\n",ptr);
    //printf("*ptr=%d\n",*ptr);
    printf("**ptr=%c\n", **ptr);
}

void two()
{
    char str[3][10] = {
        {'a', 'b', 'c', 'd'},
        {'A', 'B', 'C', 'D'},
        {'\\', '\'', '\n', '\a'}
    };
    char *p1 = (char *) str;
    char *p2 = (char *) str[1];
    char *p3 = (char *) str[2];
    printf("p1 --> %s\n", p1);
    printf("p2 --> %s\n", p2);
    printf("p3 --> %s\n", p3);
    char *p4 = &str[0][0];
    printf("p4 --> %c\n", (char) *p4);

    char *p5 = (char *) &str;
    printf("p5 --> %c\n", (char) *(++p5));

//    char (*p6)[4] = (char*)str;
//    printf("p6  --> %s\n",*p6);
//    printf("p6  --> %s\n",*p6+1);




//    p1++;
//    printf("%s\n",p1);
//    printf("%s\n",p1);
//    char **p2 = &p1;
//    printf("%s\n",p2);
//    printf("%c\n",str[0][0]);
//    printf("%c\n",str[2][0]);


}

void three()
{
    char str[4][20] = {
        "zhangrongxiang",
        "zhangrxiang",
        "zing",
        "zrx"
    };
    printf("str[0]  -->  %s\n", str[0]);
    printf("str[0][0]  --> %c\n", str[0][0]);


    char *p = (char *) str;
    char *p2 = (char *) str;
//    char *p3 = (char *)str;
    char **pp = &p2;
//    char **pp2 = &p3;
    printf("p  -->  %s\n", p);
    p++;
    printf("p++  -->  %s\n", p);
    printf("*pp  -->  %s\n", *pp);
    printf("**pp  -->  %c\n", **pp);

//    char *p4 = &str;
//    printf("*p4  -->  %s\n",p4);
//    printf("*p4  -->  %c\n",p4[1]);


}
void four()
{
    char *str[4] = {
        "asd",
        "bsd",
        "zhangrongxiang"
    };
    printf("%s\n", *str);
    printf("%s\n", *(str + 1));
    printf("%s\n", *(str + 2));
}

void five()
{
    char str[12] = {
        'z', 'h', 'a', 'n', 'g', 'r', 'x', 'i', 'a', 'n', 'g'
    };

    //str --> zhangrxiang
    printf("str --> %s\n", str);
    //str[0]  --> z
    printf("str[0]  --> %c\n", str[0]);

    char *p = str;
    //*p  --> zhangrxiang
    printf("*p  --> %s\n", p);
    //*(++p)  --> h
    printf("*(++p)  --> %c\n", *(++p));
    //++p  --> angrxiang
    printf("++p  --> %s\n", ++p);

}
void six()
{
    char str[3][13] = {
        {'1', 'z', 'h', 'a', 'n', 'g', 'r', 'x', 'i', 'a', 'n', 'g'},
        {'2', 'z', 'h', 'a', 'n', 'g', 'r', 'x', 'i', 'a', 'n', 'g'},
        {'3', 'z', 'h', 'a', 'n', 'g', 'r', 'x', 'i', 'a', 'n', 'g'},
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 13; ++j) {
            printf(" %c ", str[i][j]);
            if (j == 12) {
                printf("\n");
            }
        }
    }

    char *p = (char *) str;
    char *p2 = (char *) str;
    char *p3 = (char *) str;
    //zhangrxiang
    printf("%s\n", p);
    //hangrxiang
    printf("%s\n", ++p);
    //a
    printf("%c\n", *(++p));

    printf("--------------------------\n");
    printf("%s\n", p2);
    for (int k = 0; k < 39; ++k) {
        printf(" %c ", *(p2++));
        if ((k + 1) % 13 == 0) {
            printf("\n");
        }

    }
    while (*p3 != '\0'){
        printf(" %c ",*(p3++));
    }
    printf("\n");

    char *p4 = (char *) str[1];
    printf("%s\n",p4);

}
int main()
{
//    one();
//    two();
//    three();
//    four();
//    five();
    six();
}