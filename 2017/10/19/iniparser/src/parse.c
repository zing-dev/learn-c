#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "iniparser.h"

int main(int argc, char *argv[]) {
    dictionary *ini;
    char *ini_name;

    if (argc < 2) {
        ini_name = "twisted.ini";
    } else {
        ini_name = argv[1];
    }

    ini = iniparser_load(ini_name);
//    iniparser_dump(ini, stdout);
    const char *a = iniparser_getstring(ini, "quotes:h1", "-----");
    const char *a2 = iniparser_getstring(ini, "quotes:h2", "-----");
    const char *a3 = iniparser_getstring(ini, "quotes:h3", "-----");
    const char *a4 = iniparser_getstring(ini, "quotes:h4", "-----");
    const char *a5 = iniparser_getstring(ini, "quotes:h5", "-----");
    const char *a6 = iniparser_getstring(ini, "quotes:h6", "-----");
    printf("a --->  %s\n", a);
    printf("a2 --->  %s\n", a2);
    printf("a3 --->  %s\n", a3);
    printf("a4 --->  %s\n", a4);
    printf("a5 --->  %s\n", a5);
    printf("a6 --->  %s\n", a6);
    iniparser_freedict(ini);

    return 0;
}
