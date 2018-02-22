//
// Created by zhangrongxiang on 2018/2/22 13:49
// File attribute2
//
#include <stdio.h>
//__attrubte__ ((packed)) 的作用就是告诉编译器取消结构在编译过程中的优化对齐,按照实际占用字节数进行对齐。
#define __u8    unsigned char
#define __u16   unsigned short
/* __attribute__ ((packed)) 的位置约束是放于声明的尾部“；”之前 */
struct str_struct {
    __u8 a;
    __u8 b;
    __u8 c;
    __u16 d;
} __attribute__ ((packed));
/*  当用到typedef时，要特别注意__attribute__ ((packed))放置的位置，相当于：
  *  typedef struct str_stuct str;
  *  而struct str_struct 就是上面的那个结构。
  */
typedef struct {
    __u8 a;
    __u8 b;
    __u8 c;
    __u16 d;
} __attribute__ ((packed)) str;
/* 在下面这个typedef结构中，__attribute__ ((packed))放在结构名str_temp之后，其作用是被忽略的，注意与结构str的区别。*/
typedef struct {
    __u8 a;
    __u8 b;
    __u8 c;
    __u16 d;
} str_temp __attribute__ (());
typedef struct {
    __u8 a;
    __u8 b;
    __u8 c;
    __u16 d;
} str_nopacked;

int main(void) {
    printf("sizeof str = %d\n", (int) sizeof(str));//linux 5 mingw 6
    printf("sizeof str_struct = %d\n", (int) sizeof(struct str_struct));//linux 5 mingw 6
    printf("sizeof str_temp = %d\n", (int) sizeof(str_temp)); //linux 6 mingw 6
    printf("sizeof str_nopacked = %d\n", (int) sizeof(str_nopacked)); //linux 6 mingw6

    printf("__u8 --> %d\n",(int) sizeof(__u8));//1
    printf("__u16 --> %d\n",(int) sizeof(__u16));//2
    return 0;
}