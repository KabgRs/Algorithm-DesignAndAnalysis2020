#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>

#define N 10
#define INIT 0xfffff

using namespace std;

struct node {
	int x;
	int y;
}P[N],Q[N],S[N];

double distance(node a, node b) {//��������
	return double((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double min(double d1, double d2) {//ȡ�����н�Сֵ
	if (d1 < d2)
		return d1;
	return d2;
}

void insertV(node* p, int x, int y) {//�����ֵ
	p->x = x;
	p->y = y;
}

double bruteForce_closest(node P[],int left,int right) {//������

	double dminsq = INIT;
	for (int i = left; i <=right; i++) {
		for (int j = i+1; j <=right; j++) {
			double dis = distance(P[i], P[j]);
			if (dminsq > dis) dminsq = dis;
		}
	}
	return sqrt(dminsq);
}

double divideConquer_closest(node P[],node Q[],int left,int right) {//���η�

	if (right - left <= 2) {//����
		return bruteForce_closest(P,left,right);
	}
	int mid,midx,num;
	double dminsq, d, dl, dr;
	mid = (left + right) / 2;//��λ��
	dl=divideConquer_closest(P, Q, left, mid);
	dr=divideConquer_closest(P, Q, mid+1, right);
	//ȡ���������ֵĽ϶̾���
	d = min(dl, dr);
	//�д��ߵ�x������
	midx= P[mid].x;
	//��Q������ |x-m|<d �ĵ㸴�Ƶ�����S[0...num-1]
	num = 0;
	for (int i = 0; i < N; i++) {
		if (Q[i].x - midx < d && Q[i].x - midx > -d) {
			S[num].x = Q[i].x;
			S[num].y = Q[i].y;
			num++;
		}
	}
	//������̾��룬���жϲ��������Ҹ�ȡһ������
	dminsq = d * d;
	for (int i = 0; i < num-1; i++) {
		int k = i + 1;
		while (k <= num - 1 and pow((S[k].y - S[i].y), 2) < dminsq) {
			dminsq = min(distance(S[k], S[i]), dminsq);
			k++;
		}
	}
	return sqrt(dminsq);//���������ѭ������
}

int main() {

	//�ֶ����㼯���Ѿ��ź��򣬰�x������
	insertV(&P[0], 1, 2);
	insertV(&P[1], 2, 9);
	insertV(&P[2], 4, 5);
	insertV(&P[3], 5, 3);
	insertV(&P[4], 6, 10);
	insertV(&P[5], 8, 1);
	insertV(&P[6], 9, 7);
	insertV(&P[7], 10, 6);
	insertV(&P[8], 11, 3);
	insertV(&P[9], 11, 9);
	//��y������
	insertV(&Q[0], 8, 1);
	insertV(&Q[1], 1, 2);
	insertV(&Q[2], 5, 3);
	insertV(&Q[3], 11, 3);
	insertV(&Q[4], 4, 5);
	insertV(&Q[5], 10, 6);
	insertV(&Q[6], 9, 7);
	insertV(&Q[7], 2, 9);
	insertV(&Q[8], 11, 9);
	insertV(&Q[9], 6, 10);

	cout<<"�����������̾��룺"<<bruteForce_closest(P,0,N-1)<<endl;
	cout<<"���η������̾��룺"<<divideConquer_closest(P,Q,0,N-1)<<endl;

	return 0;
}