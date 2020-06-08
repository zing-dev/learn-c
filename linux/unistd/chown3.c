//
// Created by zing on 2018/2/22 17:08
// File chown3
//

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *src, *desc;
    struct stat sb;

    if (argc == 3) {
        src = argv[1];
        desc = argv[2];
        if (stat(src, &sb) == -1) {
            perror("stat");
            exit(EXIT_FAILURE);
        }
        int uid = sb.st_uid;
        int gid = sb.st_gid;
        int r = chown(desc, uid, gid);
        if (r == 0) {
            printf("chown %s from %s success!\n", desc, src);
        } else {
            printf("chown %s from %s error!\n", desc, src);
        }

    } else {
        fprintf(stderr,"argv error!\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}