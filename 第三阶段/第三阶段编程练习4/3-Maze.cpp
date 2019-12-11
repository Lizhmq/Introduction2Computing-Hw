#include <iostream>
#include <cstring>
using namespace std;

int n;

char m[100][100];
bool visited[100][100];

bool dfs(int sx, int sy, int ex, int ey)
{
	if (sx >= n || sx < 0 || sy >= n || sy < 0)
		return false;
	if (visited[sx][sy] || m[sx][sy] == '#')
		return false;
	if (sx == ex && sy == ey)
		return true;
	visited[sx][sy] = true;
	int dx[] = { 0, 1, 0, - 1};
	int dy[] = { 1, 0, -1, 0 };
	for (int i = 0; i < 4; ++i)
		if (dfs(sx + dx[i], sy + dy[i], ex, ey))
			return true;
	return false;
}

int main()
{
	int k;
	cin >> k;
	while (k--) {
		memset(visited, 0, sizeof(visited));
		cin >> n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> m[i][j];
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		cout << (dfs(sx, sy, ex, ey) ? "YES" : "NO") << endl;
	}
	return 0;
}