#include<iostream>

using namespace std;

int binSearch(int arr[], int n,int value) {//二分查找

	int i,left=0,right=n-1,mid;
	while (left <= right) {					
		mid = (left + right) / 2;
		if (arr[mid] == value) return mid+1;//输出下标从1开始
		else if(arr[mid] < value) left = mid+1;
		else right = mid-1;
	}
	return 0;
}


int main() {

	int a[100],guess;
	for (int i = 90; i < 190; i++)
		a[i - 90] = 2 * i - 90;
	cout << "请输入查找数：" << endl;
	cin >> guess;
	cout << "注：0表示不存在，数组下标从1开始。" << endl;
	cout << "嘀，二分查找检索！下标索引为：";
	printf("%d", binSearch(a, 100, guess) );

}
