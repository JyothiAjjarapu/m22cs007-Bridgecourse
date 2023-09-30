#include<bits/stdc++.h>
using namespace std;

void jobs(int start[], int end[], int n)
{
    if(n <= 0)
    {
        cout<<"Invalid..!!"<<endl;
        return;
    }
    int compare = end[0];
    cout<<"Jobs are : "<<endl;
    cout<<"{"<<start[0]<<", "<<compare<<"} ,";

    int i = 1;
    while(i < n)
    {
        if(start[i] > compare)
        {
            compare = end[i];
            cout<<"{"<<start[i]<<", "<<compare<<"}, ";
        }

        i++;
    }
    return;
}



int main(){
    int start[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
	int end[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    int n = sizeof(end)/sizeof(start[0]);

    jobs(start, end, n);

    return 0;
}