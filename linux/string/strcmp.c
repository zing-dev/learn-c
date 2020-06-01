//
// Created by zing on 17-8-27.
//

#include <string.h>
#include <stdio.h>

/* Compare S1 and S2.  */
int main() {
    const char *string = "Hello";
    const char *string2 = "Hello";
    const char *string3 = "HELLO";

    if (strcmp(string, string2) == 0) {
        printf("%s\n", "true");
    } else if (strcmp(string, string3) == 0) {
        printf("%s\n", "error");
    } else {
        printf("%s\n", "unknown");
    }

    printf("%d\n",strcmp("1","3")); //-2
    printf("%d\n",strcmp("3","1")); //2
    printf("%d\n",strcmp("30","1")); //2

    return 0;
}