#include <bits/stdc++.h>
using namespace std;

int maxCutseg(int n, int x, int y, int z)
{
	
	int s[n + 1];
	
	memset(s, -1, sizeof(s));

	
	s[0] = 0;

	for (int i = 0; i < n; i++)
	{
		if (s[i] != -1)
		{
			if(i + x <= n )
					s[i + x] = max(s[i] + 1, s[i + x]);
								
			if(i + y <= n )
					s[i + y] = max(s[i] + 1, s[i + y]);
								
			if(i + z <= n )
					s[i + z] = max(s[i] + 1, s[i + z]);
		}
	}
	return s[n];
}

int main()
{
	int n, x, y, z;
	cout<<"Enter n, x, y, z"<<endl;
	cin>>n>>x>>y>>z;

	cout <<"Maximum possible cuts are : "<< maxCutseg(n, x, y, z);
	return 0;
}
