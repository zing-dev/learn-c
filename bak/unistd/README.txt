The Single UNIX ® Specification, Version 2
Copyright © 1997 The Open Group
 NAME
unistd.h - standard symbolic constants and types
 SYNOPSIS


#include <unistd.h>

 DESCRIPTION
The <unistd.h> header defines miscellaneous symbolic constants and types, and declares miscellaneous functions. The contents of this header are shown below.
 Version Test Macros
The following symbolic constants are defined:
_POSIX_VERSION
Integer value indicating version of the ISO POSIX-1 standard (C language binding).
_POSIX2_VERSION
Integer value indicating version of the ISO POSIX-2 standard (Commands).
_POSIX2_C_VERSION
Integer value indicating version of the ISO POSIX-2 standard (C language binding).
_XOPEN_VERSION
Integer value indicating version of the X/Open Portability Guide to which the implementation conforms.
_POSIX_VERSION is defined in the ISO POSIX-1 standard. It changes with each new version of the ISO POSIX-1 standard.

_POSIX2_VERSION is defined to have the value of the ISO POSIX-2 standard's POSIX2_VERSION limit. It changes with each new version of the ISO POSIX-2 standard.

_POSIX2_C_VERSION is defined in the ISO POSIX-2 standard. It changes with each new version of the ISO POSIX-2 standard. When the C language binding option of the ISO POSIX-2 standard and therefore the X/Open POSIX2 C-language Binding Feature Group is not supported, _POSIX2_C_VERSION will be set to -1.

_XOPEN_VERSION is defined as an integer value equal to 500.

_XOPEN_XCU_VERSION is defined as an integer value indicating the version of the XCU specification to which the implementation conforms. If the value is -1, no commands and utilities are provided on the implementation. If the value is greater than or equal to 4, the functionality associated with the following symbols is also supported (see Mandatory Symbolic Constants and Constants for Options and Feature Groups ):

_POSIX2_C_BIND
_POSIX2_C_VERSION
_POSIX2_CHAR_TERM
_POSIX2_LOCALEDEF
_POSIX2_UPE
_POSIX2_VERSION
If this constant is not defined use the sysconf() function to determine which features are supported.

Each of the following symbolic constants is defined only if the implementation supports the indicated issue of the X/Open Portability Guide:

_XOPEN_XPG2
X/Open Portability Guide, Volume 2, January 1987, XVS System Calls and Libraries (ISBN: 0-444-70175-3).
_XOPEN_XPG3
X/Open Specification, February 1992, System Interfaces and Headers, Issue 3 (ISBN: 1-872630-37-5, C212); this specification was formerly X/Open Portability Guide, Issue 3, Volume 2, January 1989, XSI System Interface and Headers (ISBN: 0-13-685843-0, XO/XPG/89/003).
_XOPEN_XPG4
X/Open CAE Specification, July 1992, System Interfaces and Headers, Issue 4 (ISBN: 1-872630-47-2, C202).
_XOPEN_UNIX
X/Open CAE Specification, January 1997, System Interfaces and Headers, Issue 5 (ISBN: 1-85912-181-0, C606).
 Mandatory Symbolic Constants
Although all implementations conforming to this specification support all of the FIPS features described below, there may be system-dependent or file-system-dependent configuration procedures that can remove or modify any or all of these features. Such configurations should not be made if strict FIPS compliance is required.
The following symbolic constants are either undefined or defined with a value other than -1. If a constant is undefined, an application should use the sysconf(), pathconf() or fpathconf() functions to determine which features are present on the system at that time or for the particular pathname in question.

_POSIX_CHOWN_RESTRICTED
The use of chown() is restricted to a process with appropriate privileges, and to changing the group ID of a file only to the effective group ID of the process or to one of its supplementary group IDs.
_POSIX_NO_TRUNC
Pathname components longer than {NAME_MAX} generate an error.
_POSIX_VDISABLE
Terminal special characters defined in <termios.h> can be disabled using this character value.
_POSIX_SAVED_IDS
Each process has a saved set-user-ID and a saved set-group-ID.
_POSIX_JOB_CONTROL
Implementation supports job control.
_POSIX_CHOWN_RESTRICTED, _POSIX_NO_TRUNC and _POSIX_VDISABLE will have values other than -1.
The following symbolic constants are always defined to unspecified values to indicate that this functionality from the POSIX Threads Extension is always present on XSI-conformant systems:

