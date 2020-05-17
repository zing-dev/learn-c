//
// Created by zhangrongxiang on 2018/3/6 13:57
// File mem2
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

    memc = memcached_create(NULL);

    servers = memcached_server_list_append(NULL, (char *) "localhost", 11211, &rc);

    rc = memcached_server_push(memc, servers);
    memcached_server_free(servers);

    memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_DISTRIBUTION, MEMCACHED_DISTRIBUTION_CONSISTENT);
    memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_RETRY_TIMEOUT, 20);
    memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_SERVER_FAILURE_LIMIT, 5);
    memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_AUTO_EJECT_HOSTS, true);

    const char *keys[] = {"key1", "key2", "key3", "key4"};
    const size_t key_length[] = {4, 4, 4, 4};
    int i = 0;
    for (; i < 4; i++) {
        size_t length;
        char *str = memcached_get(memc, keys[i], key_length[i], &length, 0, 0);
        if (str == NULL) {
            perror("memcached_get");
        }
        printf("%s\n", str);
    }
    memcached_free(memc);
    return 0;
}
