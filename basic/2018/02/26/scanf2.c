//
// Created by zhangrongxiang on 2018/2/26 12:46
// File scanf2
//

/* scanf example */
#include <stdio.h>

int main() {
    char str[80];
    int i;

    printf("Enter your family name: ");
    scanf("%79s", str);
    printf("Enter your age: ");
    scanf("%d", &i);
    printf("Mr. %s , %d years old.\n", str, i);
    printf("Enter a hexadecimal number: ");
    scanf("%x", &i);
    printf("You have entered %#x (%d).\n", i, i);

    return 0;
}