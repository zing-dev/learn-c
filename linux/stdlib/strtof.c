//
// Created by zing on 5/18/2020.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *str = "12.34.ABC";
    char *end = NULL;
    float f = strtof(str, &end);
    printf("%f\n", f); //12.340000
    printf("%s\n", end); //.ABC
    printf("%s\n", str);//12.34.ABC
    printf("%ld\n", end - str);//5
    printf("%ld\n", str - end);// -5
    return 0;
}
