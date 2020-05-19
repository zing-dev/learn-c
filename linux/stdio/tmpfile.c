//
// Created by zing on 5/19/2020.
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *tmp = tmpfile();
    if (tmp == NULL){
        perror("tmpfile");
        return -1;
    }
    fputs("hello world\n",tmp);
    fputs("hello world\n",tmp);

    char content[64] = {};
    char *res = fgets(content, sizeof(content), tmp);
    if (res == NULL){
        perror("fgets");
        return -1;
    }
    printf("content %s\n",content);
    fclose(tmp);

    fread(content,1,20,tmp);
    printf("content %s\n",content);
    return 0;
}
