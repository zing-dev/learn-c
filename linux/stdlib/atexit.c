//
// Created by zing on 6/21/2020.
//

#include <stdlib.h>
#include <stdio.h>

void func (){
    printf("will exit\n");
}

/* Register a function to be called when `exit' is called.  */
int main(int argc, char *argv[]) {
    if (atexit(func) == 0){
        printf("注册exit callback\n");
    }
    exit(0);
}
