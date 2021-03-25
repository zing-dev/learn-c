//
// Created by zing on 2021/3/25.
//

#include <unistd.h>
#include <stdio.h>

int main() {
    __pid_t pgrp = getpgrp();
    printf("pgrp %d\n", pgrp);
}