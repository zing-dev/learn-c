#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BLOCKSIZE 256

int read_conf();


int main(void) {
    printf("Hello World....\n");

    read_conf();

    return 1;
}


int read_conf() {
    FILE *fd;
    char *buf, *temp;
    fd = fopen("test.conf", "r");
    if (fd == NULL) {
        perror("fopen error ...");
        exit(-1);
    }
    while ((buf = (char *) malloc(BLOCKSIZE)) == NULL);
    memset(buf, 0, BLOCKSIZE);
    while (fgets(buf, BLOCKSIZE, fd) != NULL) {
        printf("%s", buf);
    }

    return 1;

}
