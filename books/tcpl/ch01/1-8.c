//
// Created by zing on 6/7/2020.
//


#include <stdio.h>
#include <errno.h>
#include <strings.h>

int main(int argc, char *argv[]) {
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __PRETTY_FUNCTION__);
    printf("%s\n", __func__);
    printf("%s\n", __FILE__);
    printf("%s\n", __BASE_FILE__);
    printf("%s\n", __DATE__);
    printf("%d\n", __unix);
    printf("%d\n", __linux);
    printf("%d\n", __x86_64);

    FILE *file = fopen(__FILE__, "r");
    if (file == NULL) {
        perror("fopen");
        return errno;
    }
    char content[BUFSIZ];
    bzero(content, BUFSIZ);

    size_t count = fread(content, 1, BUFSIZ, file);
    printf("%zu\n", count);
    if (count > 0) {
        printf("read eof\n");
        printf("%s\n", content);

        int blank, tab, line;
        blank = 0;
        tab = 0;
        line = 0;
        for (int i = 0; i < count; ++i) {
            if (content[i] == ' ') {
                blank += 1;
            } else if (content[i] == '\t') {
                tab += 1;
            } else if (content[i] == '\n') {
                line += 1;
            }
        }
        printf("blank:%d,tab:%d,line:%d\n", blank, tab, line);
    }
    return 0;
}