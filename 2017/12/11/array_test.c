//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include "array.h"
//#include "common.h"
//
//int main(){
//
//    static Array *array;
//    int a = 5;
//    int b = 12;
//    int c = 848;
//    array_new(&array);
//    array_add(array,&a);
//    array_add(array,&b);
//    array_add(array,&c);
//    int index;
//    array_get_at(array,1,(void*)&index);
//    printf("%d\n",(int)index);
//    return 0;
//}


#include <stdio.h>
#include "array.h"

int main(int argc, char **argv) {
    // Create a new array
    Array *ar;
    array_new(&ar);
    int i = 10;

    // Add a string to the array
    array_add(ar, "Hello World!\n");
    array_add(ar, &i);

    // Retreive the string and print it
    char *str;
    int ii;
    array_get_at(ar, 0, (void*) &str);
    array_get_at(ar, 1, (void*) &ii);
    printf("%s\n", str);
    printf("%d\n", ii);

    return 0;
}