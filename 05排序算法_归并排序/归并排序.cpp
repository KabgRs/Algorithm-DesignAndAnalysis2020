#include<stdio.h>
#include<stdlib.h>

#define N 10
void merge(int a[], int left, int mid, int right) {
	int p1 = left, p2 = mid + 1,i=0;
	//�������� 
	int* temp = (int*)malloc(sizeof(int) * (right - left + 1));
	//����ѡ���󲿷��Ҳ����н�С��������ֵ����������
	//ע�⣺�󲿷������Ҳ������򣬵����岻һ������ 
	//ʹ��temp�е������������ 
	while (p1 <= mid && p2 <= right) {
		if (a[p1] < a[p2])  temp[i++] = a[p1++];	
		else temp[i++] = a[p2++];
	}
	//����whileֻ������һ������ʣ��δ��ֵ�������θ�ֵ����Ϊ���� 
	while (p1 <= mid) 
		temp[i++] = a[p1++];

	while (p2 <= right) 
		temp[i++] = a[p2++];
	//������õ������¸���ԭ���� 
	for (i = 0; i < right - left+1; i++) 
		a[left + i] = temp[i];
	//�ͷ��ڴ�ռ� 
	free(temp);
}

//�����鲻�϶��ֳɸ�С�Ĳ��� 
void dichotomy(int a[], int left,int right) { 
	if (left >= right) return;
	int mid=(left+right)/2;
	dichotomy(a, left, mid);
	dichotomy(a, mid+1, right);
	merge(a, left, mid, right);
}

void mergeSort(int a[], int n) {//�鲢���� 
	dichotomy(a, 0, n - 1);
}

void printArr(int a[], int n) {//��ӡ���� 
	for (int i = 0; i < n; i++) 
		printf("%d ", a[i]);
	printf("\n");
}

int* copyArr(int a[], int n) {//�������� 
	int* temp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		temp[i] = a[i];
	return temp;
}
int main() {

	int arr[10] = {4,1,67,43,55,2,8,96,12,33};
	int* temp = (int*)malloc(sizeof(int) * N);
	temp = copyArr(arr, N);
	printf("ԭ���飺\n");
	printArr(temp, N);//��ӡԭ����
	mergeSort(temp, N);
	printf("��������飺\n"); 
	printArr(temp, N);//��ӡ��������
	free(temp); 
	return 0;
}
