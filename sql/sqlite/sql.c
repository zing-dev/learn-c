//
// Created by zhangrongxiang on 2018/2/23 14:10
// File sql
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

int queryCallback(void *stu, int argc, char **argv, char **azColName);

typedef struct STUDENT {
    unsigned int id;
    unsigned char name[16];
    unsigned int age;
    unsigned char address[64];
} Student;

void generateStudent(Student *student, int count) {
//    int count = 100;
//    Student student[count];
    int i = 0;
    for (; i < count; i++) {
        unsigned char name[16] = {0};
        unsigned char address[64] = {0};
        sprintf((char *) name, "zing%d", i);
        sprintf((char *) address, "jiangsu-wuxi-%d", i);
        student[i].id = (unsigned int) (1000 + i);
        memcpy(student[i].name, name, sizeof(name));
        student[i].age = (unsigned int) (10 + i);
        memcpy(student[i].address, address, sizeof(address));
        printf("%d-%s-%d-%s\n", student[i].id, student[i].name, student[i].age, student[i].address);
    }
//    printf("----------==ok---------\n");
//    for (i = 0; i < count; ++i) {
//        printf("id:%d,name:%s,age:%d,address:%s\n", student[i].id, student[i].name, student[i].age, student[i].address);
//    }
}

int createTable(sqlite3 *db) {
    char *result = {0};
    char *sql = "CREATE TABLE IF NOT EXISTS student("\
         "`id` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
         "`name`          TEXT    NOT NULL," \
         "`age`            INT     NOT NULL," \
         "`address`      TEXT NOT NULL);";
//    *table = *sql;
    int r = sqlite3_exec(db, sql, NULL, 0, &result);
    if (r == SQLITE_OK) {
        printf("create table success!\n");
    }
    return r;
}

int insertTable(sqlite3 *db, Student student) {
    char sql[128], *result = {0};
    sprintf(sql, "INSERT INTO student (`name`,`age`,`address`) VALUES('%s','%d','%s')", student.name, student.age,
            student.address);
    int rc = sqlite3_exec(db, sql, NULL, 0, &result);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", result);
        sqlite3_free(result);
    } else {
        printf("insert ok!\n");
    }
    return rc;
}

/*
 * @param stu
 * @param argc
 * @param argv
 * @param azColName
 * @return
 */
int queryCallback(void *stu, int argc, char **argv, char **azColName) {
    static int j;
    Student *student = stu;
    student[j].id = (unsigned int) atoi(argv[0]);
    memcpy(student[j].name, argv[1], sizeof(student[j].name));
    student[j].age = (unsigned int) atoi(argv[2]);
    memcpy(student[j].address, argv[3], sizeof(student[j].address));
    j++;
//    printf("\n");
//    for (i = 0; i < argc; i++) {
//        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//    }
//    printf("argc-->%d\n",argc);
    return 0;
}

int query(sqlite3 *db, Student *student, int index, int count) {
    char sql[128];
    sprintf(sql, "select * from student order by id desc limit %d,%d;", index, count);
    char **err = NULL;
    return sqlite3_exec(db, sql, queryCallback, student, err);
}

int queryTable(sqlite3 *db, Student *student, int index, int count) {
    char sql[128];
    if (count > 10)
        count = 10;
    sprintf(sql, "select * from student order by id desc limit %d,%d", index, count);
    printf("%s\n", sql);
    char *err = NULL;
    int col, row, i, j = 0;
    char **result;
    int rs = sqlite3_get_table(db, sql, &result, &row, &col, &err);
    if (rs == SQLITE_OK) {
        printf("row %d, col %d\n", row, col);
//        id-name-age-address
//        printf("%s-%s-%s-%s\n", result[0], result[1], result[2], result[3]);
//        1-zing0-10-jiangsu-wuxi-0
//        printf("%s-%s-%s-%s\n", result[4], result[5], result[6], result[7]);
//        printf("%s-%s-%s-%s\n", result[1120], result[1121], result[1122], result[1123]);
//        for (i = 0; i < (row + 1) * col; i++) {
//            printf("%s\n", result[i]);
//        }
        for (i = 0; i < (row + 1) * col; i++) {
            if (i % col == 0 && i >= col) {
                student[j].id = (unsigned int) atoi(result[i]);
                memcpy(student[j].name, result[i + 1], sizeof(student[i].name));
                student[j].age = (unsigned int) atoi(result[i + 2]);
                memcpy(student[j].address, result[i + 3], sizeof(student[i].address));
//                printf("id:%d,name:%s,age:%d,address:%s\n", student[j].id, student[j].name, student[j].age, student[j].address);
//                printf("id:%s,name:%s,age:%s,address:%s\n", result[i], result[i + 1], result[i + 2], result[i + 3]);
                j++;
            }
        }
    } else {
        printf("error\n");
    }
    return rs;
}

