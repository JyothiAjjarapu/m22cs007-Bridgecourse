using namespace std;
#include<iostream>

#define V 5

void printST(int root[], int graf[V][V])
{
    cout<< "Edge\t Weight\n";
    for(int i = 1; i< V; i++)
    {
        cout << root[i] << " - "<< i<<" \t"<< graf[i][root[i]]<<"\n";
    }

}

//Utility function to find the minimum key which is not included in the mstSet
int minimumKey(int key[], bool mstSet[]){
    int min = INT_MAX;
    int minIndex;
    int i=0;

    while(i< V)
    {
        if(mstSet[i]==false && key[i]< min){
            min = key[i];
            minIndex = i;
        }
        i++;
    }

    return minIndex;
}

void primsTree(int graph[V][V])
{
    //used to store constructed MST.
    //Stores the parent of each vertex. parent[0] has 0 vertex's parent(adjacent)
    int root[V];

    //Key values to pick from the minimum edges keys
    int key[V];

    //verticies included in the spanning tree.
    bool mstSet[V];

    for(int i =0; i< V; i++)
    {
        key[i]= INT_MAX;
        mstSet[i] = false;
    }

    //Consider the 1st index and make it as parent.
    key[0] = 0;
    root[0] = -1;

    //Minumum Spanning tree contains V vertices. Already added 1.
    int j=0;
    while(j<V-1)
    {
   
        int pickedVertex = minimumKey(key,mstSet);

        mstSet[pickedVertex] = true;

        //Since we picked a vertex from the other vertices, we need to update the key for
        //all of those.

        int i=0;
        while(i<V)
        {
            
            if(graph[pickedVertex][i] && mstSet[i] == false && graph[pickedVertex][i]< key[i])
            {
                root[i] = pickedVertex;
                key[i] = graph[pickedVertex][i];
            }
            i++;
        }
       
        j++;
        
    }
    //parent array is filled is filled with the adjacents.
    printST(root,graph);

}

int main()
{
    int graf[V][V] =
    {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    primsTree(graf);
}

