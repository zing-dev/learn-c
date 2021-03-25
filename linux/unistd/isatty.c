//
// Created by zing on 6/8/2020.
//

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/* Return 1 if FD is a valid descriptor associated with a terminal, zero if not.  */
int main(){
    printf("%d\n",isatty(open("/dev/tty",O_RDONLY)));
    return 0;
}