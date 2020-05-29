//
// Created by zing on 5/29/2020.
//

#include <stdio.h>
#include <ctype.h>
int main(){
    //checks for any printable character which is not a space or an alphanumeric character.
    printf("%d\n",ispunct('1'));
    printf("%d\n",ispunct(' '));
    printf("%d\n",ispunct('\t'));
    printf("%d\n",ispunct('\a'));
    printf("%d\n",ispunct('.'));
    printf("%d\n",ispunct('a'));
}