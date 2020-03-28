#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXEDGE 30
#define MAXVEX 30
#define INFINITY 65535

typedef int Status;    /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

int *etv, *ltv; /* �¼����緢��ʱ�����ٷ���ʱ�����飬ȫ�ֱ��� */
int *stack2;   /* ���ڴ洢�������е�ջ */
int top2;       /* ����stack2��ָ�� */

/* �ڽӾ���ṹ */
typedef struct {
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

/* �ڽӱ�ṹ****************** */
typedef struct EdgeNode /* �߱���  */
{
    int adjvex;    /* �ڽӵ��򣬴洢�ö����Ӧ���±� */
    int weight;        /* ���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ */
    struct EdgeNode *next; /* ����ָ����һ���ڽӵ� */
} EdgeNode;

typedef struct VertexNode /* ������� */
{
    int in;    /* ������� */
    int data; /* �����򣬴洢������Ϣ */
    EdgeNode *firstedge;/* �߱�ͷָ�� */
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges; /* ͼ�е�ǰ�������ͱ��� */
} graphAdjList, *GraphAdjList;

/* **************************** */


void CreateMGraph(MGraph *G)/* ����ͼ */
{
    int i, j;
    /* printf("����������Ͷ�����:"); */
    G->numEdges = 13;
    G->numVertexes = 10;

    for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
    {
        G->vexs[i] = i;
    }

    for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
    {
        for (j = 0; j < G->numVertexes; j++) {
            if (i == j)
                G->arc[i][j] = 0;
            else
                G->arc[i][j] = INFINITY;
        }
    }

    G->arc[0][1] = 3;
    G->arc[0][2] = 4;
    G->arc[1][3] = 5;
    G->arc[1][4] = 6;
    G->arc[2][3] = 8;
    G->arc[2][5] = 7;
    G->arc[3][4] = 3;
    G->arc[4][6] = 9;
    G->arc[4][7] = 4;
    G->arc[5][7] = 6;
    G->arc[6][9] = 2;
    G->arc[7][8] = 5;
    G->arc[8][9] = 3;

}

/* �����ڽӾ��󹹽��ڽӱ� */
void CreateALGraph(MGraph G, GraphAdjList *GL) {
    int i, j;
    EdgeNode *e;

    *GL = (GraphAdjList) malloc(sizeof(graphAdjList));

    (*GL)->numVertexes = G.numVertexes;
    (*GL)->numEdges = G.numEdges;
    for (i = 0; i < G.numVertexes; i++) /* ���붥����Ϣ����������� */
    {
        (*GL)->adjList[i].in = 0;
        (*GL)->adjList[i].data = G.vexs[i];
        (*GL)->adjList[i].firstedge = NULL;    /* ���߱���Ϊ�ձ� */
    }

    for (i = 0; i < G.numVertexes; i++) /* �����߱� */
    {
        for (j = 0; j < G.numVertexes; j++) {
            if (G.arc[i][j] != 0 && G.arc[i][j] < INFINITY) {
                e = (EdgeNode *) malloc(sizeof(EdgeNode));
                e->adjvex = j;                    /* �ڽ����Ϊj */
                e->weight = G.arc[i][j];
                e->next = (*GL)->adjList[i].firstedge;    /* ����ǰ�����ϵ�ָ��Ľ��ָ�븳ֵ��e */
                (*GL)->adjList[i].firstedge = e;        /* ����ǰ�����ָ��ָ��e  */
                (*GL)->adjList[j].in++;

            }
        }
    }

}


/* �������� */
Status TopologicalSort(GraphAdjList GL) {    /* ��GL�޻�·������������������в�����1�����л�·����0�� */
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;  /* ����ջָ���±�  */
    int count = 0;/* ����ͳ���������ĸ��� */
    int *stack;    /* ��ջ�����Ϊ0�Ķ�����ջ  */
    stack = (int *) malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        if (0 == GL->adjList[i].in) /* �����Ϊ0�Ķ�����ջ */
            stack[++top] = i;

    top2 = 0;
    etv = (int *) malloc(GL->numVertexes * sizeof(int)); /* �¼����緢��ʱ������ */
    for (i = 0; i < GL->numVertexes; i++)
        etv[i] = 0;    /* ��ʼ�� */
    stack2 = (int *) malloc(GL->numVertexes * sizeof(int));/* ��ʼ����������ջ */

    printf("TopologicalSort:\t");
    while (top != 0) {
        gettop = stack[top--];
        printf("%d -> ", GL->adjList[gettop].data);
        count++;        /* ���i�Ŷ��㣬������ */

        stack2[++top2] = gettop;        /* �������Ķ������ѹ���������е�ջ */

        for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
            k = e->adjvex;
            if (!(--GL->adjList[k].in))        /* ��i�Ŷ�����ڽӵ����ȼ�1�������1��Ϊ0������ջ */
                stack[++top] = k;

            if ((etv[gettop] + e->weight) > etv[k])    /* ��������¼������緢��ʱ��etvֵ */
                etv[k] = etv[gettop] + e->weight;
        }
    }
    printf("\n");
    if (count < GL->numVertexes)
        return ERROR;
    else
        return OK;
}

/* ��ؼ�·��,GLΪ�����������G�ĸ���ؼ�� */
void CriticalPath(GraphAdjList GL) {
    EdgeNode *e;
    int i, gettop, k, j;
    int ete, lte;  /* ��������緢��ʱ�����ٷ���ʱ����� */
    TopologicalSort(GL);   /* ���������У���������etv��stack2��ֵ */
    ltv = (int *) malloc(GL->numVertexes * sizeof(int));/* �¼����緢��ʱ������ */
    for (i = 0; i < GL->numVertexes; i++)
        ltv[i] = etv[GL->numVertexes - 1];    /* ��ʼ�� */

    printf("etv:\t");
    for (i = 0; i < GL->numVertexes; i++)
        printf("%d -> ", etv[i]);
    printf("\n");

    while (top2 != 0)    /* ��ջ����ltv */
    {
        gettop = stack2[top2--];
        for (e = GL->adjList[gettop].firstedge; e; e = e->next)        /* ��������¼�����ٷ���ʱ��ltvֵ */
        {
            k = e->adjvex;
            if (ltv[k] - e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }
    }

    printf("ltv:\t");
    for (i = 0; i < GL->numVertexes; i++)
        printf("%d -> ", ltv[i]);
    printf("\n");

    for (j = 0; j < GL->numVertexes; j++)        /* ��ete,lte�͹ؼ�� */
    {
        for (e = GL->adjList[j].firstedge; e; e = e->next) {
            k = e->adjvex;
            ete = etv[j];        /* ����緢��ʱ�� */
            lte = ltv[k] - e->weight; /* ���ٷ���ʱ�� */
            if (ete == lte)    /* ������ȼ��ڹؼ�·���� */
                printf("<v%d - v%d> length: %d \n", GL->adjList[j].data, GL->adjList[k].data, e->weight);
        }
    }
}


int main(void) {
    MGraph G;
    GraphAdjList GL;
    CreateMGraph(&G);
    CreateALGraph(G, &GL);
    CriticalPath(GL);
    return 0;
}
