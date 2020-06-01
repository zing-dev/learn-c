//
// Created by zing on 6/1/2020.
//

#include <stdio.h>
#include <string.h>

/* Put a transformation of SRC into no more than N bytes of DEST.  */
int main(int argc, char *argv[]) {
    char dst[30];
    memset(dst, 0, sizeof(dst));
    char src[] = "/* Put a transformation of SRC into no more than N bytes of DEST.  */";
    size_t len = strxfrm(dst, src, 15);
    printf("%lu\n", len); // 69
    printf("%lu\n", strlen(src)); //69
    printf("%lu\n", sizeof(src)); // 70
    printf("%s\n", dst);
    printf("%lu\n", strlen(dst)); //15
    printf("%lu\n", sizeof(dst)); //30
    return 0;
}
