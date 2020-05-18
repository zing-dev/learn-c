//
// Created by zing on 5/18/2020.
//

#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {

    time_t rawtime;
    time(&rawtime);
    struct tm *info = localtime(&rawtime);
    printf("%s", asctime(info));
    return 0;
}
