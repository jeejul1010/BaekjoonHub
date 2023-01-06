#include <iostream>
#include <vector>
#include <queue>

const int vertex = 20001;
const int INF = 987654321;


using namespace std;

vector<pair<int, int>> edge[vertex];
vector<int> minDist(vertex, INF);

void dijkstra(int start);


int main()
{
	std::ios::sync_with_stdio(false);

	int V, E, K;
	cin >> V >> E >> K;

	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		edge[u].push_back(make_pair(v, w));
	}

	minDist[K] = 0;

	dijkstra(K);

	for (int i = 1; i <= V; i++)
	{
		if (minDist[i] == INF)
		{
			cout << "INF" << endl;
		}
		else
		{
			cout << minDist[i] << endl;
		}
	}
    
    return 0;
}

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int shortestDist = pq.top().first;
		int chosenVertex = pq.top().second;

		pq.pop();

		if (minDist[chosenVertex] < shortestDist)
		{
			continue;
		}

		for (int i = 0; i < edge[chosenVertex].size(); i++)
		{
			int neighbor = edge[chosenVertex][i].first;
			int weight = edge[chosenVertex][i].second;

			if (minDist[neighbor] > shortestDist + weight)
			{
				minDist[neighbor] = shortestDist + weight;
				pq.push(make_pair(minDist[neighbor], neighbor));
			}
		}
	}


}