

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

// In given question, there are 6 vertices.
#define V 6

int minDst(int dst[], bool sptSet[])
{
	
	int min = INT_MAX, min_index;
 int v=0;
	while(v < V)
    {
		if (sptSet[v] == false && dst[v] <= min)
			min = dst[v], min_index = v;
        v++;
    }
	return min_index;
}


void prtSltn(int dst[])
{
	printf("Vertex \t\t Distance from Source\n");
    int i=0;
	while( i < V)
    {
		printf("%d \t\t %d\n", i, dst[i]);
        i++;
    }
}


void dijkstra(int graph[V][V], int src)
{
	int dst[V]; 

	bool sptSet[V]; 
    int i=0;

	while(i < V)
    {
        	dst[i] = INT_MAX, sptSet[i] = false;
            i++;

    }	
	dst[src] = 0;

	int count=0;
	while(count < V - 1) 
    {
		
		int u = minDst(dst, sptSet);

		
		sptSet[u] = true;

		
		for (int v = 0; v < V; v++)
        {
	
			if (!sptSet[v] && graph[u][v] && dst[u] != INT_MAX
				&& dst[u] + graph[u][v] < dst[v])
				dst[v] = dst[u] + graph[u][v];
        }
        count++;
	}

	
	prtSltn(dst);
}


int main()
{
	
	int graph[V][V] = 
    {                   { 0, 0, 0, 0, -1, 0 },
						{ 1, 0, 0, 2, 0, 0 },
						{ 0, 2, 0, 7, 0, -8},
						{ -4, 0, 7, 0, 3, 0 },
						{ 0, 7, 0, 0, 0, 0 },
						{ 0, 5, 10, 0, 0,0}
    };

	dijkstra(graph, 0);

	return 0;
}