_POSIX_THREADS
The implementation supports the threads option.
_POSIX_THREAD_ATTR_STACKADDR
The implementation supports the thread stack address attribute option.
_POSIX_THREAD_ATTR_STACKSIZE
The implementation supports the thread stack size attribute option.
_POSIX_THREAD_PROCESS_SHARED
The implementation supports the process-shared synchronisation option.
_POSIX_THREAD_SAFE_FUNCTIONS
The implementation supports the thread-safe functions option.
 Constants for Options and Feature Groups
The following symbolic constants are defined to have the value -1 if the implementation will never provide the feature, and to have a value other than -1 if the implementation always provides the feature. If these are undefined, the sysconf() function can be used to determine whether the feature is provided for a particular invocation of the application.

_POSIX2_C_BIND
Implementation supports the C Language Binding option. This will always have a value other than -1.
_POSIX2_C_DEV
Implementation supports the C Language Development Utilities option.
_POSIX2_CHAR_TERM
Implementation supports at least one terminal type.
_POSIX2_FORT_DEV
Implementation supports the FORTRAN Development Utilities option.
_POSIX2_FORT_RUN
Implementation supports the FORTRAN Run-time Utilities option.
_POSIX2_LOCALEDEF
Implementation supports the creation of locales by the localedef utility.
_POSIX2_SW_DEV
Implementation supports the Software Development Utilities option.
_POSIX2_UPE
The implementation supports the User Portability Utilities option.
_XOPEN_CRYPT
The implementation supports the X/Open Encryption Feature Group.
_XOPEN_ENH_I18N
The implementation supports the Issue 4, Version 2 Enhanced Internationalisation Feature Group. This is always set to a value other than -1.
_XOPEN_LEGACY
The implementation supports the Legacy Feature Group.
_XOPEN_REALTIME
The implementation supports the X/Open Realtime Feature Group.
_XOPEN_REALTIME_THREADS
The implementation supports the X/Open Realtime Threads Feature Group.
_XOPEN_SHM
The implementation supports the Issue 4, Version 2 Shared Memory Feature Group. This is always set to a value other than -1.
_XBS5_ILP32_OFF32
Implementation provides a C-language compilation environment with 32-bit int, long, pointer and off_t types.
_XBS5_ILP32_OFFBIG
Implementation provides a C-language compilation environment with 32-bit int, long and pointer types and an off_t type using at least 64 bits.
_XBS5_LP64_OFF64
Implementation provides a C-language compilation environment with 32-bit int and 64-bit long, pointer and off_t types.
_XBS5_LPBIG_OFFBIG
Implementation provides a C-language compilation environment with an int type using at least 32 bits and long, pointer and off_t types using at least 64 bits.
If _XOPEN_REALTIME is defined to have a value other than -1, then the following symbolic constants will be defined to an unspecified value to indicate that the features are supported.

_POSIX_ASYNCHRONOUS_IO
Implementation supports the Asynchronous Input and Output option.
_POSIX_MEMLOCK
Implementation supports the Process Memory Locking option.
_POSIX_MEMLOCK_RANGE
Implementation supports the Range Memory Locking option.
_POSIX_MESSAGE_PASSING
Implementation supports the Message Passing option.
_POSIX_PRIORITY_SCHEDULING
Implementation supports the Process Scheduling option.
_POSIX_REALTIME_SIGNALS
Implementation supports the Realtime Signals Extension option.
_POSIX_SEMAPHORES
Implementation supports the Semaphores option.
_POSIX_SHARED_MEMORY_OBJECTS
Implementation supports the Shared Memory Objects option.
_POSIX_SYNCHRONIZED_IO
Implementation supports the Synchronised Input and Output option.
_POSIX_TIMERS
Implementation supports the Timers option.
The following symbolic constants are always defined to unspecified values to indicate that the functionality is always present on XSI-conformant systems.

