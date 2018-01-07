//
// Created by 张荣响 on 2018/1/7.
//

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  int fd;
  printf("---------------------\n");
  fd = open("ps.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd < 0) {
    perror("open error:");
    exit(0);
  }
  dup2(fd, STDOUT_FILENO);
  execlp("ps", "ps", "aux", NULL);
  perror("execlp error:");

}