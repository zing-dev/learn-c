//
// Created by zing on 2021/4/1.
//

#include <libgen.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    char *name = dirname(".");
    printf("%s\n",name);//.

    char path[100] = {0};
    char *cwd = getcwd(path, sizeof(path));
    printf("cwd:  %s\n",cwd);
    printf("path: %s\n",path);
    printf("dirname(cwd):  %s\n",dirname(cwd));
    printf("dirname(path): %s\n",dirname(path));
}