_POSIX_FSYNC
Implementation supports the File Synchronisation option.
_POSIX_MAPPED_FILES
Implementation supports the Memory Mapped Files option.
_POSIX_MEMORY_PROTECTION
Implementation supports the Memory Protection option.
The following symbolic constant will be defined if the option is supported; otherwise, it will be undefined:

_POSIX_PRIORITIZED_IO
Implementation supports the Prioritized Input and Output option.
If _XOPEN_REALTIME_THREADS is defined to have a value other than -1, then the following symbolic constants will be defined to an unspecified value to indicate that the features are supported:

_POSIX_THREAD_PRIORITY_SCHEDULING
The implementation supports the thread execution scheduling option.
_POSIX_THREAD_PRIO_INHERIT
The implementation supports the priority inheritance option.
_POSIX_THREAD_PRIO_PROTECT
The implementation supports the priority protection option.
 Execution-time Symbolic Constants
If any of the following constants are not defined in the header <unistd.h>, the value varies depending on the file to which it is applied.

If any of the following constants are defined to have value -1 in the header <unistd.h>, the implementation will not provide the option on any file; if any are defined to have a value other than -1 in the header <unistd.h>, the implementation will provide the option on all applicable files.

All of the following constants, whether defined in <unistd.h> or not, may be queried with respect to a specific file using the pathconf() or fpathconf() functions.

_POSIX_ASYNC_IO
Asynchronous input or output operations may be performed for the associated file.
_POSIX_PRIO_IO
Prioritized input or output operations may be performed for the associated file.
_POSIX_SYNC_IO
Synchronised input or output operations may be performed for the associated file.
 Constants for Functions
The following symbolic constant is defined:
NULL
Null pointer
The following symbolic constants are defined for the access() function:

R_OK
Test for read permission.
W_OK
Test for write permission.
X_OK
Test for execute (search) permission.
F_OK
Test for existence of file.
The constants F_OK, R_OK, W_OK and X_OK and the expressions R_OK|W_OK, R_OK|X_OK and R_OK|W_OK|X_OK all have distinct values.

The following symbolic constants are defined for the confstr() function:

