//
// Created by zhangrongxiang on 2018/3/5 15:15
// File gethostbyname
//

#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    char host[16] = {0};
    struct hostent *hostent = NULL;
    int rs = gethostname(host, sizeof(host));
    if (rs == 0) {
        hostent = gethostbyname(host);
        if (hostent) {
            printf("%s\n", host);
            printf("%s\n", hostent->h_name);
        }
    } else if (rs == -1) {
//        printf("%s\n",strerror(errno));
        printf("gethostname error\n");
    } else {
        printf("other error\n");
    }
    return 0;
}