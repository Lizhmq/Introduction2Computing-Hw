#include <iostream>
#include <cstring>
using namespace std;

int cnt;
int m, n;
char grid[20][20];
void dfs(int x, int y)
{
	if (x >= m || x < 0 || y >= n || y < 0)
		return;
	if (grid[x][y] == '#')
		return;
	cnt++;
	grid[x][y] = '#';
	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };
	for (int i = 0; i < 4; ++i)
		dfs(x + dx[i], y + dy[i]);
}

int main()
{
	while (cin >> n >> m && m) {
		int x, y;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) {
				cin >> grid[i][j];
				if (grid[i][j] == '@')
					x = i, y = j;
			}
		cnt = 0;
		dfs(x, y);
		cout << cnt << endl;
	}
	return 0;
}