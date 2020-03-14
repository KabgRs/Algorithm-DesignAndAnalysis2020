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
		if (n->key == x) return n->index + 1;//输出下标从1开始
		else if (n->key < x) n = n->right;
		else n = n->left;
	}
	return 0;
}

int main() {

	int guess;
	//对应升序数组按树的先序遍历的顺序逐一给节点赋值，这里做简化，手动建树：1~15
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
	
	cout << "请输入查找数：" << endl;
	cin >> guess;
	cout << "注：0表示不存在，数组下标从1开始。" << endl;
	cout << "嘀，二叉查找树检索！下标索引为：";
	printf("%d",findBtree(r,guess));
}
