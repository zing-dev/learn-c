//
// Created by zhangrongxiang on 2018/2/26 13:56
// File gethostid
//

#include <unistd.h>
#include <stdio.h>
//gethostid - get an identifier for the current host
//The gethostid() function retrieves a 32-bit identifier for the current host.
int main() {
    long id = gethostid();
    printf("%ld\n", id);
    return 0;
}
