//
// Created by zhangrongxiang on 2018/1/19 10:21
// File struct
//


/**
* Object allocation/initialization macro, using designated initializer.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT(this, ...) { (this) = malloc(sizeof(*(this))); \
                                                   *(this) = (typeof(*(this))){ __VA_ARGS__ }; }

/**
* Method declaration/definition macro, providing private and public interface.
*
* Defines a method name with this as first parameter and a return value ret,
* and an alias for this method with a _ prefix, having the this argument
* safely casted to the public interface iface.
* _name is provided a function pointer, but will get optimized out by GCC.
*/
#define METHOD(iface, name, ret, this, ...) \
        static ret name(union {iface *_public; this;} \
        __attribute__((transparent_union)), ##__VA_ARGS__); \
        static typeof(name) *_##name = (typeof(name)*)name; \
        static ret name(this, ##__VA_ARGS__)

/*
iface:接口类型,为调用函数name时，输入的第一个参数this的类型，iface类型应该和this参数的类型的开头部分相同
name:函数名称
ret:name函数的返回值类型
this:name函数的第一个参数(整个结构体的this)
*/

typedef struct STUDENTDO StudentDo;

struct STUDENTDO {
    void (*setName)(StudentDo *studentDo, char *name);
};

struct STUDENT {
    char name[20];
    unsigned int age;
    StudentDo studentDo;
};
typedef struct STUDENT Student;

METHOD(StudentDo, setName, void, Student *this, char *name) {
//    this->name = name;
    strcpy(this->name, name);
    this->age = 100;
//    memcpy(this->name, name,strlen(name) + 1);
//    printf("%s\n",this->name);
//    printf("%d\n",this->age);
}

int main() {
    Student *student;
    INIT(student, .age=10, .name="zing", .studentDo={
            .setName = _setName,
         },);
    StudentDo *studentDo = &student->studentDo;
    printf("%s's age is %d\n", student->name, student->age);
    studentDo->setName(student, "fuck");
    printf("%s's age is %d\n", student->name, student->age);
    return 0;
}