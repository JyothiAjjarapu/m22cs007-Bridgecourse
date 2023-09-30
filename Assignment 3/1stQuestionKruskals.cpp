using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
class Mz
{
   
    int* mnodes;
  
    int* count;

    public:
        Mz(int n)
        {
           mnodes = new int[n];
            count = new int[n];

            int i=0;
            while(i<n)
            {
                mnodes[i] = -1;
                count[i] = 1;
                i++;
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

            if(set1!=set2)
            {
                if(count[set1]<count[set2])
                {
                    mnodes[set1] = set2;
                    count[set2]+=count[set1];
                }
                else
                {
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
    Graphs(int V)
    {
        this->V = V;
    }

    void Edgead(int x, int y, int z)
    {
        edgeslist.push_back({z,x,y});
    }

    void mst()
    {
        //Sort the edges in the ascending order.
        std::sort(edgeslist.begin(), edgeslist.end());

        Mz d(V);
        int weight = 0;
        cout<<"The following are the edges in the Minimal Spanning Tree using Kruskal's algorithm:"<<endl;
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
    }
};

int main()
{
    Graphs g(4);
    g.Edgead(0,1,20);
    g.Edgead(1,3,25);
    g.Edgead(2,0,15);
    g.Edgead(0,3,10);
    g.Edgead(2,3,8);

    g.mst();
}