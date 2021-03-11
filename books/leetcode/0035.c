//
// Created by zing on 2021/3/11.
//

#include <stdio.h>

void p(int *nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        printf("%d\t", nums[i]);
    }
    printf("\n");
}

int searchInsert(int *nums, int numsSize, int target) {
    if (nums[numsSize - 1] < target) {
        return numsSize;
    }
    int i = 0;
    for (; i < numsSize - 1; ++i) {
        if ((nums[i] < target && target <= nums[i + 1])) {
            return i + 1;
        } else if (nums[i] >= target) {
            return i;
        }
    }
    return i;
}

typedef struct {
    int src[4];
    int size;
    int target;
    int res;
} T;

void test() {
    int arr[] = {1, 2, 3};
    int *pp = arr;
    printf("%d", pp[0]);
    printf("\n");
}

int main() {
    T t[] = {
            {{1, 3, 5, 6}, 4, 5, 2},
            {{1, 3, 5, 6}, 4, 2, 1},
            {{1, 3, 5, 6}, 4, 7, 4},
            {{1, 3, 5, 6}, 4, 0, 0},
            {{1,},         1, 0, 0},
    };
    for (int i = 0; i < sizeof(t) / sizeof(t[0]); ++i) {
        int res = searchInsert(t[i].src, t[i].size, t[i].target);
        if (res != t[i].res) {
            printf("%02d. err:     want %d but %d\n", i + 1, t[i].res, res);
        } else {
            printf("%02d. success: want %d and got %d \n", i + 1, t[i].res, res);
        }
    }
    return 0;
}

//执行用时：4 ms, 在所有 C 提交中击败了98.14% 的用户
//内存消耗：5.9 MB, 在所有 C 提交中击败了65.00% 的用户

//搜索插入位置
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会被按顺序插入的位置。