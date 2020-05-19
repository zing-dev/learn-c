//
// Created by zing on 5/19/2020.
//

#include <stdio.h>
/*
r      Open text file for reading.  The stream is positioned at the beginning of the file.
r+     Open for reading and writing.  The stream is positioned at the beginning of the file.
w      Truncate  file to zero length or create text file for writing.  The stream is positioned at the beginning of the file.
w+     Open for reading and writing.  The file is created if it does not exist, otherwise  it  is  truncated.
       The stream is positioned at the beginning of the file.
a      Open for appending (writing at end of file).  The file is created if it does not exist.  The stream is
       positioned at the end of the file.
a+     Open for reading and appending (writing at end of file).  The file is created if it  does  not  exist.
       The  initial  file position for reading is at the beginning of the file, but output is always appended
       to the end of the file.
*/

int main(int argc, char *argv[]) {
    const char* filename = "test.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        perror("open");
         file = fopen(filename, "w");
         if (file == NULL){
             perror("create");
             return -1;
         }
         printf("create file %s success\n",filename);
    }

    int res = remove(filename);
    if (res == -1){
        perror("remove");
        return res;
    }
    printf("remove %s success\n",filename);
    return 0;
}
