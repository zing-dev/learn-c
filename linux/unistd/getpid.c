//
// Created by zing on 2021/3/25.
//

#include <unistd.h>
#include <stdio.h>

/* Get the process ID of the calling process.  */
int main() {
    printf("%d\n", getpid());
}