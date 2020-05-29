//
// Created by zing on 5/29/2020.
//

#include <ctype.h>
#include <assert.h>

//checks for a blank character; that is, a space or a tab.
int main(){
    assert(isblank(' '));
    assert(isblank('    '));
    assert(isblank('    '));
    assert(isblank('\t'));
}