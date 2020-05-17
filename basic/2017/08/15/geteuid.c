#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

void main() {
    printf("geteuid is %d \n", geteuid());
}