_CS_PATH
If the ISO POSIX-2 standard is supported, this is the value for the environment variable that finds all standard utilities. Otherwise the meaning of this value is unspecified.
_CS_XBS5_ILP32_OFF32_CFLAGS
If sysconf(_SC_XBS5_ILP32_OFF32) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of initial options to be given to the cc and c89 utilities to build an application using a programming model with 32-bit int, long, pointer, and off_t types.
_CS_XBS5_ILP32_OFF32_LDFLAGS
If sysconf(_SC_XBS5_ILP32_OFF32) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of final options to be given to the cc and c89 utilities to build an application using a programming model with 32-bit int, long, pointer, and off_t types.
_CS_XBS5_ILP32_OFF32_LIBS
If sysconf(_SC_XBS5_ILP32_OFF32) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of libraries to be given to the cc and c89 utilities to build an application using a programming model with 32-bit int, long, pointer, and off_t types.
_CS_XBS5_ILP32_OFF32_LINTFLAGS
If sysconf(_SC_XBS5_ILP32_OFF32) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of options to be given to the lint utility to check application source using a programming model with 32-bit int, long, pointer, and off_t types.
_CS_XBS5_ILP32_OFFBIG_CFLAGS
If sysconf(_SC_XBS5_ILP32_OFFBIG) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of initial options to be given to the cc and c89 utilities to build an application using a programming model with 32-bit int, long, and pointer types, and an off_t type using at least 64 bits.
_CS_XBS5_ILP32_OFFBIG_LDFLAGS
If sysconf(_SC_XBS5_ILP32_OFFBIG) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of final options to be given to the cc and c89 utilities to build an application using a programming model with 32-bit int, long, and pointer types, and an off_t type using at least 64 bits.
_CS_XBS5_ILP32_OFFBIG_LIBS
If sysconf(_SC_XBS5_ILP32_OFFBIG) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of libraries to be given to the cc and c89 utilities to build an application using a programming model with 32-bit int, long, and pointer types, and an off_t type using at least 64 bits.
_CS_XBS5_ILP32_OFFBIG_LINTFLAGS
If sysconf(_SC_XBS5_ILP32_OFFBIG) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of options to be given to the lint utility to check an application using a programming model with 32-bit int, long, and pointer types, and an off_t type using at least 64 bits.
_CS_XBS5_LP64_OFF64_CFLAGS
If sysconf(_SC_XBS5_LP64_OFF64) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of initial options to be given to the cc and c89 utilities to build an application using a programming model with 64-bit int, long, pointer, and off_t types.
_CS_XBS5_LP64_OFF64_LDFLAGS
If sysconf(_SC_XBS5_LP64_OFF64) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of final options to be given to the cc and c89 utilities to build an application using a programming model with 64-bit int, long, pointer, and off_t types.
_CS_XBS5_LP64_OFF64_LIBS
If sysconf(_SC_XBS5_LP64_OFF64) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of libraries to be given to the cc and c89 utilities to build an application using a programming model with 64-bit int, long, pointer, and off_t types.
_CS_XBS5_LP64_OFF64_LINTFLAGS
If sysconf(_SC_XBS5_LP64_OFF64) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of options to be given to the lint utility to check application source using a programming model with 64-bit int, long, pointer, and off_t types.
_CS_XBS5_LPBIG_OFFBIG_CFLAGS
If sysconf(_SC_XBS5_LPBIG_OFFBIG) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of initial options to be given to the cc and c89 utilities to build an application using a programming model with an int type using at least 32 bits and long, pointer, and off_t types using at least 64 bits.
_CS_XBS5_LPBIG_OFFBIG_LDFLAGS
If sysconf(_SC_XBS5_LPBIG_OFFBIG) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of final options to be given to the cc and c89 utilities to build an application using a programming model with an int type using at least 32 bits and long, pointer, and off_t types using at least 64 bits.
_CS_XBS5_LPBIG_OFFBIG_LIBS
If sysconf(_SC_XBS5_LPBIG_OFFBIG) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of libraries to be given to the cc and c89 utilities to build an application using a programming model with an int type using at least 32 bits and long, pointer, and off_t types using at least 64 bits.
_CS_XBS5_LPBIG_OFFBIG_LINTFLAGS
If sysconf(_SC_XBS5_LPBIG_OFFBIG) returns -1, the meaning of this value is unspecified. Otherwise, this value is the set of options to be given to the lint utility to check application source using a programming model with an int type using at least 32 bits and long, pointer, and off_t types using at least 64 bits.
The following symbolic constants are defined for the lseek() and fcntl() functions (they have distinct values):

SEEK_SET
Set file offset to offset.
SEEK_CUR
Set file offset to current plus offset.
SEEK_END
Set file offset to EOF plus offset.
The following symbolic constants are defined for sysconf():

_SC_2_C_BIND
_SC_2_C_DEV
_SC_2_C_VERSION
_SC_2_FORT_DEV
_SC_2_FORT_RUN
_SC_2_LOCALEDEF
_SC_2_SW_DEV
_SC_2_UPE
_SC_2_VERSION
_SC_ARG_MAX
_SC_AIO_LISTIO_MAX
_SC_AIO_MAX
_SC_AIO_PRIO_DELTA_MAX
_SC_ASYNCHRONOUS_IO
_SC_ATEXIT_MAX
_SC_BC_BASE_MAX
_SC_BC_DIM_MAX
_SC_BC_SCALE_MAX
_SC_BC_STRING_MAX
_SC_CHILD_MAX
_SC_CLK_TCK
_SC_COLL_WEIGHTS_MAX
_SC_DELAYTIMER_MAX
_SC_EXPR_NEST_MAX
_SC_FSYNC
_SC_GETGR_R_SIZE_MAX
_SC_GETPW_R_SIZE_MAX
_SC_IOV_MAX
_SC_JOB_CONTROL
_SC_LINE_MAX
_SC_LOGIN_NAME_MAX
_SC_MAPPED_FILES
_SC_MEMLOCK
_SC_MEMLOCK_RANGE
_SC_MEMORY_PROTECTION
_SC_MESSAGE_PASSING
_SC_MQ_OPEN_MAX
_SC_MQ_PRIO_MAX
_SC_NGROUPS_MAX
_SC_OPEN_MAX
_SC_PAGESIZE
_SC_PAGE_SIZE
_SC_PASS_MAX (LEGACY)
_SC_PRIORITIZED_IO
_SC_PRIORITY_SCHEDULING
_SC_RE_DUP_MAX


