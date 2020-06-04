//
// Created by zing on 6/4/2020.
//

#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>

/* Get file attributes for FILE and put them in BUF.  */
int main() {
    struct stat st;
    int i = stat("a.txt", &st);
    if (i == -1){
        perror("stat");
        if (errno == ENOENT){
            if (creat("a.txt",O_CREAT) == -1){
                perror("create");
                return errno;
            }
            stat("a.txt",&st);
        } else{
            return errno;
        }
    }

    printf("%x\n",st.st_mode);
    return 0;
}