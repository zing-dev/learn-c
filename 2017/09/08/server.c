//
// Created by zhang on 2017/9/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>

/*
int accfd[10];
static int i = 0;
int pthid[10];
*/
struct info {
    int accfd;
    int pthid;
    int num;
    struct info *next;
};

struct clinfo {
    char name[10];
    char buf[100];
};

static int i = 0;
struct info *head;

void *del(int n) {
    struct info *p;
    struct info *t;

    t = head;
    p = head->next;
    printf("del n:%d\n", n);
    while (p) {
        if (p->num == n) {
            t->next = p->next;
            free(p);
            break;
        }
        p = p->next;
        t = t->next;
    }

    printf("after free\n");
    t = head->next;
    while (t) {
        printf("t->num:%d\n", t->num);
        t = t->next;
    }
}

void *message(void *p) {
    printf("this is message\n");
    int num = (int) p;
    struct info *t = head;
    t = t->next;

    int accfd;
    int pthid;

    while (t) {
        if (t->num == num) {
            accfd = t->accfd;
            pthid = t->pthid;
            break;
        }
        t = t->next;
    }

    struct clinfo cin;
    memset(cin.buf, 0, sizeof(cin.buf));
    memset(cin.name, 0, sizeof(cin.name));
    while (1) {
        while (recv(accfd, &cin, sizeof(cin), 0) > 0) {
            printf("%s say: %s\n", cin.name, cin.buf);
            t = head->next;
            while (t) {
                printf("t->num:%d,num:%d\n", t->num, num);
                if (t->num != num) {
                    send(t->accfd, &cin, sizeof(cin), 0);
                }
                t = t->next;
            }
            if (!strcmp(cin.buf, "退出登陆")) {
                del(num);
                printf("即将退出线程\n");
                close(accfd);
                sleep(1);
                pthread_exit(0);
            }
            memset(cin.buf, 0, sizeof(cin.buf));
            memset(cin.name, 0, sizeof(cin.name));
        }
    }
}

struct info *init() {
    struct info *in;
    in = (struct info *) malloc(sizeof(struct info));
    in->next = NULL;
    return in;
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) perror("socket"), exit(-1);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(2222);
    addr.sin_addr.s_addr = inet_addr("172.30.13.70");

    //解决地址被占用问题
    int reuse = 10;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    //绑定
    int res = bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));
    if (res == -1) perror("bind"), exit(-1);
    //监听
    listen(sockfd, 100);
    struct sockaddr_in from;
    socklen_t len = sizeof(from);

    head = init();
    while (1) {
        //得到新的描述符
        int accfd = accept(sockfd, (struct sockaddr *) &from, &len);
        struct info *p = head;
        struct info *tmp = init();
        //让指针指向链表的尾部
        while (p->next) {
            p = p->next;
        }
        p->next = tmp;

        tmp->num = i++;
        tmp->accfd = accfd;
        printf("%s连接上来\n", inet_ntoa(from.sin_addr));
        //创建线程
        pthread_create(&(tmp->pthid), 0, message, (void *) (i - 1));
    }

}