#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
#define N 8
using namespace std;

typedef double T;//权值单位

struct HTnode {
	int record;
	T weight;
	HTnode* left, *right, *parent;
};

HTnode* createHTnode(T x,int record) {
	HTnode* tmp = (HTnode*) malloc(sizeof(HTnode));
	tmp->weight = x;
	tmp->record = record;//左0右1
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;
	return tmp;
}

//每次找到队列Q和剩余数组数据中权值最小的两个，
//分别作为左节点和右结点，再为该两节点创建一个父节点，
//然后建立父节点和子节点的关系，再将父节点入队列。
//直到队列Q中的节点数小于等于1且i>=N，循环结束，哈夫曼树建成，返回树根

//再在另一个函数中读取树的相关信息。（record记录该节点是其父节点的左节点或右节点，左0右1根-1）

HTnode* HuffmanEncode(double f[N]) {

	queue<HTnode*> Q;
	//初始化
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
		//队列最小比数组第i个数大
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

	if (tree) {//终止条件(收敛) tree!=NULL
		if (tree->left == NULL) {
			cout << tree->weight << "：";
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