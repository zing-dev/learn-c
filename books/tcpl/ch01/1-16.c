//
// Created by zing on 6/20/2020.
//


#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 3    /* maximum input line size */

int get_line(char line[], int maxline);

void copy(char to[], const char from[]);

int main(void) {
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    int prevlen;        /* length of line before we ran out of mem */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */
    char temp[MAXLINE];     /* start of line before we ran out of mem */

    max = prevlen = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (prevlen + len > max) {
            max = prevlen + len;
            if (!prevlen)
                copy(longest, line);
            else
                copy(longest, temp);
        }
        if (line[len - 1] != '\n') {
            if (!prevlen) /* copy start of line to temp */
                copy(temp, line);
            prevlen += len;
        } else
            prevlen = 0;
    }
    if (max > 0) {   /* there was a line */
        printf("%s", longest);
        if (longest[max - 1] != '\n')
            putchar('\n');
        printf("%d characters\n", max);
    }
    return EXIT_SUCCESS;
}

/* get_line:  read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], const char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
