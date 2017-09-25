//
// Created by zhangrongxiang on 2017/9/25 13:25
//

#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

//准备工作
int sockfd;//
char *IP = "127.0.0.1";//本机IP,回送地址
short PORT = 10222;
typedef struct sockaddr SA;//类型转换
char name[20];//客户端昵称
//启动客户端，连接服务器
void init() {
    printf("聊天室客户端开始启动\n");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(IP);
    if (connect(sockfd, (SA *) &addr, sizeof(addr)) == -1) {
        perror("无法连接到服务器");
        printf("客户端启动失败\n");
        exit(-1);
    }
    printf("客户端启动成功\n");
}

//开始通信
void *recv_thread(void *p) {//收消息
    while (1) {
        char buf[100] = {0};
        if (recv(sockfd, buf, sizeof(buf), 0) <= 0) {
            break;
        }
        printf("%s\n", buf);
    }
}

void start() {
    //发送消息
    //发消息之前，启动一个线程,用来接受服务器发送过来的消息
    pthread_t pid;
    pthread_create(&pid, 0, recv_thread, 0);
    while (1) {
        char buf[100] = {0};
        scanf("%s", buf);//接受用户输入
        char msg[100] = {0};
        sprintf(msg, "%s 说:%s", name, buf);
        send(sockfd, msg, strlen(msg), 0);//发给服务器
    }
}

void sig_close() {
    //关闭客户端的描述符
    close(sockfd);
    exit(0);
}

int main() {
    signal(SIGINT, sig_close);//关闭CTRL+C
    printf("请输入您的昵称:");
    scanf("%s", name);
    init();//连接服务器
    send(sockfd, name, strlen(name), 0);//将昵称发给服务器
    start();//开始通信
    return 0;
}