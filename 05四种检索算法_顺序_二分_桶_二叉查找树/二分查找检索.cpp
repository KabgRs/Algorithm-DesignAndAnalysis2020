#include<iostream>

using namespace std;

int binSearch(int arr[], int n,int value) {//���ֲ���

	int i,left=0,right=n-1,mid;
	while (left <= right) {					
		mid = (left + right) / 2;
		if (arr[mid] == value) return mid+1;//����±��1��ʼ
		else if(arr[mid] < value) left = mid+1;
		else right = mid-1;
	}
	return 0;
}


int main() {

	int a[100],guess;
	for (int i = 90; i < 190; i++)
		a[i - 90] = 2 * i - 90;
	cout << "�������������" << endl;
	cin >> guess;
	cout << "ע��0��ʾ�����ڣ������±��1��ʼ��" << endl;
	cout << "�֣����ֲ��Ҽ������±�����Ϊ��";
	printf("%d", binSearch(a, 100, guess) );

}
