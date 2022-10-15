#include <iostream>

using namespace std;

long long int dArry[1000001][2];

long long int dpMem(int x)
{
	dArry[0][0] = 1;
	dArry[1][0] = 2;
	dArry[2][0] = 7;
	dArry[2][1] = 0;

	for (int i = 3; i <= x; i++)
	{
		dArry[i][1] = (dArry[i - 1][1] + dArry[i - 3][0]) % 1000000007;
		dArry[i][0] = (2 * dArry[i - 1][0] + 3 * dArry[i - 2][0] + 2 * dArry[i][1]) % 1000000007;
	}

	return dArry[x][0];
}


int main()
{
	int n;
	cin >> n;
	cout << dpMem(n) << endl;
    return 0;
}