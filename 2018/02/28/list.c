//
// Created by zhangrongxiang on 2018/2/28 15:02
// File list
//

#include<stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node *next;
} node;
typedef struct List {
    int len;
    struct node *start;
} List;

void InitListArray(List *l, int *k, int n) {
    l = (List *) malloc(sizeof(List));
    l->len = n;
    l->start = (node *) malloc(sizeof(node));
    node *t  = l->start;
    for (int i = 0; i < n; i++) {
        t->data = k[i];
        t->next = (node *) malloc(sizeof(node));

//        t->data = k[i];
//        if (i == n - 1) break;
//        t->next = (node *) malloc(sizeof(node));
//        t = t->next;
//        printf("%d\n", t->data);
    }
    t->next = NULL;
}

void ListTraverse(List *l, void(*visit)(int)) {
    node *t = l->start;
    while (t != NULL) {
        visit(t->data);
        t = t->next;
    }
    printf("\n");
}

void visit(int x) {
    printf("%d ", x);
}

int main() {
    List *l;
    int k[5] = {1, 3, 5, 8, 9};
    InitListArray(l, k, 5);
    ListTraverse(l, visit);
    return 0;
}