//
// Created by zhangrongxiang on 2017/10/31 9:18
// File 1
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t UL;

typedef struct STUDENT {
    char name[12];
    int age;
} Student;

typedef struct _ProcessArg {
    int sockfd;
    int access;
    unsigned char *SRvBuf;
} ProcessArg;

typedef struct _MsgHead {
    UL msgh;     //消息头=SNET_MSG_HEAD
    UL msgid;    //消息ID号，每发送一个消息，ID号加1
    UL cmd;      //消息命令码，服务端根据命令码调用相应的函数处理该消息
    UL error;    //消息错误标志，发送时为0，接收时为接收端处理的错误代码
    UL dataL;    //整个消息的数据长度，消息头除外
} MsgHead;


//消息体
typedef struct _MsgBody {
    UL type;    //数据类型
    UL len;    //在MsgBody后面跟着的数据长度
} MsgBody;

int getStu(void *data);

Student s;

int main() {
    unsigned char *ptr = NULL;
    printf("%ld\n", sizeof(ptr));
    ptr = (unsigned char *) malloc(sizeof(Student) * 10);
    getStu(ptr);
//    printf("%d\n",((Student *)(ptr))->age);
//    printf("%s\n",((Student *)(ptr))->name);
    int i = 0;
    for (; i < 10; ++i) {
        printf("%d\n", ((Student *) (ptr + i * sizeof(Student)))->age);
        printf("%s\n", ((Student *) (ptr + i * sizeof(Student)))->name);
    }
    printf("-------------------------------------------------------------\n");
    printf("%s --- %d  \n", s.name, s.age);
    printf("-------------------------------------------------------------\n");
    printf("_MsgHead -->  %ld\n", sizeof(struct _MsgHead));
    printf("_MsgBody -->  %ld\n", sizeof(struct _MsgBody));
    printf("_ProcessArg -->  %ld\n", sizeof(struct _ProcessArg));
    return 0;
}

int getStu(void *data) {
    Student *student = NULL;
//    data = (unsigned char *) malloc(sizeof(Student) * 10);
//    printf("%ld\n", sizeof(data));
//    student = (Student *) (data);
//    strcpy(student->name, "zing");
//    student->age = 1000;
    int i = 0;
    for (; i < 10; ++i) {
        student = (Student *) (data + i * sizeof(Student));
        strcpy(student->name, "zing");
        student->age = 100 + i;
    }
    return 0;
}