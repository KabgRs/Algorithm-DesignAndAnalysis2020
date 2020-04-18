#include<iostream>
#include<cstdlib>
#define N 6//�Ⱦ�������1

using namespace std;
//m[1][3]��ʾ����1������3�ľ�������С�˷��������
long long int calculation_m[N][N] = {0};
//��¼����λ��
int position_s[N][N] = {0};
//��������Ϣ
long long int P[N] = {10, 5, 20 , 6, 30, 8};

//��ʼ��λ������
//ÿ������µ�����λ�������һ�ľ���
void init(int m[][N]) {
	for (int i = 1; i < N; i++) {//ȡͷ��ȡβ
		for (int j = i + 1; j <= N; j++) {//ȡβ��ȡͷ
			m[i][j] = i;
		}
	}
}

int matrixChain() {
	
	init(position_s);
	//���������1��ʼ
	//rΪ��ǰ�����ģ�����������ȣ�
	for (int r = 2; r <= N-1; r++) {
		//��㷶Χ
		for (int i = 1; i <= N - r; i++) {
			//�����͹�ģ�¶�Ӧ���յ�
			int j = i + r - 1;
			calculation_m[i][j] = calculation_m[i + 1][j] + P[i - 1] * P[i] * P[j];
			//ѡ����С�㷨����ֵ����¼
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
//�ݹ��ӡ���
void printResult(int start,int end) {
	if (start+2 > end) {
		return;
	}
	int mid = position_s[start][end];
	cout << start<<"--"<<end<<":"<<mid<<"   ���������"<<calculation_m[start][end]<<endl;
	printResult(start, mid);
	printResult(mid+1, end);

}

int main() {
	matrixChain();
	printResult(1, N - 1);
	return 0;
}
