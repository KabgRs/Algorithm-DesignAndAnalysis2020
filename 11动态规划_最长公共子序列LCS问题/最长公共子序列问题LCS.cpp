#include<iostream>
#include<cstdlib>
#include<stack>

#define N 7//N=����X�ĳ���+2
#define M 8//M=����Y�ĳ���+2

using namespace std;

char sequence_X[N] = "ABBDA";//X����
char sequence_Y[M] = "BCCDAC";//Y����

//C[1][2]��ʾX����Ϊ1��Y����Ϊ2ʱ��������������г���
int length_C[N][M] = { 0 };

//���������1��ʾɾ��x��2��ʾy��3��ʾ���߶�ɾ
//B[1][2]=1 ��ʾX����Ϊ1��Y����Ϊ2ʱ�õ���������������г��ȣ�
//Ҫ��ǰһ����������ɾ��һ��xԪ��
int info_B[N][M] = { 0 };

//ջ�����������������Ԫ�أ��Ա��������
stack<char> sequence_R;

//����������г����㷨
void LCS() {

	for (int i = 1; i < N-1; i++) {
		for (int j = 1; j < M-1; j++) {
			//�ַ���ͬ
			if (sequence_X[i-1] == sequence_Y[j-1]) {
				//��ɾ
				length_C[i][j] = length_C[i - 1][j - 1] + 1;
				info_B[i][j] = 3;
			}
			//�ַ���ͬ
			else {
				if (length_C[i][j - 1] > length_C[i - 1][j]) {
					//ɾY
					length_C[i][j] = length_C[i][j - 1];
					info_B[i][j] = 2;
				}
				else {
					//ɾX
					length_C[i][j] = length_C[i - 1][j];
					info_B[i][j] = 1;
				}
			}
		}
	}

}

//Ԫ�ر��浽ջ
void collectInfo(int start,int end) {
	if (start == 0 || end == 0) {
		return;
	}
	//��ɾ��X��Y����һ
	if (info_B[start][end] == 3) {
		//cout << sequence_X[start - 1]<<" ";
		//�������дӺ���ǰ������Ƚ�������������ջsequence_R��
		sequence_R.push(sequence_X[start - 1]);
		collectInfo(start - 1, end-1);
	}
	//ɾX��X��һ
	else if (info_B[start][end] == 1) {
		collectInfo(start - 1, end);
	}
	//ɾY��Y��һ
	else {
		collectInfo(start , end-1);
	}
}

//��ǰ�����������������У�����ջ
void printSequence() {
	int num = sequence_R.size();
	cout << "����XΪ��" << sequence_X << endl;
	cout << "����YΪ��" << sequence_Y << endl;
	cout << "X��Y�������������Ϊ��";
	for (int i = 0; i < num; i++) {
		cout << sequence_R.top();
		sequence_R.pop();
	}
	cout << endl;
}

int main() {
	LCS();
	collectInfo(N-2,M-2);//N=����X�ĳ���+2,M=����Y�ĳ���+2
	printSequence();
	return 0;
}