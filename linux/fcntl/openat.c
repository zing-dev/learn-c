//
// Created by zing on 5/19/2020.
//

#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>

const char *filename = "test.txt";

/**
The openat() system call operates in exactly the same way as open(),  except  for  the  differences  described
        here.

If the pathname given in pathname is relative, then it is interpreted relative to the directory referred to by
the file descriptor dirfd (rather than relative to the current working directory of the calling process, as is
                           done by open() for a relative pathname).

If  pathname is relative and dirfd is the special value AT_FDCWD, then pathname is interpreted relative to the
        current working directory of the calling process (like open()).

If pathname is absolute, then dirfd is ignored.
 */
void my_openat() {
    int fd = openat(AT_FDCWD, filename, O_RDONLY); // like open
    if (fd == -1) {
        perror("openat");
        return;
    }
}

void my_openat2() {
    DIR *dir = opendir(".");
    int dfd = dirfd(dir);
    int fd = openat(dfd, filename, O_RDONLY); // like open
    if (fd == -1) {
        perror("my_openat2");
        return;
    }
}

void my_openat3() {
    int fd = openat(AT_FDCWD, "/home/zing/workspace/c/learn-c/cmake-build-debug/linux/fcntl", O_RDONLY);
    if (fd == -1) {
        perror("my_openat3");
        return;
    }
}

int main() {
    my_openat();
    my_openat2();
    my_openat3();
    return 0;
}

