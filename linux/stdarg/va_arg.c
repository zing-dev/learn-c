//
// Created by zing on 5/20/2020.
//

#include <stdio.h>
#include <stdarg.h>

double average(int num, ...) {
    va_list valist;
    double sum = 0.0;
    int i; /* 为 num 个参数初始化 valist */
    va_start(valist, num); /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++) {
        sum += va_arg(valist, int);
    }

/* 清理为 valist 保留的内存 */
    va_end(valist);
    return sum / num;
}

size_t print(const char *message, ...) {
    va_list arg_list;
    va_start(arg_list, message);
    size_t ret_val = vprintf(message, arg_list);
    va_end(arg_list);
    return ret_val;
}

int main() {
    printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2, 3, 4, 5));
    printf("Average of 5, 10, 15 = %f\n", average(3, 5, 10, 15));
    print("I\'m %s, %d years old.\n", "zing", 25);
    return 0;
}