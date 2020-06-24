//
// Created by zing on 6/1/2020.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Return a malloc'd copy of at most N bytes of STRING.  The
   resultant string is terminated even if no null terminator
   appears before STRING[N].  */
int main(int argc, char *argv[]) {
    char *str = strndup("Return a malloc'd copy of at most N bytes of STRING.", 20);
    printf("%s\n",str);
    printf("%lu\n",strlen(str));
    free(str);
    return 0;
}
