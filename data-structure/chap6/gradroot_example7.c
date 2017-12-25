#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"gradroot.c"

void main() {
    double eps = 0.000001;
    int n = 3, max = 600, i;
    double *x0;
    double f(double *, double *);
    x0 = (double *) malloc(n * sizeof(double));
    x0[0] = 1;                                    /* ��ֵ*/
    x0[1] = -3;
    x0[2] = 5;
    if (gradroot(x0, n, f, eps, max))                 /* ���ú������*/
    {
        for (i = 0; i < n; i++)
            printf("x[%d]=%1.7f\n", i, x0[i]);     /* ���*/
    } else
        printf("failed!\n");
}

double f(x, fd)                                   /* ������*/
double *x, *fd;
{
double f1, f2, f3, df1, df2, df3;
f1 = x[0] * x[0] + x[1] * x[1] + x[2] * x[2] - 40;
f2 = x[0] * x[0] + 7 * x[0] * x[1] + 3 * x[2] + 14;
f3 = 5 * x[0] * x[2] + x[1] * x[2] - 24;

df1 = 2.0 * x[0];
df2 = 2.0 * x[0];
df3 = 5.0 * x[2];
fd[0]=2.0*(
df1 *f1
+
df2 *f2
+
df3 *f3
);
df1 = 2 * x[1];
df2 = 7.0 * x[0];
df3 = x[2];
fd[1]=2.0*(
df1 *f1
+
df2 *f2
+
df3 *f3
);
df1 = 2.0 * x[2];
df2 = 3.0;
df3 = 5.0 * x[0] + x[1];
fd[2]=2.0*(
df1 *f1
+
df2 *f2
+
df3 *f3
);

return(
f1 *f1
+
f2 *f2
+
f3 *f3
);
}










