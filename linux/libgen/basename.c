//
// Created by zing on 2021/4/7.
//

#include <libgen.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    printf("%s\n",__FILE__);
    printf("%s\n",basename(__FILE__));

    char path[100] = {0};
    char *cwd = getcwd(path, sizeof(path));
    printf("%s\n",cwd);
    printf("%s\n",basename(cwd));
    return 0;
}