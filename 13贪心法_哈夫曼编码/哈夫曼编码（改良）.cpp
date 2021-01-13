#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
#include<string>
#define N 8
using namespace std;

//每次找到队列Q和剩余数组数据中权值最小的两个，
//分别作为左节点和右结点，再为该两节点创建一个父节点，
//然后建立父节点和子节点的关系，再将父节点入队列。
//直到队列Q中的节点数小于等于1且i>=N，循环结束，哈夫曼树建成，返回树根

//再在另一个函数中读取树的相关信息。（record记录该节点是其父节点的左节点或右节点，左0右1根-1）

typedef int T;//权值数据类型

struct HTnode {
	int record;
	T weight;
	HTnode* left, * right, * parent;
};

HTnode* createHTnode(T x, int record) {
	HTnode* tmp = (HTnode*)malloc(sizeof(HTnode));
	tmp->weight = x;
	tmp->record = record;//左0右1
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;
	return tmp;
}

HTnode* HuffmanEncode(T f[N]) {
	
	//初始化，首先选择数组中最小的两个权值分别作为左子节点和右子节点，
	//并为它们创建父节点，入队列

	//该队列用来存放新生成的父节点
	queue<HTnode*> Q;
	HTnode* root = createHTnode(f[0] + f[1], -1);
	HTnode* left = createHTnode(f[0], 0);
	HTnode* right = createHTnode(f[1], 1);
	left->parent = root;
	right->parent = root;
	root->left = left;
	root->right = right;
	Q.push(root);

	int num = 0, i = 2;

	//如果队列中的元素大于2或者数组还没有遍历完，继续循环
	while (Q.size() > 1 || i < N) {
		//通过下面左右子节点类型判断i移动数量
		num = 0;
		//从数组取左子节点
		if (i<N && f[i] < Q.front()->weight ) {
			left = createHTnode(f[i], 0);
			num += 1;
			//从队列取右子节点
			if (i + 1 < N && Q.size() > 0 && f[i + 1] > Q.front()->weight || i + 1 >= N && Q.size() > 0) {
				right = Q.front();
				right->record = 1;
				Q.pop();
			}
			else {//从数组取右子节点
				right = createHTnode(f[i + 1], 1);
				num += 1;
			}
		}
		else {//从队列取左子节点
			left = Q.front();
			left->record = 0;
			Q.pop();
			//从队列取右子节点
			if (i < N && Q.size() > 0 && f[i] > Q.front()->weight || i >= N && Q.size() > 0) {
				right = Q.front();
				right->record = 1;
				Q.pop();
			}
			else {//从数组取右子节点
				right = createHTnode(f[i], 1);
				num += 1;
			}
		}
		
		//为左右子节点创建父节点并入队列
		root = createHTnode(left->weight + right->weight, -1);
		left->parent = root;
		right->parent = root;
		root->left = left;
		root->right = right;
		Q.push(root);

		i += num;
	}
	return Q.front();
}

//先序搜索得到各哈夫曼编码
void preOrderHTree(HTnode* tree) {

	if (tree) {//终止条件(收敛) tree!=NULL
		if (tree->left == NULL) {
			cout << tree->weight << "：";
			HTnode* tmp = tree;
			string s = "";
			while (tmp) {
				if (tmp->record != -1) {
				//cout << tmp->record;
					s.append(to_string(tmp->record));
				}
				tmp = tmp->parent;
			}
			free(tmp);
			reverse(s.begin(), s.end());
			cout << s << endl;
		}
		preOrderHTree(tree->left);
		preOrderHTree(tree->right);
	}
}

void HuffmanDecode(HTnode* t) {
	preOrderHTree(t);
}

int cmp(const void* a, const void* b){ 
	return (*(T*)a - *(T*)b);
}
int main() {
	T f[N] = { 10,5,5,10,10,15,20,25 };
	//快排排序
	qsort(f, N, sizeof(T), cmp);
	/*for (int i = 0; i < N; i++) {
		cout << f[i] << " ";
	}*/
	HuffmanDecode(HuffmanEncode(f));
}
