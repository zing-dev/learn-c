//
// Created by zing on 5/19/2020.
//

#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = creat("a.txt", 00700);
    if (fd == -1) {
        perror("creat");
    }
    return 0;
}