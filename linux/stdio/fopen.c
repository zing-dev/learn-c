//
// Created by zing on 5/19/2020.
//

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen("test.txt", "w+");
    if (file == NULL) {
        perror("fopen");
        return -1;
    }
    fputs("hello world by fputs\n", file);
    fseek(file, 0, SEEK_SET);

    char content[128] = {};
    fgets(content, sizeof(content), file);
    printf("fgets => %s\n", content);

    char *str = "hello by fwrite\n";
    fwrite(str, strlen(str), 1, file);
    fseek(file, (long)strlen(content), SEEK_SET);

    char str2[128];
    fread(str2, sizeof(str2), 1, file);
    printf("fread => %s\n", str2);
    fclose(file);

    return 0;
}
