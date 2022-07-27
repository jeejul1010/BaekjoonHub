#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000;

void sortingNum()
{
	int n;
	cin >> n;

	int numArr[MAX];
	for (int i = 0; i < n; i++)
	{
		cin >> numArr[i];
	}
	
	for (int j = n - 1; j >= 1; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (numArr[i] > numArr[i + 1])
			{
				int temp = numArr[i + 1];
				numArr[i + 1] = numArr[i];
				numArr[i] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << numArr[i] << endl;
	}

}

int main()
{
    sortingNum();
    return 0;
}