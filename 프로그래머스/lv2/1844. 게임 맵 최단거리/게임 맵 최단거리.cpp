#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Coord {
public:
	int x;
	int y;
	int dist;
	Coord(int _x, int _y, int _dist) {
		x = _x;
		y = _y;
		dist = _dist;
	}
};


int solution(vector<vector<int>> maps)
{
	int n = maps.size();
	int m = maps[0].size();

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	queue<Coord> q;
	q.push(Coord( 0, 0, 1 ));
    visited[0][0] = true;

	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {-1, 0, 1, 0};

	while (!q.empty())
	{
		Coord front = q.front();
		q.pop();

		int nowX = front.x;
		int nowY = front.y;
		int nowDist = front.dist;


		for (int i = 0; i < 4; i++)
		{
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];

			if (nextX == n-1 && nextY == m - 1)
			{
				return nowDist + 1;
			}

			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
			{
				continue;
			}
			if (maps[nextX][nextY] == 0 || visited[nextX][nextY] == true)
			{
				continue;
			}

			visited[nextX][nextY] = true;
			q.push(Coord(nextX, nextY, nowDist + 1));

		}

	}

	if (!visited[n - 1][m - 1])
	{
		return -1;
	}
	
}