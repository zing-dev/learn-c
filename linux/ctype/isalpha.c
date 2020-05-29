//
// Created by zing on 5/29/2020.
//

#include <stdio.h>
#include <ctype.h>
int main(){
    printf("%d\n",isalpha('a'));
    printf("%d\n",isalpha('A'));
    printf("%d\n",isalpha('.'));
    printf("%d\n",isalpha('1'));
    printf("%d\n",isalpha(80));
    return 0;
}