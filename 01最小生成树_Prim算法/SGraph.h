#pragma once
#include<stdlib.h>
#include<stack>
using namespace std;
///////////////////////////////////////////////////////顺序：矩阵（访问效率高，删减不便 ） ，二维数组效率低下（一维数组映射），一维数组方便高效

//基于矩阵的图遍历算法
typedef char E;

typedef struct {

	int length;
	int* A;			//数组，邻接矩阵
	E* data;		//每个顶点对应的数据

}SGraph;

SGraph CreateSGraph(int* matrix, E* data, int n) {

	SGraph G;
	G.length = n;
	G.A = matrix;//邻接矩阵
	G.data = data;//对应数据
	return G;

}

E GetNode(SGraph G, int i) {

	return G.data[i];
}

int Getmatrix(SGraph G, int i, int j) {

	return G.A[i * G.length + j];
}

void OP(E e);

void BFS(SGraph g, int i) {//图的广度遍历

	int j, k;
	stack<int> S;
	int* visited = (int*)malloc(sizeof(int) * g.length);//已访问过
	for (int i = 0; i < g.length; i++) {				//初始化0
		visited[i] = 0;
	}
	S.push(i);	//i入栈
	visited[i] = 1;//已遍历第i个顶点，置1
	while (S.size() > 0) {//栈非空
		i = S.top();//得到栈顶元素
		S.pop();//出栈
		OP(g.data[i]);//打印
		for (j = 0; j < g.length; j++) {//遍历i顶点的数组,只要碰到一个没标记过的则入栈并跳出循环
			if (Getmatrix(g, i, j) == 1 && !visited[j]) {
				k = j;
				S.push(k);
				visited[k] = 1;
				break;
			}
		}
	}
}

void DFS(SGraph g, int i) {//图的深度遍历

	int j, k;
	stack<int> S;
	int* visited = (int*)malloc(sizeof(int) * g.length);//已访问过
	for (int i = 0; i < g.length; i++) {				//初始化0
		visited[i] = 0;
	}
	S.push(i);	//i入栈
	visited[i] = 1;//已遍历第i个顶点，置1
	while (S.size() > 0) {//栈非空
		i = S.top();//得到栈顶元素
		S.pop();//出栈
		OP(g.data[i]);//打印
		for (j = 0; j < g.length; j++) {//遍历i顶点的数组
			if (Getmatrix(g, i, j) == 1) {
				k = j;
				if (!visited[k]) {//若先前没有遍历过j，入栈置1
					S.push(k);
					visited[k] = 1;
				}
			}
		}
	}
}

int* copyMatrix(SGraph g) {
	int* C=(int*)malloc(sizeof(int)*g.length);
	for (int i = 0; i < g.length; i++) {
		for (int j = 0; j < g.length; j++)
			C[g.length * i + j] = g.A[g.length * i + j];

	}
	return C;
}

int* Connect(SGraph g) {//计算图的可达性矩阵
	//int* C = g.A;//这里把原矩阵改变了
	int* C = copyMatrix(g);//复制一个
	for (int k = 0; k < g.length; k++)
		for (int i = 0; i < g.length; i++)
			for (int j = 0; j < g.length; j++)
				C[i * g.length + j] |= (C[i * g.length + k] & C[k * g.length + j]);
	return C;
}

void PrintMatrix(SGraph G, int* A)
{
	for (int i = 0; i < G.length; i++) {
		for (int j = 0; j < G.length; j++)
			printf("%d ", A[G.length * i + j]);
		printf("\n");
	}
}
