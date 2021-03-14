//
// Created by zing on 2021/3/14.
//

#include <stdio.h>
/* Return the system file descriptor for STREAM.  */
// extern int fileno (FILE *__stream) __THROW __wur;

int main() {
    FILE *f = fopen("Makefile", "r");
    if (f == NULL) {
        perror("fopen");
    }
    int i = fileno(f);
    printf("%d\n", i);
    int i1 = fclose(f);
    printf("%d\n", i1);
}