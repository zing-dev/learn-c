//
// Created by zing on 6/1/2020.
//

#include <stdio.h>
#include <string.h>

/* Put a transformation of SRC into no more than N bytes of DEST.  */
int main(int argc, char *argv[]) {
    char dst[30];
    char dst2[130];
    memset(dst, 0, sizeof(dst));
    char src[] = "Put a transformation of SRC into no more than N bytes of DEST.";
    size_t len = strxfrm(dst, src, 15);
    printf("%lu\n", len); // 62
    printf("%lu\n", strlen(src)); //62
    printf("%lu\n", sizeof(src)); // 63
    printf("%s\n", dst);// Put a transform
    printf("%lu\n", strlen(dst)); //15
    printf("%lu\n", sizeof(dst)); //30

    len = strxfrm(dst2,src,100);
    printf("%lu\n", len); // 62
    printf("%lu\n", strlen(dst2)); //62
    printf("%s\n", dst2);
    return 0;
}
