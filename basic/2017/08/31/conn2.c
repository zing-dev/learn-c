#include <stdio.h>
#include<mysql/mysql.h>

int main() {
    MYSQL mysql;

    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "fgap_config", 0, NULL, 0)) {
        printf("conn error.....%s\n", mysql_error(&mysql));
    } else {
        printf("success......\n");
    }

}
