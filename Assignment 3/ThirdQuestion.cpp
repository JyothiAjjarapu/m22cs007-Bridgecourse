//Given that a represents that the gcd(a[i],a[j]) blocks would be required to form a edge between
// i and j. We need to maximum spanning tree for this graph with the given weights.

//We will follow the kruskals algorithm here also but for maximum edges. Create a graph with V 
//vertices and edges be gcd of a[i] and a[j].

using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
class Mz{
    
    int* mnodes;
    
    int* count;

    public:
        Mz(int n)
        {
            mnodes = new int[n];
            count = new int[n];

            for(int i = 0; i<n; i++){
                mnodes[i] = -1;
                count[i] = 1;
            }
        }

        int search(int i)
        {
            if(mnodes[i] == -1)
            {
                return i;
            }

            return search(mnodes[i]);
        }

        void unionsets(int x, int y)
        {
            int set1 = search(x);
            int set2 = search(y);

            if(set1!=set2){
                if(count[set1]<count[set2]){
                    mnodes[set1] = set2;
                   count[set2]+=count[set1];
                }
                else{
                    mnodes[set2] = set1;
                    count[set1]+=count[set2];
                }
            }
        }
};

class Graphs
{
    vector<vector<int>> edgeslist;
    int V;

    public: 
    Graphs(int V){
        this->V = V;
    }

    void Edgead(int x, int y, int z)
    {
        edgeslist.push_back({z,x,y});
    }

    int mstWeight()
    {
        //Sort the edges in the ascending order.
        std::sort(edgeslist.begin(), edgeslist.end(), greater<>());

        Mz d(V);
        int weight = 0;
        cout<<"These are the edges in the Maximum Spanning Tree using Kruskal's algorithm:"<<endl;
        for(auto edge: edgeslist)
        {
            int z = edge[0];
            int x = edge[1];
            int y = edge[2];

            if(d.search(x)!= d.search(y))
            {
                d.unionsets(x,y);
                weight+=z;
                cout<< x << " ---- " << y << " == " <<z << endl;
            }
        }

        return weight;
    }
};

int GCD(int a, int b)
{
    int result = min(a, b); // Find Minimum of a nd b 
    while (result > 0)
     {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result;
}

int main(){

    int array[] = {3,6,8,2,5,10};

    Graphs g(sizeof(array));
    int i=0;
    while(i<sizeof(array)/sizeof(int))
    {
        int j=i+1;
        while(j<sizeof(array)/sizeof(int))
        {
              g.Edgead(i,j,GCD(array[i],array[j]));
               j++;
        }
       i++;
    }
  
    int weight = g.mstWeight();

    cout<<"Maximum number of blocks to build road in the city is :"<< weight;
}