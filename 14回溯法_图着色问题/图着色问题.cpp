#include<iostream>
#define N 100//��󶥵���

using namespace std;

int color[N] = {0};//��������ɫ����
int graph[N][N] = {0};//����ͼ���ڽӾ���
int n, m;//nΪ��������mΪ��ɫ��
int counts=0;//���з�������

bool check(int step) {
	for (int i = 0; i < n; i++) {
		//�����������ͨ����ɫ��ͬ����ɫ������
		if (graph[step][i] == 1 && color[step] == color[i]) {
			return false;
		}
	}
	return true;
}

void graphColor(int step) {
	if (step == n) {//���ڿ��е�������ɫ��������ӡ����
		for (int i = 0; i < n; i++) {
			cout << color[i] << " ";
		}
		cout << endl;
		counts++;
	}
	else {
		for (int k = 1; k <= m; k++) {
			color[step] = k;//step���㳢�Ը�����ɫ��ɫ
			if (check(step)) {//������ɫ��ɫ���У�������һ���������ɫ
				graphColor(step+1);
			}
			//�����У�����
			color[step] = 0;
		}
	}
}

int main() {

	/*���룺
		0 1 1 1 0
		1 0 1 1 1
		1 1 0 1 0
		1 1 1 0 1
		0 1 0 1 0*/
	
	cout << "��ֱ����붨����n����ɫ��m��" << endl;
	cin >> n >> m;
	cout << "�������ڽӾ���" << endl;
	int row, col, v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	graphColor(0);
	if (counts != 0)
		cout << "���з�����Ϊ��" << counts << endl;
	else
		cout << "No" << endl;
	return 0;
}

