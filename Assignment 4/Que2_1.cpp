#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    int road, fav, i, counter;
    cout<<"#roads : ";
    cin >> road;

    cout<<"Favourite number : ";
    cin>>fav;

    vector<int> vec(road);
    vector<int> vec1(road);
    bool flag = false;

    for (i = 0; i < road; i++){   
        cout<<"Xl : ";
        cin >> vec[i];

        cout<<"Xr : "; 
        cin>> vec1[i];
        if (vec1[i] - vec[i] == fav)
            flag = true;
        
    }

    for (i = 0; i < road - 1; i++){
        counter = 1;
        while (vec1[i] == vec[i + 1]){
            counter = counter + (vec1[i] - vec[i]);
            if (counter == fav)
                flag = true;
            
            i++;
        }
    }
    if (flag == true){
        cout << "Yes" << endl;
        return 0;
    }
    
    cout << "No" << endl;
    return 0;
}