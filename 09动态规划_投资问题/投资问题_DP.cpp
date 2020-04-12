#include<iostream>
#define N 5//项目数
#define M 6//投资总额

using namespace std;

//Aitem[3][2]表示共投资2万元第3个项目的投资金额，用于追溯路径
double aItem[N][M] = {0};
//Fsum[3][2]表示前3个项目共投资2万元的最大收益
double Fsum[N][M] = { 0 };

double investMax(double f[N][M]) {
		
	//前1个项目的情况
	for (int i = 0; i <= M-1; i++) {
		Fsum[1][i] = f[1][i];
		aItem[1][i] = i;
	}
	//第k个项目
	for (int k = 2; k <= N-1; k++) {
		//k个项目共分配m万元
		for (int m = 1; m <= M-1; m++) {
			double max = -1,temp=0;
			//第k个项目分配a万元
			for (int a = 0; a <= m; a++) {
				if (f[k][a] + Fsum[k-1][m - a] > max) {
					max = f[k][a] + Fsum[k-1][m - a];
					temp =  a;
				}
			}
			Fsum[k][m] = max;
			aItem[k][m] = temp;
		}
	}

	return Fsum[N-1][M-1];
}

void printInfo() {
	int index = M - 1;
	for (int i = N - 1; i > 0; i--) {
		cout << "第" << i << "个项目，投资" << aItem[i][index] << "万元" << endl;
		index -= aItem[i][index];
	}
}

int main() {

	double f[N][M] = {//f[1][2]表示投第1个项目2万元所产生的效益
		{0, 0, 0, 0, 0, 0},
		{0,11,12,13,14,15},
		{0, 0, 5,10,15,20},
		{0, 2,10,30,32,40},
		{0,20,21,22,23,24}
	};
	cout << M-1 <<"万元投资"<<N-1<<"项目最大收益为：" << investMax(f) << endl;
	printInfo();
	return 0;
}
