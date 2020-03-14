#include<iostream>

using namespace std;

int linearSearch(int arr[], int n, int value) {//顺序查找
	for (int i = 0; i < n; i++)
		if (arr[i] == value)
			return i+1;
	return 0;
}

int main() {

	int a[100],guess;
	for (int i = 90; i < 190; i++)
		a[i - 90] = 2 * i - 90;
	cout << "请输入查找数：" << endl;
	cin >> guess;
	cout << "注：0表示不存在，数组下标从1开始。" << endl;
	cout << "嘀，顺序检索！下标索引为：";
	printf("%d", linearSearch(a, 100, guess) );

}
