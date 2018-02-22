//
// Created by zhangrongxiang on 2018/2/22 10:33
// File getpwnam
//

#include <stdio.h>
#include <pwd.h>

/* The passwd structure.  */
//struct passwd
//{
//    char *pw_name;		/* Username.  */
//    char *pw_passwd;		/* Password.  */
//    __uid_t pw_uid;		/* User ID.  */
//    __gid_t pw_gid;		/* Group ID.  */
//    char *pw_gecos;		/* Real name.  */
//    char *pw_dir;			/* Home directory.  */
//    char *pw_shell;		/* Shell program.  */
//};
//The  getpwnam()  function  returns a pointer to a structure containing the broken-out fields of the record in the password database
// (e.g., the local password file
//\/etc/passwd, NIS, and LDAP) that matches the username name.

int main(int argc,char *argv[]) {
    struct passwd *pw;
    char *username = "devis";
    if (argc == 2){
        username = argv[1];
    }
    pw = getpwnam(username);
    if (!pw) {
        printf("%s is not exist\n", username);
        return -1;
    }
//    ./a.out vagrant
    printf("pw->pw_name = %s\n", pw->pw_name);//vagrant
    printf("pw->pw_passwd = %s\n", pw->pw_passwd);//x
    printf("pw->pw_uid = %d\n", pw->pw_uid);//1000
    printf("pw->pw_gid = %d\n", pw->pw_gid);//1000
    printf("pw->pw_gecos = %s\n", pw->pw_gecos);//Vagrant Default User,,,
    printf("pw->pw_dir = %s\n", pw->pw_dir);//home/vagrant
    printf("pw->pw_shell = %s\n", pw->pw_shell);//bin/bash
    return 0;
}
