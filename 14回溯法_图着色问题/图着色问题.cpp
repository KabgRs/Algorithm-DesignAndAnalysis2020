#include<iostream>
#define N 100//最大顶点数

using namespace std;

int color[N] = {0};//各顶点颜色数组
int graph[N][N] = {0};//无向图的邻接矩阵
int n, m;//n为定点数，m为着色数
int counts=0;//可行方案总数

bool check(int step) {
	for (int i = 0; i < n; i++) {
		//如果两顶点连通且着色相同，着色不合理
		if (graph[step][i] == 1 && color[step] == color[i]) {
			return false;
		}
	}
	return true;
}

void graphColor(int step) {
	if (step == n) {//存在可行的完整着色方案，打印方案
		for (int i = 0; i < n; i++) {
			cout << color[i] << " ";
		}
		cout << endl;
		counts++;
	}
	else {
		for (int k = 1; k <= m; k++) {
			color[step] = k;//step顶点尝试各种颜色着色
			if (check(step)) {//若改颜色着色可行，进行下一个顶点的着色
				graphColor(step+1);
			}
			//不可行，回溯
			color[step] = 0;
		}
	}
}

int main() {

	/*输入：
		0 1 1 1 0
		1 0 1 1 1
		1 1 0 1 0
		1 1 1 0 1
		0 1 0 1 0*/
	
	cout << "请分别输入定点数n和着色数m：" << endl;
	cin >> n >> m;
	cout << "请输入邻接矩阵：" << endl;
	int row, col, v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	graphColor(0);
	if (counts != 0)
		cout << "可行方案数为：" << counts << endl;
	else
		cout << "No" << endl;
	return 0;
}

