#include<iostream>

using namespace std;

int linearSearch(int arr[], int n, int value) {//˳�����
	for (int i = 0; i < n; i++)
		if (arr[i] == value)
			return i+1;
	return 0;
}

int main() {

	int a[100],guess;
	for (int i = 90; i < 190; i++)
		a[i - 90] = 2 * i - 90;
	cout << "�������������" << endl;
	cin >> guess;
	cout << "ע��0��ʾ�����ڣ������±��1��ʼ��" << endl;
	cout << "�֣�˳��������±�����Ϊ��";
	printf("%d", linearSearch(a, 100, guess) );

}
