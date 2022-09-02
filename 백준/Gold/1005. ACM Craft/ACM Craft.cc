#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int T, N, K, X, Y, W;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N >> K;

		vector<int> delay(N+1, 0);
		vector<int> maxTime(N+1, 0);
		vector<int> indegree(N+1, 0);

		vector<vector<int>> neighbors(N + 1);

		for (int j = 1; j <= N; j++)
		{
			cin >> delay[j];
			maxTime[j] = delay[j];
		}

		for (int j = 0; j < K; j++)
		{
			cin >> X >> Y;
			neighbors[X].push_back(Y);
			indegree[Y]++;
		}

		cin >> W;

		queue<int> q;
		for (int j = 1; j <= N; j++)
		{
			if (indegree[j] == 0)
			{
				q.push(j);
			}
		}

		while (!q.empty())
		{
			int front = q.front();
			q.pop();

			for (int j = 0; j < neighbors[front].size(); j++)
			{
				int next = neighbors[front][j];
				maxTime[next] = max(maxTime[next], maxTime[front] + delay[next]);

				if (--indegree[next] == 0)
				{
					q.push(next);
				}
			}
		}

		cout << maxTime[W] << endl;
        
	}

	return 0;
}
