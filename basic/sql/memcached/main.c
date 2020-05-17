//
// Created by zhangrongxiang on 2018/3/6 12:04
// File main
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <libmemcached/memcached.h>

int main(int argc, char *argv[]) {
    memcached_st *memc;
    memcached_return rc;
    memcached_server_st *servers;
    int i = 0;

    //connect multi server
    memc = memcached_create(NULL);

    servers = memcached_server_list_append(NULL, (char *) "localhost", 11211, &rc);
//    servers = memcached_server_list_append(servers, (char *) "localhost", 30000, &rc);

    rc = memcached_server_push(memc, servers);
    memcached_server_free(servers);

    memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_DISTRIBUTION, MEMCACHED_DISTRIBUTION_CONSISTENT);
    memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_RETRY_TIMEOUT, 20);
    // 同时设置MEMCACHED_BEHAVIOR_SERVER_FAILURE_LIMIT 和 MEMCACHED_BEHAVIOR_AUTO_EJECT_HOSTS
    //  memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_REMOVE_FAILED_SERVERS, 1) ;
    memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_SERVER_FAILURE_LIMIT, 5);
    memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_AUTO_EJECT_HOSTS, true);

    const char *keys[] = {"key1", "key2", "key3", "key4"};
    const size_t key_length[] = {4, 4, 4, 4};
    char *values[] = {
            "This is 1 first value",
            "This is 2 second value",
            "This is 3 third value",
            "This is 4 forth value"
    };
    size_t val_length[] = {
            strlen(values[0]),
            strlen(values[1]),
            strlen(values[2]),
            strlen(values[3])
    };

    for (; i < 4; i++) {
        rc = memcached_set(memc, keys[i], key_length[i], values[i], val_length[i], (time_t) 180, (uint32_t) 0);
        printf("key: %s  rc:%s\n", keys[i], memcached_strerror(memc, rc));   // 输出状态
    }
    for (i = 0; i < 4; i++) {
        size_t *len = NULL;
        char *val = memcached_get(memc, keys[i], key_length[i], len, 0, NULL);
        printf("%s -> %s \n", keys[i], val);
        free(val);
    }
    memcached_free(memc);
    return 0;
}
