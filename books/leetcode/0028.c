//
// Created by zing on 2021/3/10.
//

#include <stdio.h>
#include <string.h>

//unfinished
int strStr1(char *haystack, char *needle) {
    /* char *str = "";
     if (needle == str) {
         return 0;
     }
     if (haystack == str) {
         return -1;
     }*/
    if (strlen(needle) == 0) {
        return 0;
    }
    if (strlen(haystack) == 0 || strlen(haystack) < strlen(needle)) {
        return -1;
    }
    int index = 0;
    int count = 0;
    int i = 0, j = 0;
    for (; haystack[i] != '\0'; i++) {
        if (needle[j] == '\0') {
            break;
        }
        if (haystack[i] == needle[j]) {
            count++;
            j++;
        } else {
            index = i - count;
            count = 0;
        }
        if (count == 0) {
            index = -1;
        }
    }
    printf("-> %d %d\n", count, index);
    return index;
}

//unfinished
int strStr2(char *haystack, char *needle) {
    int l1 = 0, l2 = 0;
    char *s1 = haystack;
    char *s2 = needle;
    while (*haystack != '\0') {
        haystack++;
        l1++;
    }
    while (*needle != '\0') {
        needle++;
        l2++;
    }
    printf("l1 %d l2 %d\n", l1, l2);
    if (l2 == 0) {
        return 0;
    }
    int count = 0;
    int position = 0;
    for (int i = 0; i < l1; ++i) {
        for (int j = position; j < l2;) {
            if (s1[i] == s2[j]) {
                count++;
                position = j;
                //printf("%d %d\n",i,j);
                if (count == l2) {
                    printf("=>  %d %d %d\n", i, j, count);
                }
            } else {
                count = 0;
                position = 0;
            }
            break;
        }
    }
    return position - count;
}

int strStr(char *haystack, char *needle) {
    int l1 = (int) strlen(haystack);
    int l2 = (int) strlen(needle);
    if (l2 == 0) {
        return 0;
    }
    if (l2 > l1) {
        return -1;
    }
    int p1 = 0, p2 = 0;
    while (haystack[p1] != '\0' && needle[p2] != '\0') {
        if (haystack[p1] == needle[p2]) {
            p1++;
            p2++;
        } else {
            p1 = p1 - p2 + 1;
            p2 = 0;
        }
    }
    if (p2 == l2) {
        return p1 - p2;
    } else {
        return -1;
    }
}

void emptyStr() {
    char *str = "";
    //Result of comparison against a string literal is unspecified
    // (use an explicit string comparison function instead)
    printf("\n%d\n", str == ""); // 1

    printf("%d\n", !str); // 0

    printf("%lu\n", strlen(str)); // 0

    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    printf("%d\n", i); // 0
    printf("%d\n", str[0]); // 0

    char *str2 = "";
    printf("%d\n", str == str2); // 1

    char *str3 = NULL;
    printf("%d\n", str3 == NULL); // 1
    printf("%d\n", str3[0] == '\0'); // 1

}

void loopStr() {
    char *str = "hello world";
    while (*str != '\0') {
        printf("%c", *str);
        str++;
    }
    printf("\n");
    str = "hello world";
    for (int i = 0; str[i] != '\0'; ++i) {
        printf("%d%c ", i, str[i]);
    }
}

typedef struct {
    char *haystack;
    char *needle;
    int res;
} T;

int main() {
    T t[] = {
            {"hello",       "ll",     2},
            {"abcd",        "a",      0},
            {"abcd",        "cd",     2},
            {"abcd",        "",       0},
            {"",            "",       0},
            {"mississippi", "issip",  4},
            {"aaaaa",       "bba",    -1},
            {"aa",          "aaa",    -1},
            {"mississippi", "issipi", -1},
            {"",            "aaa",    -1},
    };
    for (int i = 0; i < sizeof(t) / sizeof(t[0]); ++i) {
        int res = strStr(t[i].haystack, t[i].needle);
        if (res != t[i].res) {
            printf("%02d. err:     want %d but %d\n", i + 1, t[i].res, res);
        } else {
            printf("%02d. success: want %d and got %d \n", i + 1, t[i].res, res);
        }
    }
    loopStr();
    emptyStr();
}

//KMP