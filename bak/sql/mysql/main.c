//
// Created by zhangrongxiang on 2018/3/5 14:56
// File main
//

#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    MYSQL *mysql = NULL;
//    const char *host = "debian";
    const char *host = "localhost";
    const char *user = "root";
    const char *passwd = "root";
    const char *db = "fgap_config";
    unsigned int port = 3306;
    const char *unix_socket = "/var/run/mysqld/mysqld.sock";
    int flag = 0, i = 0;
    const char *db2 = "test";
    char sql[1024] = {0};

    if (mysql_library_init(0, NULL, NULL)) {
        fprintf(stderr, "could not initialize MySQL client library\n");
        exit(EXIT_FAILURE);
    }
    mysql = mysql_init(mysql);
    if (mysql == NULL) {
        perror("mysql_init error");
        return EXIT_FAILURE;
    }
    printf("mysql_init success\n");
    mysql = mysql_real_connect(mysql, host, user, passwd, db, port, unix_socket, 0);
    if (mysql == NULL) {
        fprintf(stderr, "Failed to connect to database: Error: %s\n", mysql_error(mysql));
        return EXIT_FAILURE;
    }
    printf("mysql_real_connect success\n");
    int ping = mysql_ping(mysql);
    if (ping == 0) {
        printf("mysql is active !\n");
    } else {
        return EXIT_FAILURE;
    }

    //////////////////////////////////////////////////////////////////
    const char *clientInfo = mysql_get_client_info();
    //5.5.58
    printf("mysql_get_client_info : %s\n", clientInfo);

    unsigned long version = mysql_get_client_version();
    //50558 = 5*10000 + 5*100 + 58
    //major_version*10000 + release_level*100 + sub_version
    printf("mysql_get_client_version : %ld\n", version);

    const char *serverInfo = mysql_get_server_info(mysql);
    //5.5.58-0+deb8u1
    printf("mysql_get_server_info : %s\n", serverInfo);

    const char *hostInfo = mysql_get_host_info(mysql);
    //Localhost via UNIX socket
    printf("mysql_get_host_info : %s\n", hostInfo);

    unsigned int protoInfo = mysql_get_proto_info(mysql);
    //10
    printf("mysql_get_proto_info : %d\n", protoInfo);

    unsigned long serverVersion = mysql_get_server_version(mysql);
    //50558
    printf("mysql_get_server_version : %ld\n", serverVersion);

    const char *mysqlInfo = mysql_info(mysql);
    //(null)
    printf("mysql_info : %s\n", mysqlInfo);

    const char *stat = mysql_stat(mysql);
    //mysql_stat : Uptime: 70217  Threads: 2  Questions: 824  Slow queries: 0  Opens: 69  Flush tables: 1  Open tables: 59  Queries per second avg: 0.011
    printf("mysql_stat : %s\n", stat);
    //////////////////////////////////////////////////////////////////

    MYSQL_RES *pRes = mysql_list_dbs(mysql, NULL);
    MYSQL_ROW row = NULL;
    if (pRes) {
        unsigned int fields = mysql_num_fields(pRes);
        my_ulonglong rows = mysql_num_rows(pRes);
        unsigned int count = mysql_field_count(mysql);
        printf("mysql_num_fields : %d\n", fields);//1
        printf("mysql_num_rows : %ld\n", (long) rows);//4
        printf("mysql_field_count : %d\n", count);//1
        while ((row = mysql_fetch_row(pRes)) != NULL) { // 打印结果集
            // database: information_schema
            // database: fgap_config
            // database: mysql
            // database: performance_schema
            if (strcmp(row[fields - 1], db2) == 0) {
                flag = 1;
            }
            printf("database: %-10s\n", row[fields - 1]);
        }
        mysql_free_result(pRes);
    }

    if (flag == 0) {
        printf("no %s db -> %d\n", db2, flag);
        //int mysql_create_db(MYSQL *mysql, const char *db)
        /*
         * //main.c:(.text+0x34f): undefined reference to `mysql_create_db'
        if(mysql_create_db(mysql,"test") == 0){
            printf("create test success\n");
        } else{
            printf("create test error\n");
        }
         */
    }
    if (mysql_select_db(mysql, db2) == 0) {
        printf("mysql_select_db(mysql, %s) success \n", db2);
        MYSQL_RES *tables = mysql_list_tables(mysql, NULL);
        unsigned int fields = mysql_num_fields(tables);
        my_ulonglong rows = mysql_num_rows(tables);
        printf("mysql_num_fields : %d\n", fields);//1
        printf("mysql_num_rows : %d\n", (int) rows);//1
        if (tables) {
            flag = 0;
            MYSQL_ROW fetchRow = NULL;
            while ((fetchRow = mysql_fetch_row(tables)) != NULL) {
                if (strcmp(fetchRow[fields - 1], "student") == 0)
                    flag = 1;
                printf("table : %-10s\n", fetchRow[fields - 1]);
            }
            if (!flag) {
                FILE *file = NULL;
                file = fopen("student.sql", "r");
                if (file) {
                    while (!feof(file)) {
                        char str[64] = {0};
                        fgets(str, sizeof(str), file);
                        strcat(sql, str);
                    }
                    printf("%s\n", sql);
                } else {
                    fprintf(stderr, "fopen student.sql error\n");
                    exit(EXIT_FAILURE);
                }
                fclose(file);
                int r = mysql_real_query(mysql, sql, (unsigned long) strlen(sql));
                if (r == 0) {
                    printf("table student was created success !! \n");
                } else {
                    printf("table student was created error !! \n");
                    exit(EXIT_FAILURE);
                }
            } else {
                printf("table student already exists !! \n");
            }
        } else {
            printf("something wrong\n");
        }
    }

    /////////////////////////////////////////////////////////////////

    memset(sql, 0, sizeof(sql));
    sprintf(sql, "select count(id) from student");
    int count = 0;
    if (mysql_real_query(mysql, sql, (unsigned int) strlen(sql)) == 0) {
        MYSQL_RES *result = mysql_store_result(mysql);
//        my_ulonglong rows = mysql_num_rows(result);
        unsigned int fields = mysql_num_fields(result);
        MYSQL_ROW fetchRow = mysql_fetch_row(result);
        count = atoi(fetchRow[fields - 1]);
        printf("count %d\n", count);
        mysql_free_result(result);
    }
    if (count < 50) {
        memset(sql, 0, sizeof(sql));
        for (i = 0; i < 10; ++i) {
            char name[16] = {0};
            char address[64] = {0};
            sprintf(name, "zing-%d", i);
            sprintf(address, "jiangsu-wuxi-%d", i);
            sprintf(sql, "INSERT INTO `student` (`name`,`age`,`address`) VALUES('%s','%d','%s')", name, 10 + i,
                    address);
            if (mysql_real_query(mysql, sql, (unsigned int) strlen(sql)) == 0) {
                my_ulonglong id = mysql_insert_id(mysql);
                printf("insert num %ld success\n", (long int) id);
            }
        }
    }
    memset(sql, 0, sizeof(sql));
    sprintf(sql, "select * from student order by id asc limit 0,20");
    if (mysql_real_query(mysql, sql, (unsigned int) strlen(sql)) == 0) {
        MYSQL_RES *result = mysql_store_result(mysql);
        unsigned int fields = mysql_num_fields(result);
        printf("fields %d\n", fields);
        MYSQL_ROW fetchRow;
        while ((fetchRow = mysql_fetch_row(result)) != NULL) {
            printf("id:%s name:%s age:%s address:%s \n", fetchRow[0], fetchRow[1], fetchRow[2], fetchRow[3]);
        }
        mysql_free_result(result);
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    memset(sql, 0, sizeof(sql));
    sprintf(sql, "update student set name='%s',age=%d,address='%s' where id between %d and %d;", "zhangrongxiang", 24,
            "jiangsu-xuzhou-1", 1, 10);
    if (mysql_real_query(mysql, sql, (int) strlen(sql)) == 0) {
        printf("mysql_affected_rows : %d\n", (int) mysql_affected_rows(mysql));
    }

    mysql_close(mysql);
    mysql_library_end();
    return EXIT_SUCCESS;
}

/*
 *
 * Initialize the MySQL client library by calling mysql_library_init().
 * This function exists in both the libmysqlclient C client library and the libmysqld embedded server library,
 * so it is used whether you build a regular client program by linking with the -libmysqlclient flag, or an embedded server application by linking with the -libmysqld flag.
 *
 * Initialize a connection handler by calling mysql_init() and connect to the server by calling mysql_real_connect().
 *
 * Issue SQL statements and process their results. (The following discussion provides more information about how to do this.)
 *
 * Close the connection to the MySQL server by calling mysql_close().
 *
 * End use of the MySQL client library by calling mysql_library_end().
 */