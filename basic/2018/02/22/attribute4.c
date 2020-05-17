//
// Created by zhangrongxiang on 2018/2/22 14:31
// File attribute4
//

extern void myprint(const char *format, ...)__attribute__((format(printf, 1, 2)));
void test() {
    myprint("i=%d\n", 6);
    myprint("i=%s\n", 6);
    myprint("i=%s\n", "abc");
    myprint("%s,%d,%d\n", 1, 2);
}
