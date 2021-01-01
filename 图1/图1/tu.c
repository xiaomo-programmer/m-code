#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#define max 30
#define infinity 32768


typedef char VertexData;
typedef struct
{
	VertexData vertex[max];
	int arcs[max][max];
	int vexnum, arcnum;

}AdjMatrix;


int locatevertex(AdjMatrix *G, int v)
{
	int j = -1, k;
	for (k = 0; k<G->vexnum; k++)
	if (G->vertex[k] == v)
	{
		j = k;
		break;
	}

	return(j);
}


int creatUDG(AdjMatrix *G)
{
	int i, j, k;
	VertexData v1, v2;
	printf("请输入顶点个数和弧数：");
	scanf("%d,%d", &(G->vexnum), &(G->arcnum));
	for (i = 0; i < G->vexnum; i++)
	for (j = 0; j<G->vexnum; j++)
		G->arcs[i][j] = 0;
	for (i = 0; i<G->vexnum; i++)
	{
		printf("请输入顶点数据\n");
		scanf("%c", &G->vertex[i]);
	}
	for (k = 0; k < G->arcnum; k++)
	{
		printf("请输入顶点v1,v2");
		scanf("%c,%c", &v1,&v2);
		
		
		i = locatevertex(G, v1);
		j = locatevertex(G, v2);
		G->arcs[i][j] = 1;
	}
	return 0;
	

}

	int visited[max];





	void DepthFirstSearch(AdjMatrix *G, int  v0)
	{
		
		int vj;
		visited[v0] = 1;
		printf("%c\n", G->vertex[v0]);
	

		for (vj = 0; vj < G->vexnum; vj++)

		if (!visited[vj] && G->arcs[v0][vj] == 1)
			DepthFirstSearch(G, vj);
	}
	void TraverseDFS(AdjMatrix *G)
	{
		int vi;
		for (vi = 0; vi < G->vexnum; vi++)
			visited[vi] = 0;
		for (vi = 0; vi < G->vexnum; vi++)
		{
			if (!visited[vi])
				DepthFirstSearch(G, vi);
		}
	}

	int main()
	{
		AdjMatrix *G ;
		G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
		creatUDG(&G);
		printf("深度优先遍历为：");
		TraverseDFS(G);
		system("pause");
		return 0;
	}














//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//#define maxsize 20
//#define infinity 10000
//	int visited[maxsize];
//
//
//
//	typedef struct
//	{
//		int vertex[maxsize];
//		int arcs[maxsize][maxsize];
//		int vexnum, arcnum;
//
//	}adjmatrix;
//
//	int locate_vertex(adjmatrix *g, int v)
//	{
//		int j = -1, k;
//		for (k = 0; k<g->vexnum; k++)
//		if (g->vertex[k] == v)
//		{
//			j = k;
//			break;
//		}
//
//		return(j);
//	}
//
//	int greatedn(adjmatrix *g)
//	{
//		int i, j, k, v1, v2;
//		printf("输入顶点个数");
//		scanf("%d", &g->vexnum);
//		printf("输入弧的个数");
//		scanf("%d", &g->arcnum);
//		for (i = 0; i<g->vexnum; i++)
//		for (j = 0; j<g->vexnum; j++)
//			g->arcs[i][j] = 0;
//		for (i = 0; i<g->vexnum; i++)
//		{
//			printf("请输入顶点数据\n");
//			scanf("%d", &g->vertex[i]);
//		}
//		for (k = 0; k<g->arcnum; k++)
//		{
//			printf("请输入顶点v1");
//			scanf("%d", &v1);
//			printf("请输入顶点v2");
//			scanf("%d", &v2);
//			i = locate_vertex(g, v1);
//			j = locate_vertex(g, v2);
//			g->arcs[i][j] = 1;
//		}
//		return 0;
//	}
//	void depthfirstsearch(adjmatrix g, int i)
//	{
//		int j;
//		visited[i] = 1;
//		printf("%d\n", g.vertex[i]);
//		for (j = 0; j<g.vexnum; j++)
//		if (!visited[j] && g.arcs[i][j] == 1)
//			depthfirstsearch(g, j);
//	}
//	void traversegraph(adjmatrix g)
//	{
//		int i;
//		for (i = 0; i<g.vexnum; i++)
//			visited[i] = 0;
//		for (i = 0; i<g.vexnum; i++)
//		{
//			if (!visited[i])
//				depthfirstsearch(g, i);
//		}
//	}
//
//	void main()
//	{
//		adjmatrix g;
//		greatedn(&g);
//		traversegraph(g);
//		system("pause");
//		return 0;
//	}
//