//
// Created by 张荣响 on 2018/1/30.
//

#define _GNU_SOURCE 1
#include <stdio.h>
#include <sys/types.h>

/* main --- read a line and echo it back out until EOF. */

int main(void) {
  char *line = NULL;
  size_t size = 0;
  ssize_t ret;

  while ((ret = getline(&line, &size, stdin)) != -1)
    printf("(%lu) %s", size, line);

  return 0;
}
