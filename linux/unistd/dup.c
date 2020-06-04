//
// Created by zing on 6/4/2020.
//

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

int main(){

    int fd = open("b.txt",O_CREAT|O_RDWR);
    if (fd == -1){
        if (errno == EACCES){
            if (chmod("b.txt",S_IRWXU) == -1){
                perror("chmod");
                return errno;
            }
        }
        perror("open");
        return errno;
    }
    int newfd = dup(fd);
    if (newfd == -1){
        perror("dup");
        return errno;
    }
    char *str = "hello world";
    write(newfd,str,strlen(str));
    return 0;
}