#include<iostream>
#include<cstdlib>
#define N 10//活动数

using namespace std;

struct item {
	int n;
	double start;
	double end;
}activity[N];

//将活动按结束时间排序,改编快排
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

//将活动按开始时间排序,改编快排
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

//相容算法（贪心）
int cmpatible_Q(int record[N]) {

	int num = 0, i = 0;

	//前一个项目的结束时间
	double tempEnd = activity[i].end;
	//记录所选项目的下标
	record[i++] = 0;
	//记录选择项目总数
	num++;
	for (int k = 1; k < N; k++) {
		//找到下一个相容项目，更新各值
		if (activity[k].start >= tempEnd) {
			tempEnd = activity[k].end;
			record[i++] = k;
			num++;
		}
	}
	return num;
}

//将活动按进行时长排序,改编快排
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

//相容算法（按时长排）
int cmpatible_QByTime(int record[N]) {

	int num = 0, i = 0;

	//记录所选项目的下标
	record[i++] = 0;
	//记录选择项目总数
	num++;
	for (int k = 1; k < N; k++) {
		//falg为1表示项目相容
		int flag = 1;
		//按顺序判断活动k是否与已有活动相容
		for (int j = 0; j < num; j++) {
			if ( activity[k].start < activity[record[j]].end && activity[k].start  > activity[record[j]].start - activity[k].end + activity[k].start) {
				flag = 0;
				break;
			}
		}
		//相容则更新各值
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

	//按结束时间将活动排序
	cout << "按结束时间将活动排序_最大活动数为:";
	sortByEnd(activity, activity + N - 1);
	num = cmpatible_Q(aByEnd);
	cout << num << endl<<"它们分别是："<<endl;
	for (int i = 0; i < num; i++) {
		cout << "项目" << activity[aByEnd[i]].n << ": start from " << activity[aByEnd[i]].start << ", end to " << activity[aByEnd[i]].end << endl;
	}
	cout << endl;

	//按开始时间将活动排序
	cout << "按开始时间将活动排序_最大活动数为:";
	sortByStart(activity, activity + N - 1);
	num = cmpatible_Q(aByStart);
	cout << num << endl << "它们分别是：" << endl;
	for (int i = 0; i < num; i++) {
		cout << "项目" << activity[aByStart[i]].n << ": start from " << activity[aByStart[i]].start << ", end to " << activity[aByStart[i]].end << endl;
	}
	cout << endl;

	//按时间长短将活动排序
	cout << "按时间长短将活动排序_最大活动数为:";
	sortByTime(activity, activity + N - 1);
	num = cmpatible_QByTime(aByTime);
	cout << num << endl << "它们分别是：" << endl;
	for (int i = 0; i < num; i++) {
		cout << "项目" << activity[aByTime[i]].n << ": start from " << activity[aByTime[i]].start << ", end to " << activity[aByTime[i]].end << endl;
	}
	cout << endl;

	return 0;
}