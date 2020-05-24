//
// Created by zing on 5/24/2020.
//

#include <pthread.h>
#include <stdio.h>

void *start_thread(void *argv) {
    printf("======start_thread========\n");
    pthread_exit("hello world");
    printf("after pthread_exit\n");
}

int main(int argc, char *argv[]) {
    pthread_t pthread;
    void *rev = NULL;
    pthread_create(&pthread, NULL, start_thread, NULL);
    pthread_join(pthread, &rev);
    printf("the thread exit: %s\n", (char *) rev);
    return 0;
}
