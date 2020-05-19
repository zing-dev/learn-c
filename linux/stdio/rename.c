//
// Created by zing on 5/19/2020.
//


#include <stdio.h>
#include "my_stdio.h"

int main(int argc, char *argv[]) {
    const char *filename = "test.txt";
    file(filename);
    int i = rename(filename, "a.txt");
    if (i == -1){
        perror("rename");
    } else{
        printf("rename success\n");
    }
    return 0;
}
