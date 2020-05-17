//
// Created by zhangrongxiang on 2017/12/11 14:03
// File enum
//


#include <stdio.h>

#ifdef TRUE
#undef TRUE
#endif

#ifdef FALSE
#undef FALSE
#endif

typedef enum {
    FALSE,
    TRUE,
    TWO
} Boolean;

int main() {

    Boolean t = TRUE;
    Boolean f = FALSE;
    printf("%d\n", FALSE);
    printf("%d\n", TRUE);
    printf("%d\n", TWO);
    printf("%d\n", t);
    printf("%d\n", f);
}
