//
// Created by zhangrongxiang on 2018/3/4.
//
#include <stdio.h>
int main() {
    int arr[] = {4, 3, 7, 5, 2, 6, 8, 1, 9, 0};
    int i = 0;
    ///////////////////////////////1///////////////////////////////////////
    for (; i < 10 - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    ///////////////////////////////////2///////////////////////////////////
    for (i = 0; i < 10 - 2; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
        }
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    //////.....///
    return 0;
}
