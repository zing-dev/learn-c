//
// Created by zhangrongxiang on 2017/11/16 10:21
// File 1
//


#include <stdio.h>
#include <string.h>

#define MAX_DATA_LEN    3072
typedef struct _MsgHead {
    unsigned long msgh;
    unsigned long msgid;
    unsigned long cmd;
    unsigned long error;
    unsigned long dataL;
} MsgHead;
typedef struct _MsgBody {
    unsigned long type;
    unsigned long len;
} MsgBody;
typedef struct _OPEN_SOCKET {
    int sockfd;
    int status;
    unsigned char *SendRcvBuf;
    unsigned long BufLength;
} OPEN_SOCKET;

unsigned char SRvBuf[MAX_DATA_LEN];
OPEN_SOCKET m_socket;

int main() {
    MsgHead *msghead = NULL;
    MsgBody *msgbody = NULL;
    memset(SRvBuf, 0x00, MAX_DATA_LEN);
    m_socket.SendRcvBuf = SRvBuf;
    msghead = (MsgHead *) m_socket.SendRcvBuf;
    msgbody = (MsgBody *) (m_socket.SendRcvBuf + sizeof(MsgHead));
    printf("msghead %d\n", sizeof(MsgHead));
    printf("msgbody %d\n", sizeof(MsgBody));
    printf("msghead %d\n", msghead);
    printf("msgbody %d\n", msgbody);
}