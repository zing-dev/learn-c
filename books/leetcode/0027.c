//
// Created by zing on 2021/3/9.
//
#include <stdio.h>
#include <string.h>

int removeElement(int *nums, int numsSize, int val) {
    int current = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != val) {
            nums[current] = nums[i];
            current++;
        }
    }
    return current;
}
//定义一个指向当前数组的指针变量
//遍历元素判断当前值与给定删除值的比较，若不相等，则将当前值赋予当前指针变量指向的值，指针变量朝前进一
//移除元素
typedef struct {
    int data[1024];
    int length;
    int val;
    int res;
} T;

char *p(char *str, int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        char s[10] = {};
        sprintf(s, "%d,", arr[i]);
        strcat(str, s);
    }
    return str;
}

//删除排序数组中的重复项
int main() {
    T t[] = {
            {.data = {0}, .length = 1, .val=0, .res = 0},
            {.data = {0, 1}, .length = 2, .val=0, .res = 1},
            {.data = {0, 0, 1}, .length = 3, .val=0, .res = 1},
            {.data = {0, 0, 1, 2}, .length = 4, .val=1, .res = 3},
            {.data = {0, 1, 1, 2, 3}, .length = 5, .val=1, .res = 3},
            {.data = {0, 0, 1, 2, 2, 2}, .length = 6, .val=2, .res = 3},
    };
    //printf("%lu\n", sizeof(t) / sizeof(t[0]));
    char str[32] = {};
    for (int i = 0; i < sizeof(t) / sizeof(t[0]); ++i) {
        int l = removeElement(t[i].data, t[i].length, t[i].val);
        if (l != t[i].res) {
            printf("%d err: want %d but %d %s \n", i + 1, t[i].res, l, p(str, t[i].data, t[i].res));
        } else {
            printf("%d success: want %d so %d => %s \n", i + 1, t[i].res, l, p(str, t[i].data, t[i].res));
        }
        bzero(str, sizeof(str));
    }
    return 0;
}
