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

double distance(node a, node b) {//两点间距离
	return double((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double min(double d1, double d2) {//取两者中较小值
	if (d1 < d2)
		return d1;
	return d2;
}

void insertV(node* p, int x, int y) {//插入点值
	p->x = x;
	p->y = y;
}

double bruteForce_closest(node P[],int left,int right) {//蛮力法

	double dminsq = INIT;
	for (int i = left; i <=right; i++) {
		for (int j = i+1; j <=right; j++) {
			double dis = distance(P[i], P[j]);
			if (dminsq > dis) dminsq = dis;
		}
	}
	return sqrt(dminsq);
}

double divideConquer_closest(node P[],node Q[],int left,int right) {//分治法

	if (right - left <= 2) {//蛮力
		return bruteForce_closest(P,left,right);
	}
	int mid,midx,num;
	double dminsq, d, dl, dr;
	mid = (left + right) / 2;//中位数
	dl=divideConquer_closest(P, Q, left, mid);
	dr=divideConquer_closest(P, Q, mid+1, right);
	//取左右两部分的较短距离
	d = min(dl, dr);
	//中垂线的x轴坐标
	midx= P[mid].x;
	//将Q中所有 |x-m|<d 的点复制到数组S[0...num-1]
	num = 0;
	for (int i = 0; i < N; i++) {
		if (Q[i].x - midx < d && Q[i].x - midx > -d) {
			S[num].x = Q[i].x;
			S[num].y = Q[i].y;
			num++;
		}
	}
	//更新最短距离，即判断并更新左右各取一点的情况
	dminsq = d * d;
	for (int i = 0; i < num-1; i++) {
		int k = i + 1;
		while (k <= num - 1 and pow((S[k].y - S[i].y), 2) < dminsq) {
			dminsq = min(distance(S[k], S[i]), dminsq);
			k++;
		}
	}
	return sqrt(dminsq);//把求根放在循环外面
}

int main() {

	//手动建点集，已经排好序，按x轴排序
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
	//按y轴排序
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

	cout<<"蛮力法求得最短距离："<<bruteForce_closest(P,0,N-1)<<endl;
	cout<<"分治法求得最短距离："<<divideConquer_closest(P,Q,0,N-1)<<endl;

	return 0;
}