int update(sqlite3 *db, Student student) {

    char sql[128];
    sprintf(sql, "UPDATE student set address = '%s' where ID=%d;", student.address, student.id);
    char *err = NULL;
    /* Execute SQL statement */
    int rc = sqlite3_exec(db, sql, NULL, (void *) 0, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err);
        sqlite3_free(err);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    return rc;
}

int update2(sqlite3 *db, int id, char *address) {

    char sql[128];
    sprintf(sql, "UPDATE student set address = '%s' where ID=%d;", address, id);
    char *err = NULL;
    /* Execute SQL statement */
    int rc = sqlite3_exec(db, sql, NULL, (void *) 0, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err);
        sqlite3_free(err);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    return rc;
}

int update3(sqlite3 *db, void *data) {
    Student *student = (Student *) data;
    printf("-->  %d\n", student->id);
    printf("-->  %s\n", student->address);
    char sql[128];
    sprintf(sql, "UPDATE student set address = '%s' where ID=%d;", student->address, student->id);
    char *err = NULL;
    /* Execute SQL statement */
    int rc = sqlite3_exec(db, sql, NULL, (void *) 0, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err);
        sqlite3_free(err);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    return rc;
}


int main() {
    int i = 0;
    const char *name = "test.db";
    sqlite3 *db;
    int count = 10;
    Student student[count];

    int r = sqlite3_open(name, &db);
    if (r == 0) {
        printf("open sb success\n");
    }
//    generateStudent(student, count);
//    printf("----------==ok---------\n");
//    for (i = 0; i < count; ++i) {
//        printf("id:%d,name:%s,age:%d,address:%s\n", student[i].id, student[i].name, student[i].age, student[i].address);
//    }
//    createTable(db);
//    for (i = 0; i < count; ++i) {
//        insertTable(db, student[i]);
//    }
    if (queryTable(db, student, 2, 10) == SQLITE_OK) {
        for (i = 0; i < count; ++i) {
            printf("id:%d,name:%s,age:%d,address:%s\n", student[i].id, student[i].name, student[i].age,
                   student[i].address);
        }
    }

    Student stu;
    stu.id = 68;
    char *address = "jiangsu-xuzhou";
    memcpy(stu.address, address, strlen(address));
    update(db, stu);
    queryTable(db, student, 0, 10);
    for (i = 0; i < count; ++i) {
        printf("id:%d,name:%s,age:%d,address:%s\n", student[i].id, student[i].name, student[i].age,
               student[i].address);
    }
    update2(db, 69, address);
    queryTable(db, student, 0, 10);
    for (i = 0; i < count; ++i) {
        printf("id:%d,name:%s,age:%d,address:%s\n", student[i].id, student[i].name, student[i].age,
               student[i].address);
    }
    address = "jiangsu-suzhou";
    stu.id = 70;
    memcpy(stu.address, address, strlen(address));
    update3(db, &stu);
    if (queryTable(db, student, 0, 10)) {
        for (i = 0; i < count; ++i) {
            printf("update3-> id:%d,name:%s,age:%d,address:%s\n", student[i].id, student[i].name, student[i].age,
                   student[i].address);
        }
    }
    memset(student, 0, sizeof(student));
    if (query(db, student, 0, 10) == SQLITE_OK) {
        for (i = 0; i < count; ++i) {
            printf("update-> id:%d,name:%s,age:%d,address:%s\n", student[i].id, student[i].name, student[i].age,
                   student[i].address);
        }
    }
    sqlite3_close(db);
    return 0;
}