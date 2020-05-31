//
// Created by zing on 5/31/2020.
//

#include <string.h>
#include <stdio.h>

/* Copy no more than N bytes of SRC to DEST, stopping when C is found.
   Return the position in DEST one byte past where C was copied,
   or NULL if C was not found in the first N bytes of SRC.  */
int main(int argc, char *argv[]) {

    char str[] = "Copy no more than N bytes of SRC to DEST";
    char str2[] = "Return the position in DEST one byte past where C was copied";
    memccpy(str2, str, 'N', 30);

    printf("%s\n", str);//Copy no more than N bytes of SRC to DEST
    printf("%s\n", str2);//Copy no more than N in DEST one byte past where C was copied
    return 0;
}
