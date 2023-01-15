#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000000;
const int num = 100001;

bool v[num] = { false, };

void hidenseek3()
{
	int N, K;
	cin >> N >> K;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push(make_pair(0, N));
	v[N] = true;

	while (!pq.empty())
	{
		int current = pq.top().second;
		int minDist = pq.top().first;
		pq.pop();

		if (current == K)
		{
			cout << minDist << endl;
			break;
		}

		if (2 * current < num && !v[2 * current])
		{
			pq.push(make_pair(minDist, 2 * current));
			v[2 * current] = true;
		}
		if (current-1 >= 0 && !v[current-1])
		{
			pq.push(make_pair(minDist+1, current-1));
			v[current - 1] = true;
		}
		if (current+1 < num && !v[current+1])
		{
			pq.push(make_pair(minDist+1, current+1));
			v[current + 1] = true;
		}

	}

}

int main()
{
    hidenseek3();
    return 0;
}