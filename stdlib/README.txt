The Single UNIX ® Specification, Version 2
Copyright © 1997 The Open Group
 NAME
stdlib.h - standard library definitions
 SYNOPSIS


#include <stdlib.h>

 DESCRIPTION
The <stdlib.h> header defines the following macro names:
EXIT_FAILURE
Unsuccessful termination for exit(), evaluates to a non-zero value.
EXIT_SUCCESS
Successful termination for exit(), evaluates to 0.
NULL
Null pointer.
RAND_MAX
Maximum value returned by rand(), at least 32,767.
MB_CUR_MAX
Integer expression whose value is the maximum number of bytes in a character specified by the current locale.
The following data types are defined through typedef:

div_t
Structure type returned by div() function.
ldiv_t
Structure type returned by ldiv() function.
size_t
As described in <stddef.h>.
wchar_t
As described in <stddef.h>.
In addition, the following symbolic names and macros are defined as in <sys/wait.h>, for use in decoding the return value from system():

WNOHANG
WUNTRACED
WEXITSTATUS()
WIFEXITED()
WIFSIGNALED()
WIFSTOPPED()
WSTOPSIG()
WTERMSIG()
The following are declared as functions and may also be defined as macros. Function prototypes must be provided for use with an ISO C compiler.


long      a64l(const char *);
void      abort(void);
int       abs(int);
int       atexit(void (*)(void));
double    atof(const char *);
int       atoi(const char *);
long int  atol(const char *);
void     *bsearch(const void *, const void *, size_t, size_t,
              int (*)(const void *, const void *));
void     *calloc(size_t, size_t);
div_t     div(int, int);
double    drand48(void);
char     *ecvt(double, int, int *, int *);
double    erand48(unsigned short int[3]);
void      exit(int);
char     *fcvt (double, int, int *, int *);
void      free(void *);


char     *gcvt(double, int, char *);
char     *getenv(const char *);
int       getsubopt(char **, char *const *, char **);
int       grantpt(int);
char     *initstate(unsigned int, char *, size_t);
long int  jrand48(unsigned short int[3]);
char     *l64a(long);
long int  labs(long int);
void      lcong48(unsigned short int[7]);
ldiv_t    ldiv(long int, long int);
long int  lrand48(void);
void     *malloc(size_t);
int       mblen(const char *, size_t);
size_t    mbstowcs(wchar_t *, const char *, size_t);
int       mbtowc(wchar_t *, const char *, size_t);
char     *mktemp(char *);
int       mkstemp(char *);
long int  mrand48(void);
long int  nrand48(unsigned short int [3]);
char     *ptsname(int);
int       putenv(char *);
void      qsort(void *, size_t, size_t, int (*)(const void *,
              const void *));
int       rand(void);
int       rand_r(unsigned int *);
long      random(void);
void     *realloc(void *, size_t);
char     *realpath(const char *, char *);
unsigned  short int    seed48(unsigned short int[3]);
void      setkey(const char *);
char     *setstate(const char *);
void      srand(unsigned int);
void      srand48(long int);
void      srandom(unsigned);
double    strtod(const char *, char **);
long int  strtol(const char *, char **, int);
unsigned long int
          strtoul(const char *, char **, int);
int       system(const char *);
int       ttyslot(void); (LEGACY)
int       unlockpt(int);
void     *valloc(size_t); (LEGACY)
size_t    wcstombs(char *, const wchar_t *, size_t);
int       wctomb(char *, wchar_t);

Inclusion of the <stdlib.h> header may also make visible all symbols from <stddef.h>, <limits.h>, <math.h> and <sys/wait.h>.

 APPLICATION USAGE
None.
 FUTURE DIRECTIONS
None.
 SEE ALSO
a64l(), abort(), abs(), atexit(), atof(), atoi(), atol(), bsearch(), calloc(), div(), drand48(), ecvt(), erand48(), exit(), fcvt(), free(), gcvt(), getenv(), getsubopt(), grantpt(), initstate(), jrand48(), l64a(), labs(), lcong48(), ldiv(), lrand48(), malloc(), mblen(), mbstowcs(), mbtowc(), mktemp(), mkstemp(), mrand48(), nrand48(), ptsname(), putenv(), qsort(), rand(), rand_r(), realloc(), realpath(), setstate(), srand(), srand48(), srandom(), strtod(), strtol(), strtoul(), unlockpt(), wcstombs(), wctomb(), <sys/types.h>.
UNIX ® is a registered Trademark of The Open Group.
Copyright © 1997 The Open Group
[ Main Index | XSH | XCU | XBD | XCURSES | XNS ]
