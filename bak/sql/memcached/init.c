//
// Created by zhangrongxiang on 2018/3/6 12:16
// File init
//

#include <libmemcached/memcached.h>
#include <stdio.h>

int main() {
    memcached_st *ptr = NULL;
    memcached_return rc;
    ptr = memcached_create(NULL);
    memcached_server_st *servers;

    if (ptr == NULL) {
        perror("memcached_create(ptr) error");
        exit(EXIT_FAILURE);
    }
//    servers = memcached_server_list_append(NULL, (char *) "localhost", 11211, &rc);

//    rc = memcached_server_push(ptr, servers);
//    memcached_server_free(servers);

//    char * memcached_get(memcached_st *ptr, const char *key, size_t key_length, size_t *value_length, uint32_t *flags, memcached_return_t *error);
    const char *key = "str_key";
    size_t key_length = strlen(key);
    size_t *value_length = NULL;
    uint32_t *flags = 0;
    memcached_return_t *error = NULL;
    char *value = memcached_get(ptr, key, key_length, value_length, flags, error);
    if (value == NULL) {
        //get error (0x75a010) NO SERVERS DEFINED -> libmemcached/initialize_query.cc:58
        printf("get error %s\n",memcached_error(ptr));
        exit(EXIT_FAILURE);
    }
    printf("--> %s\n", value);
    memcached_free(ptr);
    return 0;
}