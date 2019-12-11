#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char grids[200][200];
bool visited[200][200];

void dfs(int i, int j, int m, int n)
{
	if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grids[i][j] != '#')
		return;
	visited[i][j] = true;
	int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	for (int dir = 0; dir < 8; ++dir)
		dfs(i + dx[dir], j + dy[dir], m, n);
	return;
}

int main()
{
	
	int m, n, res = 0;
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> grids[i][j];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			if (visited[i][j] || grids[i][j] != '#')
				continue;
			res += 1;
			dfs(i, j, m, n);
		}
	cout << res << endl;
	return 0;
}