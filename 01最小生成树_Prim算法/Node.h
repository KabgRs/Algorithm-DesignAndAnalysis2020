#pragma once
#include"SGraph.h"

#define MAXSIZE 7
#define INIT 65535


struct NodePoint {

	int data;
	int lowestvalue;

}node[MAXSIZE];


int Getmin(NodePoint* n) {

	int i, min = 65535, k = -1;
	for (i = 0; i < MAXSIZE; i++) {
		if (n[i].lowestvalue < min && n[i].lowestvalue != 0) {
			min = n[i].lowestvalue;
			k = i;
		}
	}
	return k;
}

void Prim(SGraph g, int s) {

	for (int i = 0; i < MAXSIZE; i++)
		node[i].lowestvalue = INIT;//初始化边权值
	//从顶点s开始
	node[s].data = s;
	int sumValue=0;
	node[s].lowestvalue = 0;//置0，顶点s入生成树
	
	for (int i = 0; i < MAXSIZE;i++) {//点s到其他点的边权值
		if (i != s) {
			node[i].lowestvalue = g.A[s * MAXSIZE + i];
			node[i].data = s;
		}
	}

	for (int j = 1; j < MAXSIZE; j++) {//每一次加一条边，直至 MAXSIZE-1条边

		int k = Getmin(node);
		printf("%c--%c\n", g.data[node[k].data],g.data[k]);
		sumValue += node[k].lowestvalue;
		node[k].lowestvalue = 0;

		for (int m = 0; m < MAXSIZE; m++) {
			if (node[m].lowestvalue > g.A[k * MAXSIZE + m]) {
				node[m].lowestvalue = g.A[k * MAXSIZE + m];
				node[m].data = k;
			}
		}
	}

	printf("最小生成树权值：%d\n", sumValue);

}


