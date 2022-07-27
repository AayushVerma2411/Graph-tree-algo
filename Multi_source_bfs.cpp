#include <bits/stdc++.h>
using namespace std;
bool visited[1001][1001];
char val[1001][1001];
int level[1001][1001];
int n, m;

vector<pair<int, int>> movements
{
	{-1, 0}, {1, 0}, {0, 1}, {0, -1}    // LEFT,RIGHT,UP,DOWN
};

bool is_valid(int x, int y)
{
	if (x < n && y < m)
		return 1;                //check if current node is valid
	else
		return 0;
}
int bfs()
{
	int i, j;
	queue<pair<int, int>> q;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (val[i][j] == '#')
			{
				q.push({i, j});    // push all the sources in the queue
				visited[i][j] = 1;
				level[i][j] = 0;
			}
		}
	}
	int ans = 0;
	while (!q.empty())   // now run same as bfs
	{
		auto v = q.front();
		int child_x = v.first;
		int child_y = v.second;
		q.pop();
		for (auto move : movements)
		{
			int curr_x = child_x + move.first;
			int curr_y = child_y + move.second;
			if (!is_valid(curr_x, curr_y))
				continue;
			if (visited[child_x][child_y])
				continue;
			level[curr_x][curr_y] = level[child_x][child_y] + 1;
			//cout<<"x"<<curr_x<<" "<<"y"<<curr_y<<" "<<level[curr_x][curr_y]<<endl;
			visited[curr_x][curr_y] = 1;
			q.push({curr_x,curr_y});
			ans = max(ans, level[curr_x][curr_y]);
		}
	}
	return ans;
}

int main()
{
	int i, j, k;
	cin >> n >> m;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> val[i][j];
			visited[i][j] = false;
			level[i][j] = 0;
		}
	}
	cout << bfs() << endl;
}