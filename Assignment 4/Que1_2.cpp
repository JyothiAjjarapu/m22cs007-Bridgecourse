#include<bits/stdc++.h>
using namespace std;

int multiply(int array[], int n)
{
    sort(array, array+n);
    return min(array[0]*array[1]*array[2], array[0]*array[n-1]*array[n-2]);
}

int main()
{

    int array[] = { 4, -1, 4, 5, 9 };
    int size = sizeof(array)/sizeof(array[0]);
    if(size<3)
    {
        cout<<"Invalid..!!"<<endl;
        return 0;
    }
    cout<<"Min product of triplet is : "<<multiply(array, size);

    return 0;
}