//
// Created by zhangrongxiang on 2018/2/22 16:44
// File getpwuid
//

#include <stdio.h>
#include <pwd.h>

int main() {

    int uid = 1000;
    struct passwd *pw;
    pw = getpwuid(uid);
    if (pw) {
        printf("pw->pw_name = %s\n", pw->pw_name);//vagrant
        printf("pw->pw_passwd = %s\n", pw->pw_passwd);//x
        printf("pw->pw_uid = %d\n", pw->pw_uid);//1000
        printf("pw->pw_gid = %d\n", pw->pw_gid);//1000
        printf("pw->pw_gecos = %s\n", pw->pw_gecos);//Vagrant Default User,,,
        printf("pw->pw_dir = %s\n", pw->pw_dir);//home/vagrant
        printf("pw->pw_shell = %s\n", pw->pw_shell);//bin/bash
    } else {
        printf("%d is not exist\n", uid);
    }
}