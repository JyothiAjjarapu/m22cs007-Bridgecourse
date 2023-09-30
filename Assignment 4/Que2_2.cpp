#include<bits/stdc++.h>
using namespace std;

int main()
{

    int first_card,second_card;
    
    cout<<"First Friend number of Cards : ";
    cin>>first_card;
    int A[first_card];

    cout<<"First Friend card's Strength : ";
    for(int i = 0; i<first_card; i++)
        cin>>A[i];

    cout<<"\nSecond Friend number of Cards : ";   
    cin>>second_card;
    int B[second_card];
    cout<<"Second Friend card's Strength : ";
    for(int i = 0; i<second_card; i++)
        cin>>B[i];
    
    sort(B,B+second_card);

    long int sum = 0;
    for(int i = 0; i<first_card; i++)
    {
        long x = B[second_card-1]+1;
        if(x-A[i]>0)sum+=x-A[i];
    }
    cout<<"\nAmount of money first friend needed to win game : "<<sum<<endl;

    return 0;
}