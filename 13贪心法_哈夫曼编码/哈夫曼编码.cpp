#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
#define N 8
using namespace std;

typedef double T;//Ȩֵ��λ

struct HTnode {
	int record;
	T weight;
	HTnode* left, *right, *parent;
};

HTnode* createHTnode(T x,int record) {
	HTnode* tmp = (HTnode*) malloc(sizeof(HTnode));
	tmp->weight = x;
	tmp->record = record;//��0��1
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;
	return tmp;
}

//ÿ���ҵ�����Q��ʣ������������Ȩֵ��С��������
//�ֱ���Ϊ��ڵ���ҽ�㣬��Ϊ�����ڵ㴴��һ�����ڵ㣬
//Ȼ�������ڵ���ӽڵ�Ĺ�ϵ���ٽ����ڵ�����С�
//ֱ������Q�еĽڵ���С�ڵ���1��i>=N��ѭ�������������������ɣ���������

//������һ�������ж�ȡ���������Ϣ����record��¼�ýڵ����丸�ڵ����ڵ���ҽڵ㣬��0��1��-1��

HTnode* HuffmanEncode(double f[N]) {

	queue<HTnode*> Q;
	//��ʼ��
	HTnode* root = createHTnode(f[0] + f[1],-1);
	HTnode* left = createHTnode(f[0], 0);
	HTnode* right = createHTnode(f[1], 1);
	left->parent = root;
	right->parent = root;
	root->left = left;
	root->right = right;
	
	//cout << root->weight << endl;
	Q.push(root);
	int num = 1, i = 2;
	while (Q.size() > 1 || i < N) {
		num = 1;
		//������С�������i������
		if (f[i] < Q.front()->weight) {
			left = createHTnode(f[i],0);
			if (f[i + 1] < Q.front()->weight && i + 1 < N) {
				right = createHTnode(f[i + 1],1);
				num += 1;
			}
			else {
				right = Q.front();
				right->record = 1;
				Q.pop();
			}
		}
		else {
			left = Q.front();
			left->record = 0;
			Q.pop();
			if (Q.size() > 0 && Q.front()->weight < f[i]) {
				right = Q.front();
				right->record = 1;
				Q.pop();
			}
			else {
				right = createHTnode(f[i],1);
			}
		}
		root = createHTnode(left->weight + right->weight,-1);
		left->parent = root;
		right->parent = root;
		root->left = left;
		root->right = right;
		
		Q.push(root);
		i += num;
	}
	//preOrderHTree(Q.front());
	return Q.front();
	//return root;
}


//void preOrderHTree(HTnode* tree) {
//	cout << tree->weight;
//}

void preOrderHTree(HTnode* tree) {

	if (tree) {//��ֹ����(����) tree!=NULL
		if (tree->left == NULL) {
			cout << tree->weight << "��";
			HTnode* tmp = tree;
			while (tmp) {
				//if (tmp->record != -1) {
				cout << tmp->record;
				//}
				tmp = tmp->parent;
			}
			free(tmp);
			cout << endl;
		}
		preOrderHTree(tree->left);
		preOrderHTree(tree->right);
	}
}

void HuffmanDecode(HTnode* t) {
	preOrderHTree(t);
}

int main() {
	T f[N+1] = { 5,5,10,10,10,15,20,25,1000 };
	HuffmanDecode(HuffmanEncode(f));
	//HuffmanEncode(f);
}