//
// Created by 张荣响 on 2017/8/8.
//

#include <stdio.h>

int main() {
    int x = 5;
    printf("%d and ", sizeof(x++)); // note 1
    printf("%d\n", x); // note 2
    return 0;
}