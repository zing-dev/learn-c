//
// Created by zing on 6/1/2020.
//

#include <stdio.h>
#include <string.h>

/* Compare N characters of S1 and S2.  */
int main(int argc, char *argv[]) {
    printf("%d\n", strncmp("123", "234", 2)); //-1
    printf("%d\n", strncmp("123", "987", 2)); //-8
    printf("%d\n", strncmp("123", "087", 2)); //1
    printf("%d\n", strncmp("123", "187", 2)); //-6
    return 0;
}
