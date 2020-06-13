//
// Created by zing on 6/13/2020.
//

#include <stdio.h>

void func(){
    int ch;
    int flag = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            flag = 1;
        }
        if (flag == 0) {
            putchar(ch);
        } else {
            putchar('\n');
            flag = 0;
        }
    }
}

void fun2(){
    int ch;
    int flag = 0;
    while ((ch = getchar()) != EOF){
        if (ch == ' '){
            if (flag == 0){
                putchar('\n');
            }
            flag = 1;
        } else{
            putchar(ch);
            flag = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    fun2();
    return 0;
}
