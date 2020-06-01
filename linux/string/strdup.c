//
// Created by zing on 6/1/2020.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Duplicate S, returning an identical malloc'd string.  */
int main(int argc, char *argv[]) {
    char *src = "This is the strdup test";
    char *dest;
    dest = strdup(src);
    printf("%s\n", dest);
    printf("%lu\n", strlen(dest));//23
    free(dest);
    printf("%s\n", dest);
    printf("%lu\n", strlen(dest));//0
    return 0;
}
