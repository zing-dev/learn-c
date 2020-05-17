//
// Created by zhangrongxiang on 2017/12/26 17:36
// File 1
//

#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 33

int input(int);

char a[N];

int main() {
    int i, n, sum = 0;

    n = input(1);
    for (i = n - 1; i >= 0; i--)                                                    //二进制输入检错
    {
        if ((a[i] - '0') != 1 && (a[i] - '0') != 0)
            n = input(0);
    }

    for (i = n - 1; i >= 0; i--)                                                    //二进制转换十进制
        sum += (a[i] - '0') * ((int) pow(2, n - 1 - i));
    printf(">>转换后的十进制数为:\n%d\n", sum);
    return 0;
}

int input(int m) {
    printf(">>%s输入一个二进制数:\n", m ? "请" : "输入有误，请重新");
    scanf("%s", a);
    return strlen(a);

}