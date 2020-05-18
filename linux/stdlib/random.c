//
// Created by zing on 5/18/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    time_t time1;
    time(&time1);
    srandom(time1);
    for (int i = 0; i < 10; i++) {
        printf("%ld\n", random());
    }
    return 0;
}
