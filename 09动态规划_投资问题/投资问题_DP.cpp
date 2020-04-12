#include<iostream>
#define N 5//��Ŀ��
#define M 6//Ͷ���ܶ�

using namespace std;

//Aitem[3][2]��ʾ��Ͷ��2��Ԫ��3����Ŀ��Ͷ�ʽ�����׷��·��
double aItem[N][M] = {0};
//Fsum[3][2]��ʾǰ3����Ŀ��Ͷ��2��Ԫ���������
double Fsum[N][M] = { 0 };

double investMax(double f[N][M]) {
		
	//ǰ1����Ŀ�����
	for (int i = 0; i <= M-1; i++) {
		Fsum[1][i] = f[1][i];
		aItem[1][i] = i;
	}
	//��k����Ŀ
	for (int k = 2; k <= N-1; k++) {
		//k����Ŀ������m��Ԫ
		for (int m = 1; m <= M-1; m++) {
			double max = -1,temp=0;
			//��k����Ŀ����a��Ԫ
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
		cout << "��" << i << "����Ŀ��Ͷ��" << aItem[i][index] << "��Ԫ" << endl;
		index -= aItem[i][index];
	}
}

int main() {

	double f[N][M] = {//f[1][2]��ʾͶ��1����Ŀ2��Ԫ��������Ч��
		{0, 0, 0, 0, 0, 0},
		{0,11,12,13,14,15},
		{0, 0, 5,10,15,20},
		{0, 2,10,30,32,40},
		{0,20,21,22,23,24}
	};
	cout << M-1 <<"��ԪͶ��"<<N-1<<"��Ŀ�������Ϊ��" << investMax(f) << endl;
	printInfo();
	return 0;
}
