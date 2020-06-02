//
// Created by zing on 6/2/2020.
//

#include <stdio.h>
#include <strings.h>
#include <errno.h>

/* Create a new stream that refers to a memory buffer.  */
int main() {
    char buf[64];
    bzero(buf, sizeof(buf));
    FILE *f = fmemopen(buf, sizeof(buf), "r+");
    if (f == NULL) {
        perror("fmemopen");
        return errno;
    }

    printf("=> %s\n", buf);
    fwrite("hello", 1, 6, f);
    fflush(f);
    printf("=> %s\n", buf); //hello
    char content[10];
    bzero(content, sizeof(content));
    fseek(f, 2, SEEK_SET);
    fread(content, 1, sizeof(content) - 1, f);
    printf("=> %s\n", content); //llo
    fclose(f);
    return 0;
}