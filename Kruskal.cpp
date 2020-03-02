#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INIT 65535   
#define VData unsigned int  //顶点数据
#define VSize 6  //顶点数量

char value[] = { 'A', 'B', 'C', 'D', 'E', 'F' };//顶点值

typedef struct
{
	VData u;
	VData v;
	unsigned int cost;  //边的权值

}Edge;  //原始图的边信息

void ReadEdge(unsigned int  mat[][VSize], vector<Edge> &valueEdge) {//读取图的边权值信息加入到valueEdge

	Edge* temp = NULL;
	for (unsigned int i = 0; i < VSize; i++){//无向图读一半

		for (unsigned int j = 0; j < i; j++){

			if (mat[i][j] != INIT){				//顶点i与顶点j连通

				temp = (Edge*)malloc(sizeof(Edge));
				temp->u = i;
				temp->v = j;
				temp->cost = mat[i][j];
				valueEdge.push_back(*temp);		//将该边的全部信息添加到保存边权值的动态数组valueEdge

			}
		}
	}
}



int judgeTree(VData u, VData v, vector<vector<VData>> &Tree){	//判断u,v两个顶点是否在同一棵树内。

	unsigned int temp_u = INIT;
	unsigned int temp_v = INIT;
	for (unsigned int i = 0; i < Tree.size(); i++){//检查u,v分别属于哪颗树

		if (find(Tree[i].begin(), Tree[i].end(), u) != Tree[i].end())
			temp_u = i;
		if (find(Tree[i].begin(), Tree[i].end(), v) != Tree[i].end())
			temp_v = i;
	}

	if (temp_u != temp_v){   //若u,v没有在同一颗树上，合并两颗树,返回值1
		for (unsigned int i = 0; i < Tree[temp_v].size(); i++)
		{
			Tree[temp_u].push_back(Tree[temp_v][i]);
		}
		Tree[temp_v].clear();
		return 1;
	}
	return 0;				//u,v在同一颗树上，返回值0
}

int cmp(Edge  A, Edge  B) {	//用于排序函数

	if (A.cost < B.cost) return 1;
	else return 0;
}

int Kruskal(unsigned int mat[][VSize]){

	vector<Edge> valueEdge;
	int sumCost = 0;			//总权值
	ReadEdge(mat, valueEdge);	//读取邻接矩阵的边信息
	sort(valueEdge.begin(), valueEdge.end(), cmp);//将读取到的边根据权值将边从小到大排序

	vector<vector<VData> > Tree(VSize); //6棵独立树
	for (unsigned int i = 0; i < VSize; i++){

		Tree[i].push_back(i);  //初始化6棵独立树的信息
	}
	//依次从小到大取最小代价边
	for (unsigned int i = 0; i < valueEdge.size(); i++){

		VData u = valueEdge[i].u;
		VData v = valueEdge[i].v;

		//若此边的两个顶点不在一颗树内（不成环）
		if (judgeTree(u, v, Tree)){

			cout << value[u] << "---" << value[v] << endl;	//把此边加入到最小生成树中
			sumCost += mat[u][v];							//累加权值
		}
	}
	return sumCost;
}

int main()
{
	unsigned int m[][VSize] = {
	{	INIT,	10,		3,		20,		INIT,	INIT},
	{	10,		INIT,	INIT,	INIT,	9,		5},
	{	3,		INIT,	INIT,	INIT,	INIT,	11},
	{	20,		INIT,	INIT,	INIT,	INIT,	14},
	{	INIT,	9,		INIT,	INIT,	INIT,	8},
	{	INIT,	5,		11,		14,		8,		INIT},
			};

	cout  << "Kruskal:" << endl;
	cout<<endl<<"最小生成树权值为："<<Kruskal(m)<<endl;
	return 0;
}

//参考链接：https ://blog.csdn.net/luoshixian099/article/details/51908175