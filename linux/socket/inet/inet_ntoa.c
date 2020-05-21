//
// Created by zing on 5/21/2020.
//
#include <stdio.h>
#include <arpa/inet.h>
#include <utils.h>

int main() {
    const unsigned char arr[] = {192, 168, 0, 1};
    printf("%lu\n", sizeof(arr));
    for (int i = 0; i < sizeof(arr); i++) {
        printf("%d\t", arr[i]);
    }
    ln();
    int sum = 0;
    for (int i = 0; i < sizeof(arr); i++) {
        sum += arr[i] << i * 8;
    }
    ln();
    for (int i = 0; i < 4; i++) {
        printf("%d\t", ((unsigned char *) &sum)[i]);
    }
    printf("%d\n", sum);
    
    struct in_addr addr;
    addr.s_addr = sum;
    char *addr_str = inet_ntoa(addr);
    printf("add is %s\n",addr_str);
}