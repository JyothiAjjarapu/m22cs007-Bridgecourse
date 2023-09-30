#include <bits/stdc++.h>
using namespace std;

void printPara(int i, int j, int n, int* bracket, char& name){
	
	if (i == j) {
		cout << name++;
		return;
	}

	cout << "(";
	printPara(i, *((bracket + i * n) + j), n, bracket, name);
	printPara(*((bracket + i * n) + j) + 1, j, n, bracket, name);
	cout << ")";
}


void matrixChainOrder(int arr[], int n){
	int m[n][n];

    int bracket[n][n];

	for (int i = 1; i < n; i++)
		m[i][i] = 0;

	for (int l = 2; l < n; l++){
		for (int i = 1; i < n - l + 1; i++){
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++){
				int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];

				if (q < m[i][j]){
					m[i][j] = q;
					bracket[i][j] = k;
				}
			}
		}
	}

	char name = 'A';

	cout << "Parenthesization is : ";
	printPara(1, n - 1, n, (int*)bracket, name);
	cout << "\nCost is : " << m[1][n - 1];
}


int main()
{
	int arr[] = { 40, 20, 30, 10, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	matrixChainOrder(arr, n);
	return 0;
}
