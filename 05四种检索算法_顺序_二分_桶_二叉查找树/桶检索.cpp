#include<iostream>

using namespace std;

int sup_arr[1000]={0};

void transArr(int a[],int n){
	for (int i = 0; i < n; i++) {
		sup_arr[a[i]] = i+1;
	}
}

int bottleSearch(int key) {//Ͱ����
	return sup_arr[key];
}

int main() {

	int a[100],guess;
	for (int i = 90; i < 190; i++)
		a[i - 90] = 2 * i - 90;
	transArr(a,100);
	cout << "�������������" << endl;
	cin >> guess;
	cout << "ע��0��ʾ�����ڣ������±��1��ʼ��" << endl;
	cout << "�֣�Ͱ�������±�����Ϊ��";
	printf("%d", bottleSearch(guess));

}
