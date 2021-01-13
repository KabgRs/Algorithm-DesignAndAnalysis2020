#pragma once
#include<stdlib.h>
#include<stack>
using namespace std;
///////////////////////////////////////////////////////˳�򣺾��󣨷���Ч�ʸߣ�ɾ������ �� ����ά����Ч�ʵ��£�һά����ӳ�䣩��һά���鷽���Ч

//���ھ����ͼ�����㷨
typedef char E;

typedef struct {

	int length;
	int* A;			//���飬�ڽӾ���
	E* data;		//ÿ�������Ӧ������

}SGraph;

SGraph CreateSGraph(int* matrix, E* data, int n) {

	SGraph G;
	G.length = n;
	G.A = matrix;//�ڽӾ���
	G.data = data;//��Ӧ����
	return G;

}

E GetNode(SGraph G, int i) {

	return G.data[i];
}

int Getmatrix(SGraph G, int i, int j) {

	return G.A[i * G.length + j];
}

void OP(E e);

void BFS(SGraph g, int i) {//ͼ�Ĺ�ȱ���

	int j, k;
	stack<int> S;
	int* visited = (int*)malloc(sizeof(int) * g.length);//�ѷ��ʹ�
	for (int i = 0; i < g.length; i++) {				//��ʼ��0
		visited[i] = 0;
	}
	S.push(i);	//i��ջ
	visited[i] = 1;//�ѱ�����i�����㣬��1
	while (S.size() > 0) {//ջ�ǿ�
		i = S.top();//�õ�ջ��Ԫ��
		S.pop();//��ջ
		OP(g.data[i]);//��ӡ
		for (j = 0; j < g.length; j++) {//����i���������,ֻҪ����һ��û��ǹ�������ջ������ѭ��
			if (Getmatrix(g, i, j) == 1 && !visited[j]) {
				k = j;
				S.push(k);
				visited[k] = 1;
				break;
			}
		}
	}
}

void DFS(SGraph g, int i) {//ͼ����ȱ���

	int j, k;
	stack<int> S;
	int* visited = (int*)malloc(sizeof(int) * g.length);//�ѷ��ʹ�
	for (int i = 0; i < g.length; i++) {				//��ʼ��0
		visited[i] = 0;
	}
	S.push(i);	//i��ջ
	visited[i] = 1;//�ѱ�����i�����㣬��1
	while (S.size() > 0) {//ջ�ǿ�
		i = S.top();//�õ�ջ��Ԫ��
		S.pop();//��ջ
		OP(g.data[i]);//��ӡ
		for (j = 0; j < g.length; j++) {//����i���������
			if (Getmatrix(g, i, j) == 1) {
				k = j;
				if (!visited[k]) {//����ǰû�б�����j����ջ��1
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

int* Connect(SGraph g) {//����ͼ�Ŀɴ��Ծ���
	//int* C = g.A;//�����ԭ����ı���
	int* C = copyMatrix(g);//����һ��
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
