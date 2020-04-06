#include<iostream>
#include <algorithm>
#include<cstdlib>
#include<cmath>

#define N 10

using namespace std;

void selectSort(int a[], int left, int right) {//选择排序，降序
	
	int max,index;
	for (int i = left; i < right; i++) {
		max = a[i]; index = i;
		for (int j = i + 1; j <= right; j++) {
			if (a[j] > max) {
				max = a[j];
				index = j;
			}
		}
		a[index] = a[i];
		a[i] = max;
	}
}

void insertSort(int a[], int left, int right) {//插入排序，升序

	int i, j, temp;
	for (i = left + 1; i <= right; i++) {
		j = i - 1;
		temp = a[i];
		while (j >= left && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//得到每组中位数所构成集合的中位数
int getMedian(int* const left, int* const right) {
	if (left >= right-1) {
		return *left;
	}
	int* l, * r;
	int dis = 0;
	for (l = left; l <= right; l+=5) {
		if (l + 4 <= right) {
			r = l + 4;
		}
		else {
			r = right;
		}
		//用插入排序将每组排序
		insertSort(left,l-left,r-left);
		//将中位数交换到每组的第一个
		swap(left + dis, l + (r - l) / 2);
		dis++;
	}
	return getMedian(left, left + dis);
}

int Bfprt(int* const left, int* const right, int* const k) {//改编快速排序，升序，返回第k位值

	int* l = left, *r = right;
	int pivot = getMedian(left, right);
	while (l < r) {
		while (l < r && *r >= pivot) {
			r--;
		}
		*l = *r;
		while (l < r && *l <= pivot) {
			l++;
		}
		*r = *l;
	}
	*l = pivot;

	if (l == k) return *l;
	else if (l > k) return Bfprt(left, l - 1, k);
	else Bfprt(l+1, right, k);

}


void printArray(int a[], int n) {//打印数组，每五个换行
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
		if ((i+1) % 5 == 0) {
			cout << endl;
		}
	}
}


int main() {

	int arr[N] = {2,4,1,7,8,6,9,5,3,10};
	/*insertSort(arr, 0, N - 1);
	printArray(arr, N);*/
	int k = 1;//1
	cout << "Please enter k between 1 and 10:" ;
	cin >> k;
	cout<< "The value of index k is:"<<Bfprt(arr, arr+N-1, arr+k-1);
	return 0;
}