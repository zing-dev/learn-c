//
// Created by zing on 6/4/2020.
//

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

/* Write LENGTH bytes of randomness starting at BUFFER.
 * Return 0 on success or -1 on error.  */
int main(){
    char buf[16];
    memset(buf,0,sizeof(buf));
    int i = getentropy(buf, sizeof(buf) -1);
    if (i == -1){
        perror("getentropy");
        return errno;
    }
    printf("%s\n",buf);
    printf("%ld\n",strlen(buf));
    for (int j = 0; j < sizeof(buf); ++j) {
        printf("%d ",buf[j]);
    }
    printf("\n");
    return 0;
}