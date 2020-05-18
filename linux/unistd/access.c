//
// Created by zhangrongxiang on 2018/2/23 9:17
// File access
//

#include <unistd.h>
#include <stdio.h>
#include <errno.h>

//#define	R_OK	4		/* Test for read permission.  */
//#define	W_OK	2		/* Test for write permission.  */
//#define	X_OK	1		/* Test for execute permission.  */
//#define	F_OK	0		/* Test for existence.  */

int main(int argc, char *argv[]) {
    char *path;
    if (argc == 2) {
        path = argv[1];
    } else {
        path = ".";
    }
    int r = access(path, R_OK);
    if (r == 0) {
        printf("access R %s ok \n", path);
    } else {
        printf("access R %s error \n", path);
    }
    r = access(path, W_OK);
    if (r == 0) {
        printf("access W %s ok \n", path);
    } else {
        printf("access W %s error \n", path);
        if (errno == EACCES) {
            printf("Permission bits of the file mode do not permit the requested access, "\
                   "or search permission is denied on a component of the path prefix.\n");
        }
    }
    r = access(path, X_OK);
    if (r == 0) {
        printf("access X %s ok \n", path);
    } else {
        printf("access X %s error \n", path);
        printf("access W %s error \n", path);
        if (errno == EACCES) {
            printf("Permission bits of the file mode do not permit the requested access, "\
                   "or search permission is denied on a component of the path prefix.\n");
        }
    }
    if (access(path, F_OK) == 0) {
        printf("access F %s ok \n", path);
    } else {
        printf("access F %s error \n", path);
    }
    return 0;
}