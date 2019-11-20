#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int nums[100][100];
bool visited[100][100];

void dfs(int i, int j, int m, int n)
{
	if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || nums[i][j] == 0)
		return;
	visited[i][j] = true;
	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };
	for (int dir = 0; dir < 4; ++dir)
		dfs(i + dx[dir], j + dy[dir], m, n);
	return;
}

int main()
{
	
	int m, n, res = 0;
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> nums[i][j];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			if (visited[i][j] || nums[i][j] == 0)
				continue;
			res += 1;
			dfs(i, j, m, n);
		}
	cout << res << endl;
	return 0;
}
