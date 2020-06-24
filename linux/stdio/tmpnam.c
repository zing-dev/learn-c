//
// Created by zing on 6/23/2020.
//

#include <stdio.h>

/* Generate a temporary filename.  */
//tmpnam.c:(.text+0x1c): warning: the use of `tmpnam' is dangerous, better use `mkstemp'
int main(){
    char *name = tmpnam("a.txt");
    printf("%s\n",name);
    printf("%d\n",name == NULL);
    return 0;
}