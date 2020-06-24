//
// Created by zing on 5/19/2020.
//

#include <stdio.h>
#include <errno.h>

/*
 * Create a temporary file and open it read/write.
 */
int main(int argc, char *argv[]) {
    FILE *tmp = tmpfile();
    if (tmp == NULL) {
        perror("tmpfile");
        return -1;
    }
    int ii = fputs("hello world\n", tmp);
    printf("fputs %d\n",ii);
    fputs("hello world\n", tmp);

    size_t i = fwrite("hello world",1,10,tmp);
    printf("fwrite %zu\n",i);
    if (i == -1){
        perror("fwrite");
        return errno;
    }
    char content[64] = {};
    fseek(tmp, 0, SEEK_SET);
    i = fread(content, 1, sizeof(content), tmp);
    printf("fread %zu\n",i);
    if (i == -1){
        perror("fread");
        return errno;
    }
    printf("content %s\n", content);

    char *res = fgets(content, sizeof(content), tmp);
    if (res == NULL) {
        perror("fgets");
        return -1;
    }
    printf("content %s\n", content);
    fclose(tmp);

    fread(content, 1, 20, tmp);
    printf("content %s\n", content);
    return 0;
}
