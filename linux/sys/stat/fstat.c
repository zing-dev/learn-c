//
// Created by zing on 6/4/2020.
//

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    int fd = creat("test.txt", O_CREAT | O_RDONLY);
    if (fd == -1) {
        perror("creat");
        if (errno == EACCES) {
            printf("EACCES\n");
            int ret = chmod("test.txt", S_IRUSR);
            if (ret == -1) {
                perror("chmod");
                return errno;
            }
            fd = open("test.txt", O_RDONLY);
            if (fd == -1) {
                perror("open");
                return errno;
            }
        }
    }
    struct stat st;
    int ret = fstat(fd, &st);
    if (ret == -1) {
        perror("fstat");
        return errno;
    }
    printf("S_ISREG %d\n", S_ISREG(st.st_mode));

    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return errno;
    }
    int dfd = dirfd(dir);
    if (dfd == -1) {
        perror("dirfd");
        return errno;
    }

    struct stat st2;
    ret = fstat(dfd, &st2);
    if (ret == -1) {
        perror("fstat");
        return errno;
    }
    printf("S_ISREG %d\n", S_ISREG(st2.st_mode));
    printf("S_ISDIR %d\n", S_ISDIR(st2.st_mode));
    return 0;
}
