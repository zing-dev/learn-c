//
// Created by zing on 5/29/2020.
//
#include <ctype.h>
#include <assert.h>
//checks for white-space characters.  In the "C" and "POSIX"
//locales, these are: space, form-feed ('\f'), newline ('\n'),
//carriage return ('\r'), horizontal tab ('\t'), and vertical
//tab ('\v').
int main(){
    assert(isspace(' '));
    assert(isspace('\t'));
    assert(isspace('\n'));
    assert(isspace('\f'));
    assert(isspace('\r'));
    assert(isspace('\v'));
    assert(!isspace('\\'));
    return 0;
}