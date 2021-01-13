#include<iostream>
#include<cstdlib>
#include<stack>

#define N 7//N=序列X的长度+2
#define M 8//M=序列Y的长度+2

using namespace std;

char sequence_X[N] = "ABBDA";//X序列
char sequence_Y[M] = "BCCDAC";//Y序列

//C[1][2]表示X长度为1、Y长度为2时两者最长公共子序列长度
int length_C[N][M] = { 0 };

//三个结果：1表示删除x，2表示y，3表示两者都删
//B[1][2]=1 表示X长度为1、Y长度为2时得到两者最长公共子序列长度，
//要从前一步从右往左删除一个x元素
int info_B[N][M] = { 0 };

//栈，保存最长公共子序列元素，以便正向输出
stack<char> sequence_R;

//最长公共子序列长度算法
void LCS() {

	for (int i = 1; i < N-1; i++) {
		for (int j = 1; j < M-1; j++) {
			//字符相同
			if (sequence_X[i-1] == sequence_Y[j-1]) {
				//都删
				length_C[i][j] = length_C[i - 1][j - 1] + 1;
				info_B[i][j] = 3;
			}
			//字符不同
			else {
				if (length_C[i][j - 1] > length_C[i - 1][j]) {
					//删Y
					length_C[i][j] = length_C[i][j - 1];
					info_B[i][j] = 2;
				}
				else {
					//删X
					length_C[i][j] = length_C[i - 1][j];
					info_B[i][j] = 1;
				}
			}
		}
	}

}

//元素保存到栈
void collectInfo(int start,int end) {
	if (start == 0 || end == 0) {
		return;
	}
	//都删，X和Y各减一
	if (info_B[start][end] == 3) {
		//cout << sequence_X[start - 1]<<" ";
		//按子序列从后往前输出，先将输出结果保存在栈sequence_R中
		sequence_R.push(sequence_X[start - 1]);
		collectInfo(start - 1, end-1);
	}
	//删X，X减一
	else if (info_B[start][end] == 1) {
		collectInfo(start - 1, end);
	}
	//删Y，Y减一
	else {
		collectInfo(start , end-1);
	}
}

//从前往后输出最长公共子序列，即出栈
void printSequence() {
	int num = sequence_R.size();
	cout << "序列X为：" << sequence_X << endl;
	cout << "序列Y为：" << sequence_Y << endl;
	cout << "X与Y的最长公共子序列为：";
	for (int i = 0; i < num; i++) {
		cout << sequence_R.top();
		sequence_R.pop();
	}
	cout << endl;
}

int main() {
	LCS();
	collectInfo(N-2,M-2);//N=序列X的长度+2,M=序列Y的长度+2
	printSequence();
	return 0;
}