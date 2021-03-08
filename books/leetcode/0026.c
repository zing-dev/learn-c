//
// Created by zing on 2021/3/8.
//
#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize == 0){
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

int main() {
    int arr[] = {0};
    int i = removeDuplicates(arr,1);
    printf("want %d but %d", 1, i);
    return 0;
}