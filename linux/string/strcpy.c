//
// Created by zing on 2018/2/2 15:01
// File strcpy
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Copy SRC to DEST.  */

int main(void) {
    char *src = "Take the test.";
    //src[0] = 'M' ; // 这会是未定义行为
    char dst[strlen(src) + 1]; // +1 以适应空终止符
    strcpy(dst, src);
    dst[0] = 'M'; // OK
    printf("src = %s\ndst = %s\n", src, dst);

    char string[10];
    char str[] = "Hello World";
    char *string2 = str;
    printf("%s\n", string2); //Hello World\0

    printf("%d\n", (int) sizeof(string)); //10
    printf("%d\n", (int) strlen(string)); //0

    printf("%d\n", (int) sizeof(string2)); //8
    printf("%d\n", (int) strlen(string2)); //11

    printf("%d\n", (int) sizeof(str)); //12
    printf("%d\n", (int) strlen(str)); //11

    /******************行为未定义********************************/
    /** strcpy(string, string2);*/
    /** printf("%s\n", string);*/
    /** printf("%s\n", string2);*/
    /***********************************************************/

    char str2[sizeof(str)];
    strcpy(str2, string2);
    printf("%s\n", str2); //Hello World\0
    strcpy(str2, "hi");
    printf("%s\n", str2); //hi\0

    char str3[] = "hello world!\0hello everyone";
    printf("%s\n", str3); //hello world!
    printf("%d\n", (int) strlen(str3)); //12
    printf("%d\n", (int) sizeof(str3)); // 28

    return EXIT_SUCCESS;
}