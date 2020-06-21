//
// Created by zing on 6/21/2020.
//

#include <csapp.h>
int main(int argc, char *argv[]) {
    unix_error("unix_error");
    posix_error(1,"posix_error");
    dns_error("dns_error");
    app_error("app_error");
    return 0;
}
