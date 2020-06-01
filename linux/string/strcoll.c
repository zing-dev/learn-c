//
// Created by zing on 6/1/2020.
//

#include <stdio.h>
#include <string.h>
/* Compare the collated forms of S1 and S2.  */
int main(int argc, char *argv[]) {
    printf("%d\n",strcoll("123","1234"));
    printf("%d\n",strcoll("1234","123"));
    printf("%d\n",strcoll("1234","1233"));
    printf("%d\n",strcoll("1230","123")); //48
    printf("%d\n",'0'); //48
    printf("%d\n",'4'); //52
    printf("%d\n",strcoll("1230","12"));//51
    return 0;
}
