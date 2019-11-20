#include <iostream>
#include <cstring>
using namespace std;

bool dfs(int x, int y, int m, int n, int nums[][50], bool visited[][50])
{
	if (x >= m || x < 0 || y >= n || y < 0 || visited[x][y] || nums[x][y] == 1)
		return false;
	if (nums[x][y] == 3)
		return true;
	visited[x][y] = true;
	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };
	for (int i = 0; i < 4; ++i)
		if (dfs(x + dx[i], y + dy[i], m, n, nums, visited))
			return true;
	return false;
}

int main()
{
	int m, n, nums[50][50], startx, starty;
	bool visited[50][50];
	memset(visited, 0, sizeof(visited));
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> nums[i][j];
			if (nums[i][j] == 2)
				startx = i, starty = j;
		}
	cout << (dfs(startx, starty, m, n, nums, visited) ? "Yes" : "No") << endl;
	return 0;
}