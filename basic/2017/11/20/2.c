//
// Created by zhangrongxiang on 2017/11/20 11:09
// File 2
//

#include <stdio.h>

#define T_DB_LOG "T_DB_LOG"
#define T_Admin "T_Admin"
#define T_Member "T_Member"
#define C_ADMIN() \
         sprintf(sql, "CREATE TABLE IF NOT EXISTS `%s`("\
         "`id` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
         "`username` vchar(64)," \
         "`serialnum`  vchar(36)," \
         "`pubkey` vchar(280));", T_Admin);
#define C_MEMBER() \
         sprintf(sql, "CREATE TABLE IF NOT EXISTS `%s`("\
         "`id` integer primary key," \
         "`username` vchar(64)," \
         "`macaddress`   vchar(18)," \
         "`ipaddress` INTEGER );", T_Member);


int main() {
    char sql[500];
    C_ADMIN();
    printf("%s\n", sql);
    C_MEMBER();
    printf("%s\n", sql);
}