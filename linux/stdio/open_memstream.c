//
// Created by zing on 6/2/2020.
//

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

/* Open a stream that writes into a malloc'd buffer that is expanded as
   necessary.  *BUFLOC and *SIZELOC are updated with the buffer's location
   and the number of characters written on fflush or fclose.  */
int main(){
    char *str = NULL;
    size_t len = 64;
    FILE *f = open_memstream(&str, &len);
    if (f == NULL){
        perror("open_memstream");
        return errno;
    }

    char *buf = "Open a stream that writes into a malloc'd buffer that is expanded as necessary.";
    fwrite(buf,1,strlen(buf) + 1,f);
    fflush(f);
    printf("%s\n",str);
    printf("%lu\n",strlen(str));
    fseek(f,5,SEEK_SET);
    free(str);
    fclose(f);
}