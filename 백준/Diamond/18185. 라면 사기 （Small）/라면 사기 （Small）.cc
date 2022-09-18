#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> ramenCount(10100, 0);

	int minCost = 0;

	for (int i = 1; i < N+1; i++)
	{
		cin >> ramenCount[i];
	}

	for (int i = 1; i < N + 1; i++)
	{
		if (ramenCount[i + 1] > ramenCount[i + 2])
		{
			int two = min(ramenCount[i], ramenCount[i + 1] - ramenCount[i + 2]);
			minCost += 5 * two;

			ramenCount[i] -= two;
			ramenCount[i + 1] -= two;

			int three = min(ramenCount[i], min(ramenCount[i + 1], ramenCount[i + 2]));
			minCost += 7 * three;

			ramenCount[i] -= three;
			ramenCount[i + 1] -= three;
			ramenCount[i + 2] -= three;

		}
		else
		{
			int three = min(ramenCount[i], min(ramenCount[i + 1], ramenCount[i + 2]));
			minCost += 7 * three;

			ramenCount[i] -= three;
			ramenCount[i + 1] -= three;
			ramenCount[i + 2] -= three;

			int two = min(ramenCount[i], ramenCount[i + 1]);
			minCost += 5 * two;

			ramenCount[i] -= two;
			ramenCount[i + 1] -= two;
		}

		minCost += 3 * ramenCount[i];
	}

	cout << minCost << endl;
    
    return 0;
}