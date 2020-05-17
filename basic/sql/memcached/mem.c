//
// Created by zhangrongxiang on 2018/3/6 13:38
// File mem
//


#include <libmemcached/memcached.h>
#include <stdio.h>

int main() {
    memcached_st *memc;
    memcached_return ret;
    char server_list[] = "--SERVER=127.0.0.1:11211";
    char *key;
    char *value;

    // 创建一个客户端对象
    memc = memcached(server_list, strlen(server_list));

    if (NULL == memc) {
        perror("memcached_create return null.");
        return EXIT_SUCCESS;
    }
    // 给服务器发送flush_all命令
    ret = memcached_flush(memc, 0);
    if (ret != MEMCACHED_SUCCESS) {
        perror("memcached_flush failed.");
        return 1;
    }

//    // 添加10个元素
//    for (int i = 0; i < 10; i++) {
//        key = to_string(i);
//        value = to_string(i + 10);
//
//        // add key 0 0
//        // value
//        ret = memcached_add(memc, key.c_str(), key.length(), value.c_str(), value.length(), 0, 0);
//        if (ret != MEMCACHED_SUCCESS) {
//
//            cout << "memcached_add failed, ";
//            cout << "key<" << key << "> ";
//            cout << "value<" << value << "> ";
//            cout << "reason: " << memcached_strerror(memc, ret) << endl;
//            memcached_free(memc);
//            return 1;
//        }
//    }

    size_t value_len;
    uint32_t flags = 0;
    char *get_value;
    key = "key1";
    printf("%s\n", key);
    /*
     * get_value指向的内存是由memcached_get申请的，需要调用者释放。
     * 但是有一个疑问就是用什么接口释放那？
     * */
    get_value = memcached_get(memc, key, sizeof(key), &value_len, &flags, &ret);
    if (NULL == get_value) {
        //NOT FOUND
        printf("%s\n", memcached_strerror(memc, ret));
        printf("%s\n", memcached_error(memc));
        printf("%s\n", memcached_last_error_message(memc));
        perror("memcached_get failed, reason: ");
    } else {
        printf("%s\n", get_value);
    }
    /*
     * 直接使用free接口释放内存肯定是不对的。但是没有找到太好的办法。
     * */
    free(get_value);
    memcached_free(memc);
    return 0;
}