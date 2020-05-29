//
// Created by zing on 5/29/2020.
//

#include <stdio.h>
#include <ctype.h>

//checks for any printable character except space.
int main(){
    printf("%d\n",isgraph('\t'));
    printf("%d\n",isgraph('1'));
    printf("%d\n",isgraph('\n'));
    printf("%d\n",isgraph('\a'));
    printf("%d\n",isgraph('.'));
    return 0;
}