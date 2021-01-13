#include<iostream>
#include<cstdlib>

using namespace std;

typedef int T;

struct node {
	T key;
	int index;
	node* left, * right;
};

node* createNode(T key, int index) {
	node* n = (node*)malloc(sizeof(node));
	n->key = key;
	n->index = index;
	n->left = NULL;
	n->right = NULL;
	return n;
}

T findBtree(node* root, int x) {
	node* n = (node*)malloc(sizeof(node));
	n = root;
	while (n) {
		if (n->key == x) return n->index + 1;//����±��1��ʼ
		else if (n->key < x) n = n->right;
		else n = n->left;
	}
	return 0;
}

int main() {

	int guess;
	//��Ӧ�������鰴�������������˳����һ���ڵ㸳ֵ���������򻯣��ֶ�������1~15
	node* r = createNode(8, 7);
	r->left = createNode(4,3);
	r->right = createNode(12, 11);
	r->left->left = createNode(2, 1);
	r->left->right = createNode(6, 5);
	r->left->left->left = createNode(1, 0);
	r->left->left->right = createNode(3, 2);
	r->left->right->left = createNode(5, 4);
	r->left->right->right = createNode(7, 6);
	r->right->left = createNode(10, 9);
	r->right->right = createNode(14, 13);
	r->right->left->left = createNode(9, 8);
	r->right->left ->right= createNode(11, 10);
	r->right->right->left = createNode(13, 12);
	r->right->right->right = createNode(15, 14);
	
	cout << "�������������" << endl;
	cin >> guess;
	cout << "ע��0��ʾ�����ڣ������±��1��ʼ��" << endl;
	cout << "�֣�����������������±�����Ϊ��";
	printf("%d",findBtree(r,guess));
}
