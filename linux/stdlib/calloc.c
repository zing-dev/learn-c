//
// Created by zing on 5/20/2020.
//

#include <stdlib.h>
#include <utils.h>

/*
 * The  calloc()  function  allocates  memory  for  an  array of nmemb elements of size bytes each and returns a
   pointer to the allocated memory.  The memory is set to zero.  If nmemb or size is 0,  then  calloc()  returns
   either NULL, or a unique pointer value that can later be successfully passed to free().
 */
int main(int argc, char *argv[]) {
    int length = 10;
    int *arr = calloc(length, sizeof(int));
    print_int_arr(arr, length);
    for (int i = 0; i < length; i++) {
        arr[i] = i * i;
    }
    print_int_arr(arr, length);

    char *arr_char = calloc(length, sizeof(char));
    print_char_arr(arr_char, length);
    for (int i = 0; i < length; i++) {
        arr_char[i] = (char) (i + 65);
    }
    print_char_arr(arr_char, length);
    printf("%s\n",arr_char);
    str_lower(arr_char);
    println("%s",arr_char);
    str_upper(arr_char);
    println("%s",arr_char);
    return 0;
}
