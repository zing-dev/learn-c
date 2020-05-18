//
// Created by zing on 5/18/2020.
//

#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    time_t now;
    time_t time1 = time(&now);
    printf("%ld\n",now);
    printf("%ld\n",time1);
    return 0;
}
