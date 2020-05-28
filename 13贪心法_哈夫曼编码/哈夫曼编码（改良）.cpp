#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
#include<string>
#define N 8
using namespace std;

//ÿ���ҵ�����Q��ʣ������������Ȩֵ��С��������
//�ֱ���Ϊ��ڵ���ҽ�㣬��Ϊ�����ڵ㴴��һ�����ڵ㣬
//Ȼ�������ڵ���ӽڵ�Ĺ�ϵ���ٽ����ڵ�����С�
//ֱ������Q�еĽڵ���С�ڵ���1��i>=N��ѭ�������������������ɣ���������

//������һ�������ж�ȡ���������Ϣ����record��¼�ýڵ����丸�ڵ����ڵ���ҽڵ㣬��0��1��-1��

typedef int T;//Ȩֵ��������

struct HTnode {
	int record;
	T weight;
	HTnode* left, * right, * parent;
};

HTnode* createHTnode(T x, int record) {
	HTnode* tmp = (HTnode*)malloc(sizeof(HTnode));
	tmp->weight = x;
	tmp->record = record;//��0��1
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;
	return tmp;
}

HTnode* HuffmanEncode(T f[N]) {
	
	//��ʼ��������ѡ����������С������Ȩֵ�ֱ���Ϊ���ӽڵ�����ӽڵ㣬
	//��Ϊ���Ǵ������ڵ㣬�����

	//�ö���������������ɵĸ��ڵ�
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

	//��������е�Ԫ�ش���2�������黹û�б����꣬����ѭ��
	while (Q.size() > 1 || i < N) {
		//ͨ�����������ӽڵ������ж�i�ƶ�����
		num = 0;
		//������ȡ���ӽڵ�
		if (i<N && f[i] < Q.front()->weight ) {
			left = createHTnode(f[i], 0);
			num += 1;
			//�Ӷ���ȡ���ӽڵ�
			if (i + 1 < N && Q.size() > 0 && f[i + 1] > Q.front()->weight || i + 1 >= N && Q.size() > 0) {
				right = Q.front();
				right->record = 1;
				Q.pop();
			}
			else {//������ȡ���ӽڵ�
				right = createHTnode(f[i + 1], 1);
				num += 1;
			}
		}
		else {//�Ӷ���ȡ���ӽڵ�
			left = Q.front();
			left->record = 0;
			Q.pop();
			//�Ӷ���ȡ���ӽڵ�
			if (i < N && Q.size() > 0 && f[i] > Q.front()->weight || i >= N && Q.size() > 0) {
				right = Q.front();
				right->record = 1;
				Q.pop();
			}
			else {//������ȡ���ӽڵ�
				right = createHTnode(f[i], 1);
				num += 1;
			}
		}
		
		//Ϊ�����ӽڵ㴴�����ڵ㲢�����
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

//���������õ�������������
void preOrderHTree(HTnode* tree) {

	if (tree) {//��ֹ����(����) tree!=NULL
		if (tree->left == NULL) {
			cout << tree->weight << "��";
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
	//��������
	qsort(f, N, sizeof(T), cmp);
	/*for (int i = 0; i < N; i++) {
		cout << f[i] << " ";
	}*/
	HuffmanDecode(HuffmanEncode(f));
}
