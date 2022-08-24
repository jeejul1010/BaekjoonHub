#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string wb[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string bw[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"	
};

vector<string> board;

void getBoardInput(int row)
{
	string temp;

	for (int i = 0; i < row; i++)
	{
		cin >> temp;
		board.push_back(temp);
	}
}

int wb_cnt(int x, int y)
{
	int cnt = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[x + i][y + j] != wb[i][j])
			{
				cnt++;
			}
		}
	}

	return cnt;
}

int bw_cnt(int x, int y)
{
	int cnt = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[x + i][y + j] != bw[i][j])
			{
				cnt++;
			}
		}
	}

	return cnt;
}


int main()
{
	int N, M;
	cin >> N >> M;

	getBoardInput(N);

	int min_cnt = 70;

	for (int i = 0; i + 8 <= N; i++)
	{
		for (int j = 0; j + 8 <= M; j++)
		{
			int minimum = min(wb_cnt(i, j), bw_cnt(i, j));

			if (minimum < min_cnt)
			{
				min_cnt = minimum;
			}

		}
	}

	cout << min_cnt;

    return 0;
}