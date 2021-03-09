//
// Created by zing on 2021/3/8.
//
#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int low = 0;
    int fast = 1;
    for (; fast < numsSize; fast++) {
        if (nums[low] != nums[fast]) {
            low++;
            nums[low] = nums[fast];
        }
    }
    return low + 1;
}

typedef struct {
    int data[1024];
    int length;
    int res;
} T;

//删除排序数组中的重复项
int main() {
    T t[] = {
            {.data = {0}, .length = 1, .res = 1},
            {.data = {0, 1}, .length = 2, .res = 2},
            {.data = {0, 0, 1}, .length = 3, .res = 2},
            {.data = {0, 0, 1, 2}, .length = 4, .res = 3},
            {.data = {0, 0, 1, 2, 3}, .length = 5, .res = 4},
            {.data = {0, 0, 1, 1, 2, 2}, .length = 6, .res = 3},
    };
    for (int i = 0; i < sizeof(t)/sizeof(t[0]); ++i) {
        int l = removeDuplicates(t[i].data, t[i].length);
        if (l != t[i].res) {
            printf("err: want %d but %d\n", t[i].res, l);
        } else {
            printf("success: want %d so %d\n", t[i].res, l);
        }
    }
    return 0;
}