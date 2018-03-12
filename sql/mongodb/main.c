//
// Created by zhangrongxiang on 2018/3/7 17:10
// File main
//

#include <stdio.h>
#include <mongoc.h>

int main() {
    mongo conn[1];
    int status = mongo_client(conn, "127.0.0.1", 27017);

    if (status != MONGO_OK) {
        switch (conn->err) {
            case MONGO_CONN_NO_SOCKET:
                printf("no socket\n");
                return 1;
            case MONGO_CONN_FAIL:
                printf("connection failed\n");
                return 1;
            case MONGO_CONN_NOT_MASTER:
                printf("not master\n");
                return 1;
        }
    }
    printf("connection done\n");

    mongo_destroy(conn);

    return 0;
}