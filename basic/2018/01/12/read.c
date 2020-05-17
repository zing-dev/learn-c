#include <stdio.h>
#include <stdlib.h>

enum {
    SIZE = 5
};
int main() {
    FILE *pFile;
    long lSize = 0;
    double *buffer;
    size_t result;

    pFile = fopen("test.bin", "rb");
    if (pFile == NULL) {
        fputs("File error", stderr);
        exit(1);
    }

    // obtain file size:
    fseek(pFile, 0, SEEK_END);
    lSize = ftell(pFile);
    printf("%d\n",lSize);
    rewind(pFile);

    // allocate memory to contain the whole file:
    buffer = (double *) malloc(sizeof(double) * lSize);
    if (buffer == NULL) {
        fputs("Memory error", stderr);
        exit(2);
    }

    // copy the file into the buffer:
    result = fread(buffer, 1, lSize, pFile);
    if (result != lSize) {
        fputs("Reading error", stderr);
        exit(3);
    } else{
        int n = 0;
        for (;n < SIZE; ++n) printf("%f ", buffer[n]);
        putchar('\n');
    }

    /* the whole file is now loaded in the memory buffer. */

    // terminate
    fclose(pFile);
    free(buffer);
    return 0;
}