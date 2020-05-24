//
// Created by zing on 5/24/2020.
//

#include <pthread.h>
#include <errno.h>
#include <stdio.h>

void *start_thread(void *argv) {
    printf("hello world\n");
    return 0;
}

int main(int argc, char *argv[]) {
    pthread_t pthread;
    void *ret = NULL;
//    if (pthread_create(&pthread, NULL, NULL, NULL) != 0) {
//        perror("pthread_create");
//        return errno;
//    }
    if (pthread_create(&pthread, NULL, &start_thread, NULL) != 0) {
        perror("pthread_create");
        return errno;
    }
    pthread_join(pthread, &ret);
    return 0;
}
