#define KEY name                                             /* ���ù�ϣ������Ҫ�ĺ�*/
#define NULLTag "\0"
#define DELTag "1\0"
#define HashSize 29

struct student {                                              /* ������ѧ����Ϣ�Ľṹ��*/
    int num;
    char name[8];
    char sex;
    int age;
};

typedef struct student ElemType;
typedef struct student *ElemTypeP;
typedef ElemType hashlist[HashSize];
typedef char KeyType[8];

int KeyEqu(char *stra, char *strb);   /* �жϹؼ����Ƿ���ͬ*/
void ElemCP(ElemType *a, ElemType *b);                         /* ��Ԫ��b�����ݿ�����a��*/
void ElemDEL(ElemType *a);                                    /* ��Ԫ��a�����ɾ��*/
void ElemNULL(ElemType *a);                                   /* ��Ԫ��a��ɿգ����ڳ�ʼ������չ�ϣ��*/

#include "stdio.h"
#include "string.h"
#include "hashk.c"
#include "hashpos.c"
#include "hashins.c"
#include "hashsch.c"
#include "hashdel.c"

main() {
    int i, m;
    static ElemType x[16] = {{101, "Zhao",  'M', 19},
                             {102, "Qian",  'F', 18},
                             {103, "Sun",   'M', 19},
                             {104, "Li",    'F', 20},
                             {105, "Zhou",  'M', 19},
                             {106, "Wu",    'F', 18},
                             {107, "Zheng", 'M', 17},
                             {108, "Wang",  'F', 21},
                             {109, "Jiang", 'M', 19},
                             {110, "Shen",  'F', 18},
                             {111, "Chu",   'M', 19},
                             {112, "Wei",   'F', 19},
                             {113, "He",    'M', 18},
                             {114, "Lv",    'F', 18},
                             {115, "Shi",   'M', 19},
                             {110, "Zhang", 'F', 18}};
    KeyType a = "Zhou";                                /* aΪҪ���ҵĹؼ���*/
    hashlist HT;                                        /* �����ϣ��*/
    m = HashSize;
    for (i = 0; i < m; i++)                                  /* ��ʼ����ϣ��*/
        ElemNULL(&HT[i]);
    for (i = 0; i < 16; i++)                                 /* ��Ԫ�ز����ϣ��*/
        hashins(HT, m, x[i]);
    i = hashsch(HT, m, a);                                /* �ڹ�ϣ���в���*/
    if (i != -1)
        printf("%-5d%-8s%-2c%-2d%\n", HT[i].num, HT[i].name, HT[i].sex, HT[i].age);
}

int KeyEqu(char *stra, char *strb)   /* �жϹؼ����Ƿ���ͬ*/
{
    return (!strcmp(stra, strb));
}

void ElemCP(ElemType *a, ElemType *b)                          /* ��Ԫ��b�����ݿ�����a��*/
{
    int i;
    a->num = b->num;
    for (i = 0; i < 8; i++)
        a->name[i] = b->name[i];
    a->name[7] = '\0';
    a->sex = b->sex;
    a->age = b->age;
}

void ElemDEL(ElemType *a)                                    /* ��Ԫ��a�����ɾ��*/
{
    int i;
    a->name[0] = '1';
    for (i = 1; i < 8; i++)
        a->name[i] = '\0';
}

void ElemNULL(ElemType *a)                                    /* ��Ԫ��a�����ɾ��*/
{
    int i;
    for (i = 0; i < 8; i++)
        a->name[i] = '\0';
}