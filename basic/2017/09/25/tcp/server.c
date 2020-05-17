//
// Created by zhangrongxiang on 2017/9/25 13:26
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
struct client {//
    char name[20];//存储客户昵称
    int fds;//客户端socket描述符
};
struct client c[100] = {0};//最多记录100个链接到服务器的客户端
int size = 0;//记录客户端的个数，数组的索引
//初始化服务器的网络,创建socket
void init() {
    printf("聊天室服务器开始启动..\n");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("创建socket失败");
        printf("服务器启动失败\n");
        exit(-1);
    }
    //准备网络通信地址
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(IP);
    if (bind(sockfd, (SA *) &addr, sizeof(addr)) == -1) {
        perror("绑定失败");
        printf("服务器启动失败\n");
        exit(-1);
    }
    printf("成功绑定\n");
    //设置监听
    if (listen(sockfd, 10) == -1) {
        perror("设置监听失败");
        printf("服务器启动失败\n");
        exit(-1);
    }
    printf("设置监听成功\n");
    printf("初始化服务器成功\n");
    //等待客户端链接，放到另一个函数中
}

//线程函数,用来接受客户端的消息,并把消息发给所有客户端
//分发消息函数
void sendMsgToAll(char *msg) {
    int i = 0;
    for (; i < size; i++) {
        printf("%s sendto%d\n", c[i].name, c[i].fds);
        send(c[i].fds, msg, strlen(msg), 0);
    }
}

void *service_thread(void *p) {
    int fd = *(int *) p;//拿到标记客户端的sockfd
    printf("pthread=%d\n", fd);//输出测试
    //记录客户端的sockfd
    c[size].fds = fd;
    char name[20] = {0};
    if (recv(fd, name, sizeof(name), 0) > 0) {
        strcpy(c[size].name, name);//拿到昵称
    }
    size++;
    char tishi[100] = {0};
    //群发通知消息
    sprintf(tishi, "热烈欢迎 %s 登录聊天室..", name);
    //发给所有人
    sendMsgToAll(tishi);
    while (1) {
        char buf[100] = {0};
        if (recv(fd, buf, sizeof(buf), 0) == 0) {
            //返回0,表示TCP另一端断开链接
            //有客户端退出
            printf("fd=%dquit\n", fd);//测试
            int i;
            char name[20] = {0};
            for (i = 0; i < size; i++) {
                if (c[i].fds == fd) {
                    strcpy(name, c[i].name);
                    c[i].fds = c[size - 1].fds;
                    strcpy(c[i].name, c[size - 1].name);//用最后一个有效的数组元素，覆盖当前没用的这个保存退出的客户端的信息的数组元素
                }
            }
            size--;
            printf("quit->fd=%dquit\n", fd);
            char msg[100] = {0};
            sprintf(msg, "欢送 %s 离开聊天室,再见!", name);
            //群发退出通知
            sendMsgToAll(msg);
            close(fd);
            return;//客户端退出了，结束服务线程
        }
        sendMsgToAll(buf);//接受成功,广播聊天信息
    }
}

//等待客户端的连接，启动服务器的服务
void service() {
    printf("服务器开始服务\n");
    while (1) {
        struct sockaddr_in fromaddr;
        socklen_t len = sizeof(fromaddr);
        int fd = accept(sockfd, (SA *) &fromaddr, &len);
        if (fd == -1) {
            printf("客户端链接出错\n");
            continue;//继续循环，处理连接
        }
        //如果客户端成功连接上
        printf("fd=%d\n", fd);//测试
        //启动线程
        pthread_t pid;
        pthread_create(&pid, 0, service_thread, &fd);
    }
}

void sig_close() {
//关闭服务器的socket
    close(sockfd);
    printf("服务器已经关闭\n");
    exit(0);
}

int main() {
    signal(SIGINT, sig_close);//退出CTRL+C
    init();
    service();
    return 0;
}