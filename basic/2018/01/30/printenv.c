//
// Created by 张荣响 on 2018/1/30.
//


#include <stdio.h>

extern char **environ;

int main(int argc, char **argv) {
  int i;

  if (environ != NULL)
    for (i = 0; environ[i] != NULL; i++)
      printf("%s\n", environ[i]);

  return 0;
}