#include <cstring>
#include <iostream>
using namespace std;

int n, m;
int edge1[10][10][10];
int edge2[10][10][10];
int edgecnt[10][10];
int pv[10][10][10];
bool visited[10];
int mincost = 1e8;

void dfs(int depth, int cost, int cur)
{
	if (cur == n - 1) {
		mincost = min(mincost, cost);
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (visited[i])
			continue;
		for (int j = 0; j < edgecnt[cur][i]; ++j) {
			int path = visited[pv[cur][i][j]] ? edge1[cur][i][j] : edge2[cur][i][j];
			visited[i] = true;
			dfs(depth + 1, cost + path, i);
			visited[i] = false;
		} 
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		from -= 1;
		to -= 1;
		cin >> pv[from][to][edgecnt[from][to]] >> edge1[from][to][edgecnt[from][to]] >> edge2[from][to][edgecnt[from][to]];
		pv[from][to][edgecnt[from][to]] -= 1;
		edgecnt[from][to] += 1;
	}
	visited[0] = true;
	dfs(1, 0, 0);
	if (mincost == 1e8)
		cout << "impossible" << endl;
	else
		cout << mincost << endl;
	return 0;
}