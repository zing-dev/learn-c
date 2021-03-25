//
// Created by zhangrongxiang on 2018/2/26 13:46
// File getdtablesize
//

#include <unistd.h>
#include <stdio.h>
//getdtablesize - get the file descriptor table size (LEGACY)

/* Return the maximum number of file descriptors
   the current process could possibly have.  */
int main() {
    int size = getdtablesize();
    printf("%d\n", size);
    return 0;
}