_SC_REALTIME_SIGNALS
_SC_RTSIG_MAX
_SC_SAVED_IDS
_SC_SEMAPHORES
_SC_SEM_NSEMS_MAX
_SC_SEM_VALUE_MAX
_SC_SHARED_MEMORY_OBJECTS
_SC_SIGQUEUE_MAX
_SC_STREAM_MAX
_SC_SYNCHRONIZED_IO
_SC_THREADS
_SC_THREAD_ATTR_STACKADDR
_SC_THREAD_ATTR_STACKSIZE
_SC_THREAD_DESTRUCTOR_ITERATIONS
_SC_THREAD_KEYS_MAX
_SC_THREAD_PRIORITY_SCHEDULING
_SC_THREAD_PRIO_INHERIT
_SC_THREAD_PRIO_PROTECT
_SC_THREAD_PROCESS_SHARED
_SC_THREAD_SAFE_FUNCTIONS
_SC_THREAD_STACK_MIN
_SC_THREAD_THREADS_MAX
_SC_TIMERS
_SC_TIMER_MAX
_SC_TTY_NAME_MAX
_SC_TZNAME_MAX
_SC_VERSION
_SC_XOPEN_VERSION
_SC_XOPEN_CRYPT
_SC_XOPEN_ENH_I18N
_SC_XOPEN_SHM
_SC_XOPEN_UNIX
_SC_XOPEN_XCU_VERSION
_SC_XOPEN_LEGACY
_SC_XOPEN_REALTIME
_SC_XOPEN_REALTIME_THREADS
_SC_XBS5_ILP32_OFF32
_SC_XBS5_ILP32_OFFBIG
_SC_XBS5_LP64_OFF64
_SC_XBS5_LPBIG_OFFBIG
The two constants _SC_PAGESIZE and _SC_PAGE_SIZE may be defined to have the same value.

The following symbolic constants are defined as possible values for the function argument to the lockf() function:

F_LOCK
Lock a section for exclusive use.
F_ULOCK
Unlock locked sections.
F_TEST
Test section for locks by other processes.
F_TLOCK
Test and lock a section for exclusive use.
The following symbolic constants are defined for pathconf():

_PC_ASYNC_IO
_PC_CHOWN_RESTRICTED
_PC_FILESIZEBITS
_PC_LINK_MAX
_PC_MAX_CANON
_PC_MAX_INPUT
_PC_NAME_MAX
_PC_NO_TRUNC
_PC_PATH_MAX
_PC_PIPE_BUF
_PC_PRIO_IO
_PC_SYNC_IO
_PC_VDISABLE
The following symbolic constants are defined for file streams:

STDIN_FILENO
File number of stdin. It is 0.
STDOUT_FILENO
File number of stdout. It is 1.
STDERR_FILENO
File number of stderr. It is 2.
 Type Definitions
The size_t, ssize_t, uid_t, gid_t, off_t and pid_t types are defined as described in <sys/types.h>.
The useconds_t type is defined as described in <sys/types.h>.

The intptr_t type is defined as described in <inttypes.h>.

 Declarations
The following are declared as functions and may also be defined as macros. Function prototypes must be provided for use with an ISO C compiler.

