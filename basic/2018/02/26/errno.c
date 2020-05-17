//
// Created by zhangrongxiang on 2018/2/26 15:58
// File errno
//

#include<stdio.h>
#include<errno.h>
#include<string.h>

int main() {
    //#define EPERM 1
    //EPERM 1 -> Operation not permitted
    printf("EPERM %d -> %s\n", EPERM, strerror(EPERM));

    //#define ENOENT 2
    //ENOENT 2 -> No such file or directory
    printf("ENOENT %d -> %s\n", ENOENT, strerror(ENOENT));

    //#define ENOFILE ENOENT
    //printf("ENOFILE %d -> %s\n", ENOFILE, strerror(ENOFILE));

    //#define ESRCH 3
    //ESRCH 3 -> No such process
    printf("ESRCH %d -> %s\n", ESRCH, strerror(ESRCH));

    //#define EINTR 4
    // EINTR 4 -> Interrupted system call --> linux
    //EINTR 4 -> Interrupted function call --> mingw
    printf("EINTR %d -> %s\n", EINTR, strerror(EINTR));

    //#define EIO 5
    //EIO 5 -> Input/output error
    printf("EIO %d -> %s\n", EIO, strerror(EIO));

    //#define ENXIO 6
    //EIENXIOO 6 -> No such device or address
    printf("EIENXIOO %d -> %s\n", ENXIO, strerror(ENXIO));

    //#define E2BIG 7
    //E2BIG 7 -> Argument list too long --> linux
    //E2BIG 7 -> Arg list too long --> mingw
    printf("E2BIG %d -> %s\n", E2BIG, strerror(E2BIG));

    //#define ENOEXEC 8
    //ENOEXEC 8 -> Exec format error
    printf("ENOEXEC %d -> %s\n", ENOEXEC, strerror(ENOEXEC));

    //#define EBADF 9
    //EBADF 9 -> Bad file descriptor
    printf("EBADF %d -> %s\n", EBADF, strerror(EBADF));

    //#define ECHILD 10
    //ECHILD 10 -> No child processes
    printf("ECHILD %d -> %s\n", ECHILD, strerror(ECHILD));

    //#define EAGAIN 11
    //EAGAIN 11 -> Resource temporarily unavailable
    printf("EAGAIN %d -> %s\n", EAGAIN, strerror(EAGAIN));

    //#define ENOMEM 12
    //ENOMEM 12 -> Cannot allocate memory --> linux
    //ENOMEM 12 -> Not enough space --> mingw
    printf("ENOMEM %d -> %s\n", ENOMEM, strerror(ENOMEM));

    //#define EACCES 13
    //EACCES 13 -> Permission denied
    printf("EACCES %d -> %s\n", EACCES, strerror(EACCES));

    //#define EFAULT 14
    //EFAULT 14 -> Bad address
    printf("EFAULT %d -> %s\n", EFAULT, strerror(EFAULT));

    //#define EBUSY 16
    //EBUSY 16 -> Device or resource busy
    printf("EBUSY %d -> %s\n", EBUSY, strerror(EBUSY));

    //#define EEXIST 17
    //EEXIST 17 -> File exists
    printf("EEXIST %d -> %s\n", EEXIST, strerror(EEXIST));

    //#define EXDEV 18
    //EXDEV 18 -> Invalid cross-device link
    printf("EXDEV %d -> %s\n", EXDEV, strerror(EXDEV));

    //#define ENODEV 19
    //ENODEV 19 -> No such device
    printf("ENODEV %d -> %s\n", ENODEV, strerror(ENODEV));

    //#define ENOTDIR 20
    //ENOTDIR 20 -> Not a directory
    printf("ENOTDIR %d -> %s\n", ENOTDIR, strerror(ENOTDIR));

    //#define EISDIR 21
    //Is a directory
    printf("EISDIR %d -> %s\n", EISDIR, strerror(EISDIR));

    //#define ENFILE 23
    //ENFILE 23 -> Too many open files in system
    printf("ENFILE %d -> %s\n", ENFILE, strerror(ENFILE));

    //#define EMFILE 24
    //EMFILE 24 -> Too many open files
    printf("EMFILE %d -> %s\n", EMFILE, strerror(EMFILE));

    //#define ENOTTY 25
    //ENOTTY 25 -> Inappropriate ioctl for device
    printf("ENOTTY %d -> %s\n", ENOTTY, strerror(ENOTTY));

    //#define EFBIG 27
    //EFBIG 27 -> File too large
    printf("EFBIG %d -> %s\n", EFBIG, strerror(EFBIG));

    //#define ENOSPC 28
    //ENOSPC 28 -> No space left on device
    printf("ENOSPC %d -> %s\n", ENOSPC, strerror(ENOSPC));

    //#define ESPIPE 29
    //ESPIPE 29 -> Illegal seek
    printf("ESPIPE %d -> %s\n", ESPIPE, strerror(ESPIPE));

    //#define EROFS 30
    //EROFS 30 -> Read-only file system
    printf("EROFS %d -> %s\n", EROFS, strerror(EROFS));

    //#define EMLINK 31
    //EMLINK 31 -> Too many links
    printf("EMLINK %d -> %s\n", EMLINK, strerror(EMLINK));

    //#define EPIPE 32
    //EPIPE 32 -> Broken pipe
    printf("EPIPE %d -> %s\n", EPIPE, strerror(EPIPE));

    //#define EDOM 33
    //EDOM 33 -> Numerical argument out of domain
    //EDOM 33 -> Domain error
    printf("EDOM %d -> %s\n", EDOM, strerror(EDOM));

    //EDEADLK 35 -> Resource deadlock avoided --> linux
    //EDEADLK 36 -> Resource deadlock avoided --> mingw
    printf("EDEADLK %d -> %s\n", EDEADLK, strerror(EDEADLK));

    //ENAMETOOLONG 36 -> File name too long --> linux
    //ENAMETOOLONG 38 -> Filename too long --> mingw
    printf("ENAMETOOLONG %d -> %s\n", ENAMETOOLONG, strerror(ENAMETOOLONG));

    //ENOLCK 37 -> No locks available --> linux
    //ENOLCK 39 -> No locks available --> mingw
    printf("ENOLCK %d -> %s\n", ENOLCK, strerror(ENOLCK));

    //ENOSYS 38 -> Function not implemented -->linux
    //ENOSYS 40 -> Function not implemented --> mingw
    printf("ENOSYS %d -> %s\n", ENOSYS, strerror(ENOSYS));

    //ENOTEMPTY 39 -> Directory not empty --> linux
    //ENOTEMPTY 41 -> Directory not empty --> mingw
    printf("ENOTEMPTY %d -> %s\n", ENOTEMPTY, strerror(ENOTEMPTY));

    int i = 0;
    for (; i < 133; i++) {
        printf("%3d -> %s\n", i + 1, strerror(i + 1));
    }
    return 0;
}