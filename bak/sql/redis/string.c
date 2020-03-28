//
// Created by zhangrongxiang on 2018/3/7 10:27
// File string
//
#include <hiredis/hiredis.h>
#include <stdlib.h>
#include <string.h>

int main() {
    redisContext *context = redisConnect("127.0.0.1", 6379);
    if (context->err) {
        printf("error: %s\n", context->errstr);
        redisFree(context);
        exit(EXIT_SUCCESS);
    }
    printf("Connect to redisServer Success\n");
    char *command = "get str";
    redisReply *reply = redisCommand(context, command);
    if (NULL == reply) {
        printf("exec command error \n");
        redisFree(context);
        exit(EXIT_FAILURE);
    }
    if (reply->type == REDIS_REPLY_STRING) {
        printf("%s:%s \n", "str", reply->str);
        printf("length:%d \n", reply->len);
    } else if (reply->type == REDIS_REPLY_NIL) {
        printf("%s is null\n", "str");
        command = "set str string";
        freeReplyObject(reply);
        reply = redisCommand(context, command);
        printf("%d\n", reply->type);
        if (reply->type == REDIS_REPLY_STATUS) {
            printf("set success\n");
        } else if (reply->type == REDIS_REPLY_ERROR) {
            printf("REDIS_REPLY_ERROR\n");
        }
    } else {
        printf("%d\n", reply->type);
        fprintf(stderr, "error happen\n");
    }
    freeReplyObject(reply);
    command = "APPEND str Hello-world";
    reply = redisCommand(context, command);
    if (reply->type == REDIS_REPLY_INTEGER) {
        printf("%lld\n", reply->integer);//length
    }
    freeReplyObject(reply);
    printf("%d\n", reply->type);
    return EXIT_SUCCESS;
}