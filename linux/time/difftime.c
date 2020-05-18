//
// Created by zing on 5/18/2020.
//

#include <time.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    time_t start = 0, end = 0;
    time(&start);
    sleep(1);
    time(&end);

    double diff = difftime(end, start);
    printf("%f", diff);
    return 0;
}
