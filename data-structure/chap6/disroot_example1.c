#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"disroot.c"

void main() {
    double f(double);
    double a, b, eps, root;
    a = 0.0;
    b = 1.0;
    eps = 0.00001;              /* ����;���Ҫ��*/

    printf("    a          (a+b)/2         b\n\n");
    root = disroot(a, b, f, eps);              /* ���ַ��������ӡ���*/
    printf("\nThe root is  %1.7f\n", root);
}

double f(x)                               /* ����ķ���*/
double x;
{
double z;
z = x * x * x - 3 * x + 1;
return
z;
}


 
