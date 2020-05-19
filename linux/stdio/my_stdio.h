//
// Created by zing on 5/19/2020.
//

#ifndef LEARN_C_MY_STDIO_H
#define LEARN_C_MY_STDIO_H

extern void test() {
    printf("ok!");
}

extern void file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("open");
        file = fopen(filename, "w");
        if (file == NULL) {
            perror("create");
            return;
        }
        printf("create file %s success\n", filename);
    }
}

#endif //LEARN_C_MY_STDIO_H
