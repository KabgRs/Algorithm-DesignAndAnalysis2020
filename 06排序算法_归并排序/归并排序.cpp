#include<stdio.h>
#include<stdlib.h>

#define N 10
void merge(int a[], int left, int mid, int right) {
	int p1 = left, p2 = mid + 1,i=0;
	//辅助数组 
	int* temp = (int*)malloc(sizeof(int) * (right - left + 1));
	//依次选择左部分右部分中较小的数，赋值给辅助数组
	//注意：左部分有序，右部分有序，但整体不一定有序 
	//使得temp中的数据是有序的 
	while (p1 <= mid && p2 <= right) {
		if (a[p1] < a[p2])  temp[i++] = a[p1++];	
		else temp[i++] = a[p2++];
	}
	//两个while只会运行一个，将剩余未赋值的数依次赋值（即为有序） 
	while (p1 <= mid) 
		temp[i++] = a[p1++];

	while (p2 <= right) 
		temp[i++] = a[p2++];
	//将排序好的数重新赋给原数组 
	for (i = 0; i < right - left+1; i++) 
		a[left + i] = temp[i];
	//释放内存空间 
	free(temp);
}

//将数组不断二分成更小的部分 
void dichotomy(int a[], int left,int right) { 
	if (left >= right) return;
	int mid=(left+right)/2;
	dichotomy(a, left, mid);
	dichotomy(a, mid+1, right);
	merge(a, left, mid, right);
}

void mergeSort(int a[], int n) {//归并排序 
	dichotomy(a, 0, n - 1);
}

void printArr(int a[], int n) {//打印数组 
	for (int i = 0; i < n; i++) 
		printf("%d ", a[i]);
	printf("\n");
}

int* copyArr(int a[], int n) {//复制数组 
	int* temp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		temp[i] = a[i];
	return temp;
}
int main() {

	int arr[10] = {4,1,67,43,55,2,8,96,12,33};
	int* temp = (int*)malloc(sizeof(int) * N);
	temp = copyArr(arr, N);
	printf("原数组：\n");
	printArr(temp, N);//打印原数组
	mergeSort(temp, N);
	printf("排序后数组：\n"); 
	printArr(temp, N);//打印排序数组
	free(temp); 
	return 0;
}
