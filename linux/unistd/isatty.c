//
// Created by zing on 6/8/2020.
//

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
    printf("%d\n",isatty(open("/dev/tty",O_RDONLY)));
    return 0;
}