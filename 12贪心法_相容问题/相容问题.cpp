#include<iostream>
#include<cstdlib>
#define N 10//���

using namespace std;

struct item {
	int n;
	double start;
	double end;
}activity[N];

//���������ʱ������,�ı����
void sortByEnd(item* const left, item* const right) {
	if (left >= right) {
		return;
	}
	item* l = left, * r = right;
	item pivot = *l;
	while (l < r) {
		while (l < r && r->end >= pivot.end) {
			r--;
		}
		*l = *r;
		while (l < r && l->end <= pivot.end) {
			l++;
		}
		*r = *l;
	}
	l->end = pivot.end;
	l->start = pivot.start;
	l->n = pivot.n;

	sortByEnd(left, l - 1);
	sortByEnd(l + 1, right);
}

//�������ʼʱ������,�ı����
void sortByStart(item* const left, item* const right) {
	if (left >= right) {
		return;
	}
	item* l = left, * r = right;
	item pivot = *l;
	while (l < r) {
		while (l < r && r->start >= pivot.start) {
			r--;
		}
		*l = *r;
		while (l < r && l->start <= pivot.start) {
			l++;
		}
		*r = *l;
	}
	l->end = pivot.end;
	l->start = pivot.start;
	l->n = pivot.n;

	sortByStart(left, l - 1);
	sortByStart(l + 1, right);
}

//�����㷨��̰�ģ�
int cmpatible_Q(int record[N]) {

	int num = 0, i = 0;

	//ǰһ����Ŀ�Ľ���ʱ��
	double tempEnd = activity[i].end;
	//��¼��ѡ��Ŀ���±�
	record[i++] = 0;
	//��¼ѡ����Ŀ����
	num++;
	for (int k = 1; k < N; k++) {
		//�ҵ���һ��������Ŀ�����¸�ֵ
		if (activity[k].start >= tempEnd) {
			tempEnd = activity[k].end;
			record[i++] = k;
			num++;
		}
	}
	return num;
}

//���������ʱ������,�ı����
void sortByTime(item* const left, item* const right) {
	if (left >= right) {
		return;
	}
	item* l = left, * r = right;
	item pivot = *l;
	while (l < r) {
		while (l < r && (r->end - r->start) >= (pivot.end - pivot.start)) {
			r--;
		}
		*l = *r;
		while (l < r && (r->end - r->start) <= (pivot.end - pivot.start)) {
			l++;
		}
		*r = *l;
	}
	l->end = pivot.end;
	l->start = pivot.start;
	l->n = pivot.n;

	sortByTime(left, l - 1);
	sortByTime(l + 1, right);
}

//void updateTime(int time_slot[T],int left,int right) {
//	for (int i = left; i <= right; i++) {
//		time_slot[i]= 1;
//	}
//}

//�����㷨����ʱ���ţ�
int cmpatible_QByTime(int record[N]) {

	int num = 0, i = 0;

	//��¼��ѡ��Ŀ���±�
	record[i++] = 0;
	//��¼ѡ����Ŀ����
	num++;
	for (int k = 1; k < N; k++) {
		//falgΪ1��ʾ��Ŀ����
		int flag = 1;
		//��˳���жϻk�Ƿ������л����
		for (int j = 0; j < num; j++) {
			if ( activity[k].start < activity[record[j]].end && activity[k].start  > activity[record[j]].start - activity[k].end + activity[k].start) {
				flag = 0;
				break;
			}
		}
		//��������¸�ֵ
		if (flag == 1) {
			record[i++] = k;
			num++;
		}
	}
	return num;
}

int main() {

	activity[0].n = 1; activity[0].start = 1; activity[0].end = 4;
	activity[1].n = 2; activity[1].start = 3; activity[1].end = 5;
	activity[2].n = 3; activity[2].start = 2; activity[2].end = 6;
	activity[3].n = 4; activity[3].start = 5; activity[3].end = 7;
	activity[4].n = 5; activity[4].start = 4; activity[4].end = 9;
	activity[5].n = 6; activity[5].start = 5; activity[5].end = 9;
	activity[6].n = 7; activity[6].start = 6; activity[6].end = 10;
	activity[7].n = 8; activity[7].start = 8; activity[7].end = 11;
	activity[8].n = 9; activity[8].start = 8; activity[8].end = 12;
	activity[9].n = 10; activity[9].start = 2; activity[9].end = 13;

	int aByEnd[N] = { 0 };
	int aByStart[N] = { 0 };
	int aByTime[N] = { 0 };

	int num;

	//������ʱ�佫�����
	cout << "������ʱ�佫�����_�����Ϊ:";
	sortByEnd(activity, activity + N - 1);
	num = cmpatible_Q(aByEnd);
	cout << num << endl<<"���Ƿֱ��ǣ�"<<endl;
	for (int i = 0; i < num; i++) {
		cout << "��Ŀ" << activity[aByEnd[i]].n << ": start from " << activity[aByEnd[i]].start << ", end to " << activity[aByEnd[i]].end << endl;
	}
	cout << endl;

	//����ʼʱ�佫�����
	cout << "����ʼʱ�佫�����_�����Ϊ:";
	sortByStart(activity, activity + N - 1);
	num = cmpatible_Q(aByStart);
	cout << num << endl << "���Ƿֱ��ǣ�" << endl;
	for (int i = 0; i < num; i++) {
		cout << "��Ŀ" << activity[aByStart[i]].n << ": start from " << activity[aByStart[i]].start << ", end to " << activity[aByStart[i]].end << endl;
	}
	cout << endl;

	//��ʱ�䳤�̽������
	cout << "��ʱ�䳤�̽������_�����Ϊ:";
	sortByTime(activity, activity + N - 1);
	num = cmpatible_QByTime(aByTime);
	cout << num << endl << "���Ƿֱ��ǣ�" << endl;
	for (int i = 0; i < num; i++) {
		cout << "��Ŀ" << activity[aByTime[i]].n << ": start from " << activity[aByTime[i]].start << ", end to " << activity[aByTime[i]].end << endl;
	}
	cout << endl;

	return 0;
}