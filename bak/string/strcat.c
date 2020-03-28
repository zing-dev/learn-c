//
// Created by zhangrxiang on 2018/2/3.
//

#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "Hello C";
  char str2[50] = "Hello World";
  printf("%s\n", str);//Hello C
  printf("%s\n", str2);//Hello World
  char *str3 = strcat(str2, str);
  printf("%s\n", str2);//Hello WorldHello C
  printf("%s\n", str3);//Hello WorldHello C
  str3 = "hi everyone";
  printf("%s\n", str3);//hi everyone
  printf("%s\n", str2);//Hello WorldHello C
  str2[2] = 'L';
  str[2] = 'L';
  str[0] = 'h';
  printf("%s\n", str2);//HeLlo WorldHello C
  printf("%s\n", str);//heLlo C

  char *str4 = "hi world";
//  str[0] = 'H'; //行为为定义 h
  printf("%c\n",str4[0]);//h
  printf("%s\n",str4);

  char str5[80];
  strcpy (str5,"these ");
  strcat (str5,"strings ");
  strcat (str5,"are ");
  strcat (str5,"concatenated.");
  puts (str5);
  //these strings are concatenated.

  return 0;
}