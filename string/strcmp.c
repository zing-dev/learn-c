//
// Created by zhangrxiang on 17-8-27.
//



#include <string.h>
#include <stdio.h>

int main()
{
    const char *string = "Hello";
    const char *string2 = "Hello";
    const char *string3 = "HELLO";

    if(strcmp(string,string2) == 0){
        printf("%s\n","true");
    }
    else if(strcmp(string,string3) == 0){
        printf("%s\n","error");
    }
    else{
        printf("%s\n","unknown");
    }
}