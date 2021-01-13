#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INIT 65535   
#define VData unsigned int  //��������
#define VSize 6  //��������

char value[] = { 'A', 'B', 'C', 'D', 'E', 'F' };//����ֵ

typedef struct
{
	VData u;
	VData v;
	unsigned int cost;  //�ߵ�Ȩֵ

}Edge;  //ԭʼͼ�ı���Ϣ

void ReadEdge(unsigned int  mat[][VSize], vector<Edge> &valueEdge) {//��ȡͼ�ı�Ȩֵ��Ϣ���뵽valueEdge

	Edge* temp = NULL;
	for (unsigned int i = 0; i < VSize; i++){//����ͼ��һ��

		for (unsigned int j = 0; j < i; j++){

			if (mat[i][j] != INIT){				//����i�붥��j��ͨ

				temp = (Edge*)malloc(sizeof(Edge));
				temp->u = i;
				temp->v = j;
				temp->cost = mat[i][j];
				valueEdge.push_back(*temp);		//���ñߵ�ȫ����Ϣ��ӵ������Ȩֵ�Ķ�̬����valueEdge

			}
		}
	}
}



int judgeTree(VData u, VData v, vector<vector<VData>> &Tree){	//�ж�u,v���������Ƿ���ͬһ�����ڡ�

	unsigned int temp_u = INIT;
	unsigned int temp_v = INIT;
	for (unsigned int i = 0; i < Tree.size(); i++){//���u,v�ֱ������Ŀ���

		if (find(Tree[i].begin(), Tree[i].end(), u) != Tree[i].end())
			temp_u = i;
		if (find(Tree[i].begin(), Tree[i].end(), v) != Tree[i].end())
			temp_v = i;
	}

	if (temp_u != temp_v){   //��u,vû����ͬһ�����ϣ��ϲ�������,����ֵ1
		for (unsigned int i = 0; i < Tree[temp_v].size(); i++)
		{
			Tree[temp_u].push_back(Tree[temp_v][i]);
		}
		Tree[temp_v].clear();
		return 1;
	}
	return 0;				//u,v��ͬһ�����ϣ�����ֵ0
}

int cmp(Edge  A, Edge  B) {	//����������

	if (A.cost < B.cost) return 1;
	else return 0;
}

int Kruskal(unsigned int mat[][VSize]){

	vector<Edge> valueEdge;
	int sumCost = 0;			//��Ȩֵ
	ReadEdge(mat, valueEdge);	//��ȡ�ڽӾ���ı���Ϣ
	sort(valueEdge.begin(), valueEdge.end(), cmp);//����ȡ���ı߸���Ȩֵ���ߴ�С��������

	vector<vector<VData> > Tree(VSize); //6�ö�����
	for (unsigned int i = 0; i < VSize; i++){

		Tree[i].push_back(i);  //��ʼ��6�ö���������Ϣ
	}
	//���δ�С����ȡ��С���۱�
	for (unsigned int i = 0; i < valueEdge.size(); i++){

		VData u = valueEdge[i].u;
		VData v = valueEdge[i].v;

		//���˱ߵ��������㲻��һ�����ڣ����ɻ���
		if (judgeTree(u, v, Tree)){

			cout << value[u] << "---" << value[v] << endl;	//�Ѵ˱߼��뵽��С��������
			sumCost += mat[u][v];							//�ۼ�Ȩֵ
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
	cout<<endl<<"��С������ȨֵΪ��"<<Kruskal(m)<<endl;
	return 0;
}

//�ο����ӣ�https ://blog.csdn.net/luoshixian099/article/details/51908175