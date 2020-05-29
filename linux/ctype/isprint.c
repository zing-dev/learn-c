//
// Created by zing on 5/29/2020.
//

#include <stdio.h>
#include <ctype.h>
//checks for any printable character including space.
int main(){
    printf("%d\n",isprint('a'));
    printf("%d\n",isprint('\t'));
    printf("%d\n",isprint(' '));
    printf("%d\n",isprint('.'));
    return 0;
}