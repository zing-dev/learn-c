//
// Created by zing on 6/8/2020.
//

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

/* Return the pathname of the terminal FD is open on, or NULL on errors.
   The returned storage is good only until the next call to this function.  */

int main() {
    int fd = open("ttyname", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return errno;
    }
    char *name = ttyname(fd);
    if (name != NULL) {
        printf("ttyname %s\n", name);
    } else {
        perror("ttyname");
    }

    name = ttyname(open("/dev/tty",O_RDONLY));
    if (name != NULL) {
        printf("ttyname %s\n", name);
    } else {
        perror("ttyname");
    }

    return 0;
}