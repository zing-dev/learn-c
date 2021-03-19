//
// Created by zing on 2021/3/17.
//
#include <stdio.h>
#include <unistd.h>
#include <pty.h>
#include <utmp.h>
#include <errno.h>

#define SLAVE_DEV_NAME_MAX_LEN    128
#define PTY_BUFF_MAX_LEN        1024

int main(int argc, char *argv[]) {
    int mpty = 0, spty = 0;
    int rv = 0, n = 0;
    char spty_name[SLAVE_DEV_NAME_MAX_LEN] = {0};
    char buf[PTY_BUFF_MAX_LEN] = {0};

    fd_set rfds;

    rv = openpty(&mpty, &spty, spty_name, NULL, NULL);
    if (-1 == rv) {
        perror("Failed to get a pty");
        return -1;
    }

    printf("Get a pty pair, FD -- master[%d], slave[%d]\n", mpty, spty);
    printf("Slave name is %s\n", spty_name);

    FD_ZERO(&rfds);
    FD_SET(mpty, &rfds);

    while (1) {
        rv = select(mpty + 1, &rfds, &rfds, NULL, NULL);
        if (rv < 0) {
            perror("Failed to select");
            return -1;
        }

        if (FD_ISSET(mpty, &rfds)) {
            n = read(mpty, buf, PTY_BUFF_MAX_LEN);
            if (n > 0) {
                //    memset(buf+n, 0, PTY_BUFF_MAX_LEN-n);
                printf("recv [%d] bytes:[%s]\n", n, buf);
                //write(mpty, buf, n);
            } else if (n == 0) {
                printf("Slave closed\n");
                break;
            } else {
                if (errno == EINTR) {
                    continue;
                }
                perror("Failed to read the master\n");
                return -1;
            }
        }
    }

    close(mpty);
    close(spty);
    return 0;
}
