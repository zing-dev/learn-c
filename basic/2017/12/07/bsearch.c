//
// Created by 张荣响 on 2017/8/8.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct DATA {
    int nr;
    char const *value;
} Data;
Data data[] = {
        {1, "Foo"},
        {2, "Bar"},
        {3, "Hello"},
        {4, "World"}
};

int data_cmp(void const *lhs, void const *rhs) {
    Data const *const l = lhs;
    Data const *const r = rhs;
    if (l->nr < r->nr)
        return -1;
    else if (l->nr > r->nr)
        return 1;
    else
        return 0;
    // return (l->nr > r->nr) - (l->nr < r->nr); // possible shortcut
    // return l->nr - r->nr; // erroneous shortcut (fails if INT_MIN is present)
}

int main(void) {
    Data key = {key.nr = 2};

//    void* bsearch (const void* key, const void* base,
//                   size_t num, size_t size,
//                   int (*compar)(const void*,const void*));
    Data const *res = bsearch(&key, data, sizeof data / sizeof data[0], sizeof data[0], data_cmp);
    if (res) {
        printf("No %d: %s\n", (*res).nr, res->value);
    } else {
        printf("No %d not found\n", key.nr);
    }
}