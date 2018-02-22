//
// Created by zhangrongxiang on 2018/2/22 17:05
// File stat
//

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//struct stat {
//    dev_t     st_dev;         /* ID of device containing file */
//    ino_t     st_ino;         /* inode number */
//    mode_t    st_mode;        /* protection */
//    nlink_t   st_nlink;       /* number of hard links */
//    uid_t     st_uid;         /* user ID of owner */
//    gid_t     st_gid;         /* group ID of owner */
//    dev_t     st_rdev;        /* device ID (if special file) */
//    off_t     st_size;        /* total size, in bytes */
//    blksize_t st_blksize;     /* blocksize for filesystem I/O */
//    blkcnt_t  st_blocks;      /* number of 512B blocks allocated */
//
//    /* Since Linux 2.6, the kernel supports nanosecond
//       precision for the following timestamp fields.
//       For the details before Linux 2.6, see NOTES. */
//
//    struct timespec st_atim;  /* time of last access */
//    struct timespec st_mtim;  /* time of last modification */
//    struct timespec st_ctim;  /* time of last status change */
//
//#define st_atime st_atim.tv_sec      /* Backward compatibility */
//#define st_mtime st_mtim.tv_sec
//#define st_ctime st_ctim.tv_sec
//};

int main(int argc, char *argv[]) {
    struct stat sb;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    printf("File type:                ");

    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:
            printf("block device\n");
            break;
        case S_IFCHR:
            printf("character device\n");
            break;
        case S_IFDIR:
            printf("directory\n");
            break;
        case S_IFIFO:
            printf("FIFO/pipe\n");
            break;
        case S_IFLNK:
            printf("symlink\n");
            break;
        case S_IFREG:
            printf("regular file\n");
            break;
        case S_IFSOCK:
            printf("socket\n");
            break;
        default:
            printf("unknown?\n");
            break;
    }

    printf("I-node number:            %ld\n", (long) sb.st_ino);

    printf("Mode:                     %lo (octal)\n",
           (unsigned long) sb.st_mode);

    printf("Link count:               %ld\n", (long) sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",
           (long) sb.st_uid, (long) sb.st_gid);

    printf("Preferred I/O block size: %ld bytes\n",
           (long) sb.st_blksize);
    printf("File size:                %lld bytes\n",
           (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n",
           (long long) sb.st_blocks);

    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));

    exit(EXIT_SUCCESS);
}
/**/
