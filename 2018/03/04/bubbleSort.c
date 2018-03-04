//
// Created by zhangrongxiang on 2018/3/4.
//

#include <stdio.h>

void bubble(int arr[], int n) {
    int i = 0, temp;
    for (; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}

void bubbleSort(int arr[], int n) {
    int i = 0;
    for (i = n; i >= 1; i--) {
        bubble(arr, i);
    }
}
void bubbleSort2(int arr[], int n) {
    int i = 0, j = 0, temp;
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() {
    int i = 0;
    int arr[] = {4, 3, 7, 5, 2, 6, 8, 1, 9, 0};
    bubbleSort(arr, 10);
    bubbleSort2(arr, 10);
    for (; i < 10; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}