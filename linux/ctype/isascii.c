//
// Created by zing on 5/29/2020.
//

#include <ctype.h>
#include <assert.h>

int main(){
    assert(isascii('0'));
    assert(isascii('b'));
    assert(__isascii('['));
    assert((((125) & ~0x7f) == 0));
    assert((((127 ) & ~0x7f) == 0));
    assert(!(((128 ) & ~0x7f) == 0));
    return 0;
}