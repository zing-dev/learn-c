//
// Created by zing on 2018/2/14.
//

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
void my_strtod(){
    // 带错误处理的剖析
    const char *p = "111.11 -2.22 Nan nan(2) inF 0X1.BC70A3D70A3D7P+6  1.18973e+4932zzz";
    printf("Parsing '%s':\n", p);
    char *end;
    for (double f = strtod(p, &end); p != end;) {
        printf("'%.*s' -->> ", (int) (end - p), p);
        p = end;
        if (errno == ERANGE) {
            printf("range error, got ");
            errno = 0;
        }
        printf("%f\n", f);
        f = strtod(p, &end);
    }

    // 无错误处理的剖析
    printf("\"  -0.0000000123junk\"  -->  %g\n", strtod("  -0.0000000123junk", NULL));
    printf("\"junk\"                 -->  %g\n", strtod("junk", NULL));
    char szOrbits[] = "365.24 29.53";
    char *pEnd;
    double d1, d2;
    d1 = strtod(szOrbits, &pEnd);
    d2 = strtod(pEnd, NULL);
    printf("The moon completes %.2f orbits per Earth year.\n", d1 / d2);
}

void my_strtod2(){
    char *end = NULL;
    double d = strtod("123.456ABC", &end);
    printf("%f\n",d);
    printf("%s\n",end);
}

int main(void) {
    my_strtod();
    my_strtod2();
    return 0;
}