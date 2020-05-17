#include<stdlib.h>
#include<stdio.h>


int main() {

    char *ptr = NULL;
    char *buflist = NULL;

    printf("buflist length is %d\n", sizeof(buflist));
    printf("char* length is %d\n", sizeof(char *));
    printf("length is %d\n", sizeof(buflist) / sizeof(buflist[0]));

    if ((buflist = malloc(1024)) == NULL) {
        printf("malloc error .... ...");
        exit(-1);
    }

    printf("buflist length is %d\n", sizeof(buflist));
    printf("char length is %d\n", sizeof(char));


    *((unsigned long *) buflist) = 0;
    printf("buflist[0] is %d\n", buflist[0]);
    printf("buflist[1] is %d\n", buflist[1]);
    printf("buflist[2] is %d\n", buflist[2]);
    printf("buflist length is %d\n", sizeof(buflist));

    printf("--------------------------------------------------------------\n");
    printf("*((unsigned long *)buflist)  -->  %d\n", *((unsigned long *) buflist));

    ptr = (char *) (*((unsigned long *) buflist));
    printf("ptr--->%d\n", sizeof(ptr));

    ptr = malloc(1024);

//	exit(0);
//	*((unsigned long *)buflist) = *((unsigned long *)ptr);

    printf("%d\n", buflist[0]);

}
