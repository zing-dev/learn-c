//
// Created by zing on 5/25/2020.
//

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>

int writev1() {
    struct iovec iov[3];
    ssize_t nr;
    int fd, i;
    char *buf[] = {"The term buccaneer comes from the word boucan.\n",
                   "A boucan is a wooden frame used for cooking meat.\n",
                   "Buccaneer is the West Indies name for a pirate.\n"};
    fd = open("buccaneer.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    /* fill out three iovec structures */
    for (i = 0; i < 3; i++) {
        iov[i].iov_base = buf[i];
        iov[i].iov_len = strlen(buf[i] + 1);
    }
    /* with a single call, write them all out */
    nr = writev(fd, iov, 3);
    if (nr == -1) {
        perror("writev");
        return 1;
    }
    printf("wrote %zd bytes\n", nr);
    if (close(fd)) {
        perror("close");
        return 1;
    }
    return 0;
}

int writev2(){
    char *str0 = "hello ";
    char *str1 = "world\n";
    struct iovec iov[2];
    ssize_t nwritten;

    iov[0].iov_base = str0;
    iov[0].iov_len = strlen(str0);
    iov[1].iov_base = str1;
    iov[1].iov_len = strlen(str1);

    nwritten = writev(STDOUT_FILENO, iov, 2);
    return nwritten;
}
int main() {
    writev1();
    writev2();
    return 0;
}