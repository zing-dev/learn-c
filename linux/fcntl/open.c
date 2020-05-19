//
// Created by zing on 5/19/2020.
//

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

/* Open FILE and return a new file descriptor for it, or -1 on error.
   OFLAG determines the type of access used.  If O_CREAT or O_TMPFILE is set
   in OFLAG, the third argument is taken as a `mode_t', the mode of the
   created file.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
const char *filename = "test.txt";

void read_only() {
    int fd = open("Makefile", O_RDONLY);
    if (fd == -1) {
        perror("open");
    }
}

void my_create() {
    int fd = open("test.txt", O_CREAT);
    if (fd == -1) {
        perror("create");
    }
}

void my_write() {
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("open by write");
        if (errno == EACCES) {
            if (chmod(filename, 0777) == -1) {
                perror("chmod");
                return;
            }
        } else {
            perror("open");
        }
    }
    char *content = "hello world\n";
    int size = write(fd, content, strlen(content) + 1);
    if (size == -1) {
        perror("write");
        return;
    }
    printf("write %d\n", size);

}

void my_read() {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open by read");
        return;
    }
    char content[20] = {};
    printf("before read %s\n", content);
    ssize_t size = read(fd, content, sizeof(content));
    if (size == -1) {
        perror("read");
        return;
    }
    printf("after read %zd %s\n", size, content);
}

int main() {
    read_only();
    my_create();
    my_write();
    my_read();
    return 0;
}