int          access(const char *, int);
unsigned int alarm(unsigned int);
int          brk(void *);
int          chdir(const char *);
int          chroot(const char *); (LEGACY)
int          chown(const char *, uid_t, gid_t);
int          close(int);
size_t       confstr(int, char *, size_t);
char        *crypt(const char *, const char *);
char        *ctermid(char *);
char        *cuserid(char *s); (LEGACY)
int          dup(int);
int          dup2(int, int);
void         encrypt(char[64], int);
int          execl(const char *, const char *, ...);
int          execle(const char *, const char *, ...);
int          execlp(const char *, const char *, ...);
int          execv(const char *, char *const []);
int          execve(const char *, char *const [], char *const []);
int          execvp(const char *, char *const []);
void        _exit(int);
int          fchown(int, uid_t, gid_t);
int          fchdir(int);
int          fdatasync(int);
pid_t        fork(void);
long int     fpathconf(int, int);
int          fsync(int);
int          ftruncate(int, off_t);
char        *getcwd(char *, size_t);
int          getdtablesize(void); (LEGACY)
gid_t        getegid(void);
uid_t        geteuid(void);
gid_t        getgid(void);
int          getgroups(int, gid_t []);
long         gethostid(void);
char        *getlogin(void);
int          getlogin_r(char *, size_t);
int          getopt(int, char * const [], const char *);
int          getpagesize(void); (LEGACY)
char        *getpass(const char *); (LEGACY)
pid_t        getpgid(pid_t);
pid_t        getpgrp(void);
pid_t        getpid(void);
pid_t        getppid(void);
pid_t        getsid(pid_t);
uid_t        getuid(void);
char        *getwd(char *);
int          isatty(int);
int          lchown(const char *, uid_t, gid_t);
int          link(const char *, const char *);
int          lockf(int, int, off_t);
off_t        lseek(int, off_t, int);
int          nice(int);
long int     pathconf(const char *, int);
int          pause(void);
int          pipe(int [2]);
ssize_t      pread(int, void *, size_t, off_t);
int          pthread_atfork(void (*)(void), void (*)(void),
                 void(*)(void));
ssize_t      pwrite(int, const void *, size_t, off_t);
ssize_t      read(int, void *, size_t);
int          readlink(const char *, char *, size_t);
int          rmdir(const char *);
void        *sbrk(intptr_t);
int          setgid(gid_t);
int          setpgid(pid_t, pid_t);
pid_t        setpgrp(void);
int          setregid(gid_t, gid_t);
int          setreuid(uid_t, uid_t);
pid_t        setsid(void);
int          setuid(uid_t);
unsigned int sleep(unsigned int);
void         swab(const void *, void *, ssize_t);
int          symlink(const char *, const char *);
void         sync(void);
long int     sysconf(int);
pid_t        tcgetpgrp(int);
int          tcsetpgrp(int, pid_t);
int          truncate(const char *, off_t);
char        *ttyname(int);
int          ttyname_r(int, char *, size_t);
useconds_t   ualarm(useconds_t, useconds_t);
int          unlink(const char *);
int          usleep(useconds_t);
pid_t        vfork(void);
ssize_t      write(int, const void *, size_t);

The following external variables are declared:


extern char   *optarg;
extern int    optind, opterr, optopt;

 APPLICATION USAGE
None.
 FUTURE DIRECTIONS
None.
 SEE ALSO
access(), alarm(), chdir(), chown(), close(), crypt(), ctermid(), dup(), encrypt(), environ(), exec, exit(), fchdir(), fchown(), fcntl(), fork(), fpathconf(), fsync(), ftruncate(), getcwd(), getegid(), geteuid(), getgid(), getgroups(), gethostid(), getlogin(), getpgid(), getpgrp(), getpid(), getppid(), getsid(), getuid(), getwd(), isatty(), lchown(), link(), lockf(), lseek(), nice(), pathconf(), pause(), pipe(), read(), readlink(), rmdir(), setgid(), setpgid(), setpgrp(), setregid(), setreuid(), setsid(), setuid(), sleep(), swab(), symlink(), sync(), sysconf(), tcgetpgrp(), tcsetpgrp(), truncate(), ttyname(), ualarm(), unlink(), usleep(), vfork(), write(), <limits.h>, <sys/types.h>, <termios.h>, .
UNIX ® is a registered Trademark of The Open Group.
Copyright © 1997 The Open Group
[ Main Index | XSH | XCU | XBD | XCURSES | XNS ]
