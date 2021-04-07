//
// Created by zing on 2018/2/24 9:21
// File getcwd
//

#include <unistd.h>
#include <stdio.h>
#include <string.h>

/* Get the pathname of the current working directory,
   and put it in SIZE bytes of BUF.  Returns NULL if the
   directory couldn't be determined or SIZE was too small.
   If successful, returns BUF.  In GNU, if BUF is NULL,
   an array is allocated with `malloc'; the array is SIZE
   bytes long, unless SIZE == 0, in which case it is as
   big as necessary.  */
int main() {
    char buf[128];
    char *rs = getcwd(buf, sizeof(buf));
    printf("rs: %s\n", rs);//   /mnt/c/Users/zing/workspace/c/learn-c/cmake-build-debug/linux/unistd
    printf("buf: %s\n", buf);//  /mnt/c/Users/zing/workspace/c/learn-c/cmake-build-debug/linux/unistd
    printf("%d\n", buf == rs);//1
    printf("%lu\n",strlen(rs));
    return 0;
}
