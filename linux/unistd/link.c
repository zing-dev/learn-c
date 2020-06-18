//
// Created by zing on 6/18/2020.
//

#include <unistd.h>
#include <stdio.h>
#include <errno.h>

/* Make a link to FROM named TO.  */
int main(int argc, char *argv[]) {
    int i = link("vfork", "vfork-link");
    if (i == -1){
        perror("link");
        return errno;
    }
    printf("ok\n");
    return 0;
}
