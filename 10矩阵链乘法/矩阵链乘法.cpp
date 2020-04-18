#include<iostream>
#include<cstdlib>
#define N 6//比矩阵数多1

using namespace std;
//m[1][3]表示矩阵1到矩阵3的矩阵链最小乘法运算次数
long long int calculation_m[N][N] = {0};
//记录括号位置
int position_s[N][N] = {0};
//矩阵链信息
long long int P[N] = {10, 5, 20 , 6, 30, 8};

//初始化位置数组
//每种情况下的括号位置在其第一的矩阵
void init(int m[][N]) {
	for (int i = 1; i < N; i++) {//取头不取尾
		for (int j = i + 1; j <= N; j++) {//取尾不取头
			m[i][j] = i;
		}
	}
}

int matrixChain() {
	
	init(position_s);
	//矩阵计数从1开始
	//r为当前问题规模（矩阵链长度）
	for (int r = 2; r <= N-1; r++) {
		//起点范围
		for (int i = 1; i <= N - r; i++) {
			//该起点和规模下对应的终点
			int j = i + r - 1;
			calculation_m[i][j] = calculation_m[i + 1][j] + P[i - 1] * P[i] * P[j];
			//选择最小算法并赋值、记录
			for (int k = i + 1; k <= j - 1; k++) {
				long long int t = calculation_m[i][k] + calculation_m[k + 1][j] + P[i - 1] * P[k] * P[j];
				if (t < calculation_m[i][j]) {
					calculation_m[i][j] = t;
					position_s[i][j] = k;
				}
			}
		}
	}
	return position_s[1][N - 1];
}
//递归打印结果
void printResult(int start,int end) {
	if (start+2 > end) {
		return;
	}
	int mid = position_s[start][end];
	cout << start<<"--"<<end<<":"<<mid<<"   运算次数："<<calculation_m[start][end]<<endl;
	printResult(start, mid);
	printResult(mid+1, end);

}

int main() {
	matrixChain();
	printResult(1, N - 1);
	return 0;
}
