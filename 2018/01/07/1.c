//
// Created by 张荣响 on 2018/1/7.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

  int i;
  pid_t pid;
  printf("begin.........................\n");

  for (i = 0; i < 5; i++) {
    pid = fork();
    if (pid == -1) {
      perror("fork error:");
      exit(1);
    } else if (pid == 0) {
      break;
    }
  }
  if (i < 5) {
    sleep(i);
    printf("%d child ,pid = %u\n", i + 1, getpid());
  } else {
    sleep(i);
    printf("parent\n");
  }
  return 0;
}