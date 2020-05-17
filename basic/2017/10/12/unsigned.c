//
// Created by zhangrongxiang on 2017/10/12 9:47
// File unsigned
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    /**
     * char -128 ~ +127 (1 Byte)
     * short -32767 ~ + 32768 (2 Bytes)
     * unsigned short 0 ~ 65536 (2 Bytes)
     * int -2147483648 ~ +2147483647 (4 Bytes)
     * unsigned int 0 ~ 4294967295 (4 Bytes)
     * long == int
     * long long -9223372036854775808 ~ +9223372036854775807 (8 Bytes)
     * double 1.7 * 10^308 (8 Bytes)
     * unsigned int 0～4294967295
     * long long的最大值：9223372036854775807
     * long long的最小值：-9223372036854775808
     * unsigned long long的最大值：1844674407370955161
     * __int64的最大值：9223372036854775807
     * __int64的最小值：-9223372036854775808
     * unsigned __int64的最大值：18446744073709551615
     * 符号属性 长度属性 基本型 所占位数 取值范围 输入符举例 输出符举例
     * -- -- char                            8 -2^7 ~ 2^7-1 %c %c 、 %d 、 %u
     * signed -- char                    8 -2^7 ~ 2^7-1 %c %c 、 %d 、 %u
     * unsigned -- char                8 0 ~ 2^8-1 %c %c 、 %d 、 %u
     * [signed] short [int]            16 -2^15 ~ 2^15-1 %hd
     * unsigned short [int]           16 0 ~ 2^16-1 %hu 、 %ho 、 %hx
     * [signed] -- int                    32 -2^31 ~ 2^31-1 %d
     * unsigned -- [int]                 32 0 ~ 2^32-1 %u 、 %o 、 %x
     * [signed] long [int]              32 -2^31 ~ 2^31-1 %ld
     * unsigned long [int]             32 0 ~ 2^32-1 %lu 、 %lo 、 %lx
     * [signed] long long [int]       64 -2^63 ~ 2^63-1 %I64d
     * unsigned long long [int]      64 0 ~ 2^64-1 %lld，%llx
     * -- -- float                            32 +/- 3.40282e+038 %f 、 %e 、 %g
     * -- -- double                        64 +/- 1.79769e+308 %lf 、 %le 、 %lg %f 、 %e 、 %g
     * -- long double                    96 +/- 1.79769e+308 %Lf 、 %Le 、 %Lg
     */
    int a = -1;
    unsigned int b = 1;
    unsigned int c = -1;
    printf("c  %d\n", c);
    printf("c  %x\n", c);
//    如果运算数是有符号另一个数无符号，隐式将有符号参数强制类型为无符号数
    if (a > b)
        printf("a > b, a = %d, b = %u\n", a, b);
    else
        printf("a <= b, a = %d, b = %u\n", a, b);

    if (a > (int) b)
        printf("a > (int)b, a = %d, b = %u\n", a, b);
    else
        printf("a <= (int)b, a = %d, b = %u\n", a, b);
    exit(0);
}