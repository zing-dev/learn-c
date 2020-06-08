//
// Created by zing on 2018/2/24 9:32
// File chroot
//

#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main() {
    const char root[64] = "../";
    char path[64];
    if (chroot(root) == 0) {
        printf("%s\n", root); // ../
        getcwd(path, sizeof(path));
        printf("%s\n", path);// /unistd
    } else {
        if (errno == EACCES) {
            printf("EACCES Search permission is denied on a component of the path prefix.\n");
        }
        if (errno == EFAULT) {
            printf("EFAULT path points outside your accessible address space.\n");
        }
        if (errno == EPERM) {
            printf("EPERM  The caller has insufficient privilege.\n");
        }
        printf("error %d\n", errno);
        perror("chroot error");
    }
    return 0;
}
