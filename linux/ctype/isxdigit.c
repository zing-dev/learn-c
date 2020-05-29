//
// Created by zing on 5/29/2020.
//

#include <stdio.h>
#include <ctype.h>

//checks for hexadecimal digits, that is, one of
//0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F.
int main(){
    printf("%d\n",isxdigit('0'));
    printf("%d\n",isxdigit('a'));
    printf("%d\n",isxdigit('A'));
    printf("%d\n",isxdigit('g'));
    return 0;
}