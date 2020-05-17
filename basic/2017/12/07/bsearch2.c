//
// Created by zhangrongxiang on 2017/12/7 17:06
// File bsearch2
//

/* bsearch example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort, bsearch, NULL */

int compareints(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int values[] = {50, 20, 60, 40, 10, 30};

int main() {
    int *pItem;
    int key = 40, i = 0;
    qsort(values, 6, sizeof(int), compareints);
    for (i = 0; i < 6; ++i) {
        printf("%d\t", values[i]);
    }
    printf("\n");
    pItem = (int *) bsearch(&key, values, 6, sizeof(int), compareints);
    if (pItem != NULL)
        printf("%d is in the array.\n", *pItem);
    else
        printf("%d is not in the array.\n", key);
    return 0;
}