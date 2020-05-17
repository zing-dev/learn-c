//
// Created by zhangrongxiang on 2017/11/21 13:19
// File wrap
//

#ifndef LEARN_C_WRAP_H
#define LEARN_C_WRAP_H

void perr_exit(const char *s);

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);

void Bind(int fd, const struct sockaddr *sa, socklen_t salen);

void Connect(int fd, const struct sockaddr *sa, socklen_t salen);

void Listen(int fd, int backlog);

int Socket(int family, int type, int protocol);

ssize_t Read(int fd, void *ptr, size_t nbytes);

ssize_t Write(int fd, const void *ptr, size_t nbytes);

void Close(int fd);

#endif //LEARN_C_WRAP_H
