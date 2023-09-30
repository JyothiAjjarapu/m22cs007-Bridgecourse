#include <bits/stdc++.h>
using namespace std;
int s[50][50];

int product(int* arr, int i, int j){
	if (i == j)
	    return 0;

	if (s[i][j] != -1)
        return s[i][j];


	s[i][j] = INT_MAX;
	
    for (int k = i; k < j; k++)
		s[i][j] = min( s[i][j], product(arr, i, k) + product(arr, k + 1, j) + arr[i - 1]*arr[k]*arr[j] );
	
    
    return s[i][j];
}

int MatrixChainOrder(int* arr, int n){
    int i = 1, j = n - 1;
    return product(arr, i, j);
}


int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(s, -1, sizeof s);

	cout << "Number of product is : "<< MatrixChainOrder(arr, n);

    return 0;
}


