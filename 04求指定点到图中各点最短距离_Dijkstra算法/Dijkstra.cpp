#include <iostream>
#include<vector>
#define INIT 65535
#define N 8

using namespace std;

typedef char printType;
printType vertexValue[N] = { 'a','b','c','d','e','f','g','h' };

unsigned int*  Dijkstra(int u, unsigned int mat[][N]) {	//点u为起始点

	
	unsigned int min,temp,visited[N] = { 0 };	//记录该点是否确定，0未确定，1确定
	unsigned int* dis = (unsigned int*)malloc(sizeof(unsigned int) * N);
	visited[u] = 1;
	for (int i = 0; i < N; i++) {
		dis[i] = mat[u][i];					//初始化起点u的最短路径数组
	}	

	for (int k = 1; k < N; k++) {		//循环N-1次
		min = INIT; temp = 0;
		for (int i = 0; i < N; i++) {
			if (dis[i] < min && dis[i] != 0 && visited[i] == 0) {	//找到满足条件的最小距离的点加入
				min = dis[i];
				temp = i;
			}
		}
		visited[temp] = 1;				//每次选择距离最小且未被确定过的点加入

		//松弛
		for (int i = 0; i < N; i++) {	//更新以temp为中转点的最短距离
			if (dis[i]>dis[temp]+mat[temp][i]&&visited[i]==0) {
				dis[i] = dis[temp] + mat[temp][i];
			}
		}
	}
	return dis;
}

void printPath(int u,unsigned int dis[],printType a[]) {			//打印从起始点u到图中各点的最短距离

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
	int srcVertex;//起始顶点
	cout << "请输入起始顶点（0~7）：" << endl;
	cin >> srcVertex;
	printPath(srcVertex, Dijkstra(srcVertex, mat), vertexValue);

	return 0;
}