//
// Created by zing on 6/18/2020.
//

#include <unistd.h>
#include <stdio.h>

/* Make a symbolic link to FROM named TO.  */
int main(int argc, char *argv[]) {
    if (symlink("Makefile", "Makefile2") == 0) {
        printf("ok");
    } else {
        perror("symlink");
    }
    return 0;
}
