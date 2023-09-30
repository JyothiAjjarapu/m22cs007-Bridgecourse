#include<bits/stdc++.h>
using namespace std;

bool twoParts(int array[], int n) 
{
    int res = 0;
    for(int i = 0; i<n;i++)
    {
        res = res + array[i];
    }

    if(res%2!=0)
        return false;

    res = res / 2;
    bool s[res+1] = {false};
    s[0] = true;

    for(int i=1; i <= n; i++)
    {
        for(int j = res; j>=0; j=j-1)
        {
            if(j-array[i-1] >= 0)
            {
                s[j] = s[j - array[i-1]] or s[j];
            }
        }
    }
    return s[res];
}



int main()
{
    int array[] = {1, 5, 11, 5 };
    int size = sizeof(array)/sizeof(array[0]);
    if(twoParts(array, size))
    {
        cout<<"Yes..!!"<<endl;
        return 0;
    }
    cout<<"No..!!"<<endl;
    return 0;
}
