//
// Created by zhangrongxiang on 2018/2/24 9:59
// File confstr
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[128];
    confstr(_CS_PATH, buf, sizeof(buf));
    printf("_CS_PATH -> %s\n", buf);// /bin:/usr/bin
    confstr(_CS_GNU_LIBC_VERSION, buf, sizeof(buf)); // glibc 2.19
    printf("_CS_GNU_LIBC_VERSION -> %s\n", buf);
    confstr(_CS_GNU_LIBPTHREAD_VERSION, buf, sizeof(buf)); // glibc 2.19
    printf("_CS_GNU_LIBPTHREAD_VERSION -> %s\n", buf); //NPTL 2.19

    ////////////////////////////////////////////////////////////////////////////
    char *pathbuf;
    size_t n;
    n = confstr(_CS_PATH, NULL, (size_t) 0);
    pathbuf = malloc(n);
    if (pathbuf == NULL)
        abort();
    confstr(_CS_PATH, pathbuf, n);
//    _CS_PATH -> /bin:/usr/bin; n -> 14
    printf("_CS_PATH -> %s; n -> %d\n", pathbuf, (int)n);
    return 0;
}