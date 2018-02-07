//
// Created by 张荣响 on 2018/2/5.
//

#include<stdio.h>
#include<string.h>
#include <stdbool.h>

char a[100005];

int change(int x, int y) {
    int temp = 0;

    for (int i = x; i <= y; i++) {
        if (a[i] > '9') {
            temp = temp * 16 + a[i] - 'A' + 10;
        } else {
            temp = temp * 16 + a[i] - '0';
        }
    }

    return temp;
}

int main() {
    int n;

    scanf("%d", &n);

    while (n--) {
        scanf("%s", a);

        int len = strlen(a);
        bool flag = true;
        int num = 0;

        if (len % 3 == 1)                //为什么是对3取模？
        {
            printf("%o", change(0, 0));
            flag = false;
            num = 1;
        } else if (len % 3 == 2) {
            printf("%o", change(0, 1));
            flag = false;
            num = 2;
        }

        for (int i = num; i < len; i = i + 3) {
            if (flag) {
                flag = false;
                printf("%o", change(i, i + 2));
            } else
                printf("%04o", change(i, i + 2));        //这个地方为什么要补0？
        }

        printf("\n");
    }

    return 0;
}