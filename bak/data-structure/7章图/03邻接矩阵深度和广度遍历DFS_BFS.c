#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;    /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */

typedef char VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */

#define MAXSIZE 9 /* �洢�ռ��ʼ������ */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

typedef struct {
    VertexType vexs[MAXVEX]; /* ����� */
    EdgeType arc[MAXVEX][MAXVEX];/* �ڽӾ��󣬿ɿ����߱� */
    int numVertexes, numEdges; /* ͼ�е�ǰ�Ķ������ͱ��� */
} MGraph;

/* �õ��Ķ��нṹ�뺯��********************************** */

/* ѭ�����е�˳��洢�ṹ */
typedef struct {
    int data[MAXSIZE];
    int front;        /* ͷָ�� */
    int rear;        /* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
} Queue;

/* ��ʼ��һ���ն���Q */
Status InitQueue(Queue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

/* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
Status QueueEmpty(Queue Q) {
    if (Q.front == Q.rear) /* ���пյı�־ */
        return TRUE;
    else
        return FALSE;
}

/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
Status EnQueue(Queue *Q, int e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front)    /* ���������ж� */
        return ERROR;
    Q->data[Q->rear] = e;            /* ��Ԫ��e��ֵ����β */
    Q->rear = (Q->rear + 1) % MAXSIZE;/* rearָ�������һλ�ã� */
    /* ���������ת������ͷ�� */
    return OK;
}

/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
Status DeQueue(Queue *Q, int *e) {
    if (Q->front == Q->rear)            /* ���пյ��ж� */
        return ERROR;
    *e = Q->data[Q->front];                /* ����ͷԪ�ظ�ֵ��e */
    Q->front = (Q->front + 1) % MAXSIZE;    /* frontָ�������һλ�ã� */
    /* ���������ת������ͷ�� */
    return OK;
}

/* ****************************************************** */


void CreateMGraph(MGraph *G) {
    int i, j;

    G->numEdges = 15;
    G->numVertexes = 9;

    /* ���붥����Ϣ����������� */
    G->vexs[0] = 'A';
    G->vexs[1] = 'B';
    G->vexs[2] = 'C';
    G->vexs[3] = 'D';
    G->vexs[4] = 'E';
    G->vexs[5] = 'F';
    G->vexs[6] = 'G';
    G->vexs[7] = 'H';
    G->vexs[8] = 'I';


    for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
    {
        for (j = 0; j < G->numVertexes; j++) {
            G->arc[i][j] = 0;
        }
    }

    G->arc[0][1] = 1;
    G->arc[0][5] = 1;

    G->arc[1][2] = 1;
    G->arc[1][8] = 1;
    G->arc[1][6] = 1;

    G->arc[2][3] = 1;
    G->arc[2][8] = 1;

    G->arc[3][4] = 1;
    G->arc[3][7] = 1;
    G->arc[3][6] = 1;
    G->arc[3][8] = 1;

    G->arc[4][5] = 1;
    G->arc[4][7] = 1;

    G->arc[5][6] = 1;

    G->arc[6][7] = 1;


    for (i = 0; i < G->numVertexes; i++) {
        for (j = i; j < G->numVertexes; j++) {
            G->arc[j][i] = G->arc[i][j];
        }
    }

}

Boolean visited[MAXVEX]; /* ���ʱ�־������ */

/* �ڽӾ����������ȵݹ��㷨 */
void DFS(MGraph G, int i) {
    int j;
    visited[i] = TRUE;
    printf("%c ", G.vexs[i]);/* ��ӡ���㣬Ҳ������������ */
    for (j = 0; j < G.numVertexes; j++)
        if (G.arc[i][j] == 1 && !visited[j])
            DFS(G, j);/* ��Ϊ���ʵ��ڽӶ���ݹ���� */
}

/* �ڽӾ������ȱ������� */
void DFSTraverse(MGraph G) {
    int i;
    for (i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE; /* ��ʼ���ж���״̬����δ���ʹ�״̬ */
    for (i = 0; i < G.numVertexes; i++)
        if (!visited[i]) /* ��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ�� */
            DFS(G, i);
}

/* �ڽӾ���Ĺ�ȱ����㷨 */
void BFSTraverse(MGraph G) {
    int i, j;
    Queue Q;
    for (i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE;
    InitQueue(&Q);        /* ��ʼ��һ�����õĶ��� */
    for (i = 0; i < G.numVertexes; i++)  /* ��ÿһ��������ѭ�� */
    {
        if (!visited[i])    /* ����δ���ʹ��ʹ��� */
        {
            visited[i] = TRUE;        /* ���õ�ǰ������ʹ� */
            printf("%c ", G.vexs[i]);/* ��ӡ���㣬Ҳ������������ */
            EnQueue(&Q, i);        /* ���˶�������� */
            while (!QueueEmpty(Q))    /* ����ǰ���в�Ϊ�� */
            {
                DeQueue(&Q, &i);    /* ���Ӷ�Ԫ�س����У���ֵ��i */
                for (j = 0; j < G.numVertexes; j++) {
                    /* �ж������������뵱ǰ������ڱ���δ���ʹ�  */
                    if (G.arc[i][j] == 1 && !visited[j]) {
                        visited[j] = TRUE;            /* ���ҵ��Ĵ˶�����Ϊ�ѷ��� */
                        printf("%c ", G.vexs[j]);    /* ��ӡ���� */
                        EnQueue(&Q, j);                /* ���ҵ��Ĵ˶��������  */
                    }
                }
            }
        }
    }
}


int main(void) {
    MGraph G;
    CreateMGraph(&G);
    printf("\n��ȱ�����");
    DFSTraverse(G);
    printf("\n��ȱ�����");
    BFSTraverse(G);
    return 0;
}

