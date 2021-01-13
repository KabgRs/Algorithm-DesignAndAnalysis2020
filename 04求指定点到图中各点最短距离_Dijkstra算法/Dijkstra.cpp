#include <iostream>
#include<vector>
#define INIT 65535
#define N 8

using namespace std;

typedef char printType;
printType vertexValue[N] = { 'a','b','c','d','e','f','g','h' };

unsigned int*  Dijkstra(int u, unsigned int mat[][N]) {	//��uΪ��ʼ��

	
	unsigned int min,temp,visited[N] = { 0 };	//��¼�õ��Ƿ�ȷ����0δȷ����1ȷ��
	unsigned int* dis = (unsigned int*)malloc(sizeof(unsigned int) * N);
	visited[u] = 1;
	for (int i = 0; i < N; i++) {
		dis[i] = mat[u][i];					//��ʼ�����u�����·������
	}	

	for (int k = 1; k < N; k++) {		//ѭ��N-1��
		min = INIT; temp = 0;
		for (int i = 0; i < N; i++) {
			if (dis[i] < min && dis[i] != 0 && visited[i] == 0) {	//�ҵ�������������С����ĵ����
				min = dis[i];
				temp = i;
			}
		}
		visited[temp] = 1;				//ÿ��ѡ�������С��δ��ȷ�����ĵ����

		//�ɳ�
		for (int i = 0; i < N; i++) {	//������tempΪ��ת�����̾���
			if (dis[i]>dis[temp]+mat[temp][i]&&visited[i]==0) {
				dis[i] = dis[temp] + mat[temp][i];
			}
		}
	}
	return dis;
}

void printPath(int u,unsigned int dis[],printType a[]) {			//��ӡ����ʼ��u��ͼ�и������̾���

	for (int i = 0; i < N; i++) {
		cout << a[u] << "-->" << a[i] << ": " << dis[i] << endl;
	}

}

int main() {

	unsigned int mat[][N] = {
		{0,		1,		INIT,	INIT,	INIT,	INIT,	INIT,	INIT},
		{INIT,	0,		INIT,	2,		INIT,	INIT,	INIT,	INIT},
		{2,		INIT,	0,		INIT,	INIT,	INIT,	INIT,	INIT},
		{INIT,	INIT,	1,		0,		INIT,	8,		INIT,	INIT},
		{INIT,	INIT,	INIT,	2,		0,		INIT,	2,		INIT},
		{INIT,	INIT,	INIT,	INIT,	2,		0,		INIT,	INIT},
		{INIT,	INIT,	INIT,	INIT,	INIT,	3,		0,		3	},
		{INIT,	INIT,	INIT,	INIT,	INIT,	2,		INIT,	0	},
	};
	int srcVertex;//��ʼ����
	cout << "��������ʼ���㣨0~7����" << endl;
	cin >> srcVertex;
	printPath(srcVertex, Dijkstra(srcVertex, mat), vertexValue);

	return 0;
}