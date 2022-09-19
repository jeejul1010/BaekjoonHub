#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dist[100][100];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(int x, int y, vector<vector<char>>& m, int& N, int& M)
{
	queue<pair<int, int>> q;
	dist[x][y] = 1;
	q.push({ x,y });

	while (!q.empty())
	{
		pair<int, int> item = q.front();
		q.pop();
		int x = item.first;
		int y = item.second;

		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
			{
				continue;
			}
			if (dist[nextX][nextY] || m[nextX][nextY] == '0')
			{
				continue;
			}
			if (nextX == N - 1 && nextY == M - 1)
			{
				dist[nextX][nextY] = dist[x][y] + 1;
				return;
			}

			dist[nextX][nextY] = dist[x][y] + 1;
			q.push({ nextX, nextY });
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<char>> maze(N, vector<char>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
		}
	}

	bfs(0, 0, maze, N, M);

	cout << dist[N - 1][M - 1] << endl;
    
    return 0;
}