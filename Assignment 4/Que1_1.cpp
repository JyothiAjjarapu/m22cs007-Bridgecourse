#include <algorithm>
#include <iostream>

using namespace std;

int station(float arrival[], float departure[], int size)
{
	sort(arrival, arrival + size);
	sort(departure, departure + size);

	int need = 1, result = 1;
	int i = 1, j = 0;

	while (i < size && j < size) 
	{
		if (arrival[i] <= departure[j]) 
		{
			need++;
			i++;
		}

		else if (arrival[i] > departure[j])
		 {
			need--;
			j++;
		}

		if (need > result)
			result = need;
	}

	return result;
}

int main()
{
	float arrival[] = { 2.05, 2.10, 3.10, 3.20, 3.50, 5.10 };
	float departure[] = { 2.35, 3.40, 3.25, 4.30, 4.10, 5.40 };
	int size = sizeof(arrival) / sizeof(arrival[0]);
	cout << station(arrival, departure, size);
	return 0;
}
