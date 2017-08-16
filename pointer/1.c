//
// Created by zhangrxiang on 17-8-16.
//

#include <stdio.h>
#define PI 3.14


int main(void) {

    char *str = "ABCDEFGHIJKL";
    int *pInt = (int *) str;
    long *pLong = (long *) str;
    printf("%c\n%c\n%c\n", *(str + 1), //B
           *(char *) (pInt + 1),       //E
           *(char *) (pLong + 1));     //I


    char ch = 'a';
    int a = (int)ch;
    printf("%d %c\n", a, ch);


    int add = 0x123456;
    int *p = &add;
    printf("%d\n",*p);


    int pi = PI;
    int pi2 = 3.14;
    printf("PI is %f\n",PI);
    printf("pi is %d\n",pi);
    printf("pi2 is %d\n",pi2);

    char *string = "abcdef";
    printf("%s\n", string);
    printf("%d\n", *string);
//    *string = "fedcba";
//    printf("%s\n", string);
//    string[2] = 'C';     //修改第三个字符为大写
//    printf("%s\n", string);


    /**
     * 不管什么常量，其值是编译是固定好的，不能再被改变
     */

    /**
     * 变量里的值，和其数据类型没有关系，它只是一个二进制序列，
     * 不要将电脑想的多聪明，它只认识0, 1，只不过，这一堆01被其类型限定了其代表的意义，
     * 类型为整形就是其值，指针地址类型，就是内存里的一个地址，字符型，
     * 就是其无符号整形代表的ASCII码。
     */

    /**
     * 字符串，是常量(字符指针指向一字符串，不是数组，数组和指针的区别在后面)，其值不能再被改变，
     * char * str = "abcdef";
     * 这行代码的意思是告诉编译器：
     * 老编啊，我这儿有个抽屉（指针变量str），
     * 你给我找个房间（存放字符串的内存空间），
     * 找到后，把钥匙给我放到这个抽屉里。
     * 老编去找客房经理，找到后问：有没有空房间啊，有的话给我一间，一哥们要开房，
     * 客房经理去查房间入住情况（内存管理），
     * 最后说，这儿有一间，它是老总的房间，你要不先用着，你用没事，你可别乱动里面的东西，
     * 你要是动的话，估计你那哥们就被KILL掉，老板是黑社会的，
     * 不过，你用没事。于是，老编将老总房间钥匙给我放到了抽屉（指针变量str）里，
     * 这样，我打开抽屉（指针变量），拿出房间（内存空间）钥匙（指针），去开房了，
     * 老编告诉的，别乱动，用没事（读取），一定不能破坏里面的结构（修改数据内容），
     * 要是乱动（修改数据），会出乱子的（段错误），然后你会被KILL的（异常结束程序）。
     * 如果有两个人，就会Double kill，老板就GOD LIKE了
     * 。
     */

    return 0;

}