#include<iostream>

using namespace std;

int sup_arr[1000]={0};

void transArr(int a[],int n){
	for (int i = 0; i < n; i++) {
		sup_arr[a[i]] = i+1;
	}
}

int bottleSearch(int key) {//桶查找
	return sup_arr[key];
}

int main() {

	int a[100],guess;
	for (int i = 90; i < 190; i++)
		a[i - 90] = 2 * i - 90;
	transArr(a,100);
	cout << "请输入查找数：" << endl;
	cin >> guess;
	cout << "注：0表示不存在，数组下标从1开始。" << endl;
	cout << "嘀，桶检索！下标索引为：";
	printf("%d", bottleSearch(guess));

}
