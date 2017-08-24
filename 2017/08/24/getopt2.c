//
// Created by zhangrxiang on 17-8-24.
//

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int oc;                     /*选项字符 */
    char *b_opt_arg;            /*选项参数字串 */

    while ((oc = getopt(argc, argv, "bg:l:")) != -1) {
        switch (oc) {
            case 'b':
                printf("My name is zhangrongxiang.\n");
                break;
            case 'g':
                printf("Her name is null.\n");
                printf("Her name is %s.\n",optarg);
                break;
            case 'l':
                b_opt_arg = optarg;
                printf("Our love is %s\n", optarg);
                break;
        }
    }
    return 0;
}