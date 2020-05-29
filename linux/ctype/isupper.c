//
// Created by zing on 5/29/2020.
//

#include <stdio.h>
#include <ctype.h>
#include <assert.h>

//checks for an uppercase letter.
int main(){
    printf("%d\n",isupper('A'));
    printf("%d\n",isupper('a'));
    assert(!isupper('b'));
    assert(isupper('B'));
    return 0;
}