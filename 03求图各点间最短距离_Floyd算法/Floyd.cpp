#include <iostream>
#include<vector>
#define INIT 65535
#define N 4

using namespace std;

vector<vector<int> > Floyd(vector<vector<int> > mat) {

	vector<vector<int>> copy(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			copy[i][j]=mat[i][j];

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (copy[i][j] > (copy[i][k] + copy[k][j]) && i != j )
					copy[i][j] = copy[i][k] + copy[k][j];

	return copy;

}

void printMat(vector<vector<int> > mat) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}

}

int main() {

	vector<vector<int> > mat= {
	{	0,		2,		6,		4	},
	{	INIT,	0,		3,		INIT},
	{	7,		INIT,	0,		1	},
	{	5,		INIT,	12,		0}	};
	//printMat(mat);
	vector<vector<int> > newMat(N, vector<int>(N));
	newMat = Floyd(mat);
	printMat(newMat);

	return 0;
}
