//
// Created by zhangrongxiang on 2017/12/7 17:09
// File qsort
//

/* qsort example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

int values[] = {40, 10, 100, 90, 20, 25};

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int compare2(const void *a, const void *b) {
    return (*(int *) b - *(int *) a);
}

int main() {
    int n;
    /**
     * void qsort (void* base, size_t num, size_t size,int (*compar)(const void*,const void*));
     *
     */
    qsort(values, 6, sizeof(int), compare);
    for (n = 0; n < 6; n++)
        printf("%d\t", values[n]);
    printf("\n");
    qsort(values, 6, sizeof(int), compare2);
    for (n = 0; n < 6; n++)
        printf("%d\t", values[n]);
    printf("\n");
    return 0;
}