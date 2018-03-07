#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hiredis/hiredis.h>

int main(int argc, char **argv) {
    unsigned int j;
    redisContext *c;
    redisReply *reply;
    const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
    int port = (argc > 2) ? atoi(argv[2]) : 6379;

    struct timeval timeout = {1, 500000}; // 1.5 seconds
    c = redisConnectWithTimeout(hostname, port, timeout);
    if (c == NULL || c->err) {
        if (c) {
            printf("Connection error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }

    /* PING server */
    reply = redisCommand(c, "PING");
    printf("PING: %s\n", reply->str);
    freeReplyObject(reply);

    /* Set a key */
    reply = redisCommand(c, "SET %s %s", "foo", "hello world");
    printf("1 - reply->str: %s\n", reply->str);//OK
    printf("1 - reply->str: %d\n", reply->len);//2
    freeReplyObject(reply);
    reply = redisCommand(c, "get %s", "foo");
    printf("1 - reply->str: %s\n", reply->str);//hello world
    printf("1 - reply->str: %d\n", reply->len);//11

    /* Set a key using binary safe API */
    reply = redisCommand(c, "SET %b %b", "bar", (size_t) 3, "hello", (size_t) 5);
    printf("2 - SET (binary API): %s\n", reply->str);
    freeReplyObject(reply);
    reply = redisCommand(c, "GET %s", "bar");
    printf("2 - GET (binary API): %s\n", reply->str);//hello
    freeReplyObject(reply);

    /* Try a GET and two INCR */
    reply = redisCommand(c, "GET foo");
    printf("3 - GET foo: %s\n", reply->str);
    freeReplyObject(reply);

    reply = redisCommand(c, "INCR counter");
    printf("4 - INCR counter: %lld\n", reply->integer);//n
    freeReplyObject(reply);
    /* again ... */
    reply = redisCommand(c, "INCR counter");
    printf("4 - INCR counter: %lld\n", reply->integer);//n+1
    freeReplyObject(reply);

    /* Create a list of numbers, from 0 to 9 */
    reply = redisCommand(c, "DEL mylist");
    freeReplyObject(reply);
    for (j = 0; j < 10; j++) {
        char buf[64];
        snprintf(buf, 64, "%u", j);
        reply = redisCommand(c, "LPUSH mylist element-%s", buf);
        freeReplyObject(reply);
    }

    /* Let's check what we have inside the list */
    reply = redisCommand(c, "LRANGE mylist 0 -1");
    if (reply->type == REDIS_REPLY_ARRAY) {
        for (j = 0; j < reply->elements; j++) {
            printf("5 - %u) %s\n", j, reply->element[j]->str);
        }
    }
    freeReplyObject(reply);

    /* Disconnects and frees the context */
    redisFree(c);

    return 0;
}
