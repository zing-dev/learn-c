#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <io.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAX_LENGTH_INSERT_SORT 7 /* ���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ */

typedef int Status;


#define MAXSIZE 10000  /* ����Ҫ��������������ֵ���ɸ�����Ҫ�޸� */
typedef struct {
    int r[MAXSIZE + 1];    /* ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ���� */
    int length;            /* ���ڼ�¼˳���ĳ��� */
} SqList;

/* ����L������r���±�Ϊi��j��ֵ */
void swap(SqList *L, int i, int j) {
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

void print(SqList L) {
    int i;
    for (i = 1; i < L.length; i++)
        printf("%d,", L.r[i]);
    printf("%d", L.r[i]);
    printf("\n");
}

/* ��˳���L����������ð����������棩 */
void BubbleSort0(SqList *L) {
    int i, j;
    for (i = 1; i < L->length; i++) {
        for (j = i + 1; j <= L->length; j++) {
            if (L->r[i] > L->r[j]) {
                swap(L, i, j);/* ����L->r[i]��L->r[j]��ֵ */
            }
        }
    }
}

/* ��˳���L��ð������ */
void BubbleSort(SqList *L) {
    int i, j;
    for (i = 1; i < L->length; i++) {
        for (j = L->length - 1; j >= i; j--)  /* ע��j�ǴӺ���ǰѭ�� */
        {
            if (L->r[j] > L->r[j + 1]) /* ��ǰ�ߴ��ں��ߣ�ע����������һ�㷨�Ĳ��죩*/
            {
                swap(L, j, j + 1);/* ����L->r[j]��L->r[j+1]��ֵ */
            }
        }
    }
}

/* ��˳���L���Ľ�ð���㷨 */
void BubbleSort2(SqList *L) {
    int i, j;
    Status flag = TRUE;            /* flag������Ϊ��� */
    for (i = 1; i < L->length && flag; i++) /* ��flagΪtrue˵���й����ݽ���������ֹͣѭ�� */
    {
        flag = FALSE;                /* ��ʼΪFalse */
        for (j = L->length - 1; j >= i; j--) {
            if (L->r[j] > L->r[j + 1]) {
                swap(L, j, j + 1);    /* ����L->r[j]��L->r[j+1]��ֵ */
                flag = TRUE;        /* ��������ݽ�������flagΪtrue */
            }
        }
    }
}


/* ��˳���L����ѡ������ */
void SelectSort(SqList *L) {
    int i, j, min;
    for (i = 1; i < L->length; i++) {
        min = i;                        /* ����ǰ�±궨��Ϊ��Сֵ�±� */
        for (j = i + 1; j <= L->length; j++)/* ѭ��֮������� */
        {
            if (L->r[min] > L->r[j])    /* �����С�ڵ�ǰ��Сֵ�Ĺؼ��� */
                min = j;                /* ���˹ؼ��ֵ��±긳ֵ��min */
        }
        if (i != min)                        /* ��min������i��˵���ҵ���Сֵ������ */
            swap(L, i, min);                /* ����L->r[i]��L->r[min]��ֵ */
    }
}

/* ��˳���L��ֱ�Ӳ������� */
void InsertSort(SqList *L) {
    int i, j;
    for (i = 2; i <= L->length; i++) {
        if (L->r[i] < L->r[i - 1]) /* �轫L->r[i]���������ӱ� */
        {
            L->r[0] = L->r[i]; /* �����ڱ� */
            for (j = i - 1; L->r[j] > L->r[0]; j--)
                L->r[j + 1] = L->r[j]; /* ��¼���� */
            L->r[j + 1] = L->r[0]; /* ���뵽��ȷλ�� */
        }
    }
}

/* ��˳���L��ϣ������ */
void ShellSort(SqList *L) {
    int i, j, k = 0;
    int increment = L->length;
    do {
        increment = increment / 3 + 1;/* �������� */
        for (i = increment + 1; i <= L->length; i++) {
            if (L->r[i] < L->r[i - increment])/*  �轫L->r[i]�������������ӱ� */
            {
                L->r[0] = L->r[i]; /*  �ݴ���L->r[0] */
                for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
                    L->r[j + increment] = L->r[j]; /*  ��¼���ƣ����Ҳ���λ�� */
                L->r[j + increment] = L->r[0]; /*  ���� */
            }
        }
        printf("	��%d��������: ", ++k);
        print(*L);
    } while (increment > 1);

}


/* ������********************************** */

/* ��֪L->r[s..m]�м�¼�Ĺؼ��ֳ�L->r[s]֮�������ѵĶ��壬 */
/* ����������L->r[s]�Ĺؼ���,ʹL->r[s..m]��Ϊһ���󶥶� */
void HeapAdjust(SqList *L, int s, int m) {
    int temp, j;
    temp = L->r[s];
    for (j = 2 * s; j <= m; j *= 2) /* �عؼ��ֽϴ�ĺ��ӽ������ɸѡ */
    {
        if (j < m && L->r[j] < L->r[j + 1])
            ++j; /* jΪ�ؼ����нϴ�ļ�¼���±� */
        if (temp >= L->r[j])
            break; /* rcӦ������λ��s�� */
        L->r[s] = L->r[j];
        s = j;
    }
    L->r[s] = temp; /* ���� */
}

/*  ��˳���L���ж����� */
void HeapSort(SqList *L) {
    int i;
    for (i = L->length / 2; i > 0; i--) /*  ��L�е�r������һ������� */
        HeapAdjust(L, i, L->length);

    for (i = L->length; i > 1; i--) {
        swap(L, 1, i); /* ���Ѷ���¼�͵�ǰδ�����������е����һ����¼���� */
        HeapAdjust(L, 1, i - 1); /*  ��L->r[1..i-1]���µ���Ϊ����� */
    }
}

/* **************************************** */


/* �鲢����********************************** */

/* �������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n] */
void Merge(int SR[], int TR[], int i, int m, int n) {
    int j, k, l;
    for (j = m + 1, k = i; i <= m && j <= n; k++)    /* ��SR�м�¼��С����ز���TR */
    {
        if (SR[i] < SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    if (i <= m) {
        for (l = 0; l <= m - i; l++)
            TR[k + l] = SR[i + l];        /* ��ʣ���SR[i..m]���Ƶ�TR */
    }
    if (j <= n) {
        for (l = 0; l <= n - j; l++)
            TR[k + l] = SR[j + l];        /* ��ʣ���SR[j..n]���Ƶ�TR */
    }
}


/* �ݹ鷨 */
/* ��SR[s..t]�鲢����ΪTR1[s..t] */
void MSort(int SR[], int TR1[], int s, int t) {
    int m;
    int TR2[MAXSIZE + 1];
    if (s == t)
        TR1[s] = SR[s];
    else {
        m = (s + t) / 2;                /* ��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t] */
        MSort(SR, TR2, s, m);        /* �ݹ�ؽ�SR[s..m]�鲢Ϊ�����TR2[s..m] */
        MSort(SR, TR2, m + 1, t);    /* �ݹ�ؽ�SR[m+1..t]�鲢Ϊ�����TR2[m+1..t] */
        Merge(TR2, TR1, s, m, t);    /* ��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t] */
    }
}

/* ��˳���L���鲢���� */
void MergeSort(SqList *L) {
    MSort(L->r, L->r, 1, L->length);
}

/* �ǵݹ鷨 */
/* ��SR[]�����ڳ���Ϊs�������������鲢��TR[] */
void MergePass(int SR[], int TR[], int s, int n) {
    int i = 1;
    int j;
    while (i <= n - 2 * s + 1) {/* �����鲢 */
        Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
        i = i + 2 * s;
    }
    if (i < n - s + 1) /* �鲢����������� */
        Merge(SR, TR, i, i + s - 1, n);
    else /* �����ֻʣ�µ��������� */
        for (j = i; j <= n; j++)
            TR[j] = SR[j];
}

/* ��˳���L���鲢�ǵݹ����� */
void MergeSort2(SqList *L) {
    int *TR = (int *) malloc(L->length * sizeof(int));/* �������ռ� */
    int k = 1;
    while (k < L->length) {
        MergePass(L->r, TR, k, L->length);
        k = 2 * k;/* �����г��ȼӱ� */
        MergePass(TR, L->r, k, L->length);
        k = 2 * k;/* �����г��ȼӱ� */
    }
}

/* **************************************** */

/* ��������******************************** */

/* ����˳���L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ�� */
/* ��ʱ����֮ǰ(��)�ļ�¼������(С)������ */
int Partition(SqList *L, int low, int high) {
    int pivotkey;

    pivotkey = L->r[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
    while (low < high) /*  �ӱ�����˽�������м�ɨ�� */
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        swap(L, low, high);/* ���������¼С�ļ�¼�������Ͷ� */
        while (low < high && L->r[low] <= pivotkey)
            low++;
        swap(L, low, high);/* ���������¼��ļ�¼�������߶� */
    }
    return low; /* ������������λ�� */
}

/* ��˳���L�е�������L->r[low..high]���������� */
void QSort(SqList *L, int low, int high) {
    int pivot;
    if (low < high) {
        pivot = Partition(L, low, high); /*  ��L->r[low..high]һ��Ϊ�����������ֵpivot */
        QSort(L, low, pivot - 1);        /*  �Ե��ӱ�ݹ����� */
        QSort(L, pivot + 1, high);        /*  �Ը��ӱ�ݹ����� */
    }
}

/* ��˳���L���������� */
void QuickSort(SqList *L) {
    QSort(L, 1, L->length);
}

/* **************************************** */

/* �Ľ����������******************************** */

/* ���������Ż��㷨 */
int Partition1(SqList *L, int low, int high) {
    int pivotkey;

    int m = low + (high - low) / 2; /* ���������м��Ԫ�ص��±� */
    if (L->r[low] > L->r[high])
        swap(L, low, high);    /* ����������Ҷ����ݣ���֤��˽�С */
    if (L->r[m] > L->r[high])
        swap(L, high, m);        /* �����м����Ҷ����ݣ���֤�м��С */
    if (L->r[m] > L->r[low])
        swap(L, m, low);        /* �����м���������ݣ���֤��˽�С */

    pivotkey = L->r[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
    L->r[0] = pivotkey;  /* ������ؼ��ֱ��ݵ�L->r[0] */
    while (low < high) /*  �ӱ�����˽�������м�ɨ�� */
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        L->r[low] = L->r[high];
        while (low < high && L->r[low] <= pivotkey)
            low++;
        L->r[high] = L->r[low];
    }
    L->r[low] = L->r[0];
    return low; /* ������������λ�� */
}

void QSort1(SqList *L, int low, int high) {
    int pivot;
    if ((high - low) > MAX_LENGTH_INSERT_SORT) {
        while (low < high) {
            pivot = Partition1(L, low, high); /*  ��L->r[low..high]һ��Ϊ�����������ֵpivot */
            QSort1(L, low, pivot - 1);        /*  �Ե��ӱ�ݹ����� */
            /* QSort(L,pivot+1,high);		/*  �Ը��ӱ�ݹ����� */
            low = pivot + 1;    /* β�ݹ� */
        }
    } else
        InsertSort(L);
}

/* ��˳���L���������� */
void QuickSort1(SqList *L) {
    QSort1(L, 1, L->length);
}

/* **************************************** */
#define N 9

int main() {
    int i;

    /* int d[N]={9,1,5,8,3,7,4,6,2}; */
    int d[N] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
    /* int d[N]={9,8,7,6,5,4,3,2,1}; */

    SqList l0, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10;

    for (i = 0; i < N; i++)
        l0.r[i + 1] = d[i];
    l0.length = N;
    l1 = l2 = l3 = l4 = l5 = l6 = l7 = l8 = l9 = l10 = l0;
    printf("����ǰ:\n");
    print(l0);

    printf("����ð������:\n");
    BubbleSort0(&l0);
    print(l0);

    printf("ð������:\n");
    BubbleSort(&l1);
    print(l1);

    printf("�Ľ�ð������:\n");
    BubbleSort2(&l2);
    print(l2);

    printf("ѡ������:\n");
    SelectSort(&l3);
    print(l3);

    printf("ֱ�Ӳ�������:\n");
    InsertSort(&l4);
    print(l4);

    printf("ϣ������:\n");
    ShellSort(&l5);
    print(l5);

    printf("������:\n");
    HeapSort(&l6);
    print(l6);

    printf("�鲢���򣨵ݹ飩:\n");
    MergeSort(&l7);
    print(l7);

    printf("�鲢���򣨷ǵݹ飩:\n");
    MergeSort2(&l8);
    print(l8);

    printf("��������:\n");
    QuickSort(&l9);
    print(l9);

    printf("�Ľ���������:\n");
    QuickSort1(&l10);
    print(l10);


    /*����������*/
    /*
    srand(time(0));
    int Max=10000;
    int d[10000];
    int i;
    SqList l0;
    for(i=0;i<Max;i++)
        d[i]=rand()%Max+1;
    for(i=0;i<Max;i++)
        l0.r[i+1]=d[i];
    l0.length=Max;
    MergeSort(l0);
    print(l0);
    */
    return 0;
}
