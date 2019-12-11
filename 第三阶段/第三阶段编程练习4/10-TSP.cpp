#include <cstring>
#include <iostream>
using namespace std;

int cost[15][15];
int mem[1 << 15][15];
bool visited[15];
int n;

void dfs(int depth, int curpos, int curcost, int state)
{
	if (depth == n - 1) {
		mem[(1 << n) - 1][0] = min((unsigned)mem[(1 << n) - 1][0], unsigned(curcost + cost[curpos][0]));
		return;
	}
	for (int i = 1; i < n; ++i) {
		if (visited[i])
			continue;
		int nextstate = state | (1 << i);
		int nextcost = curcost + cost[curpos][i];
		if (mem[nextstate][i] > 0 && mem[nextstate][i] <= nextcost)
			continue;
		mem[nextstate][i] = nextcost;
		visited[i] = true;
		dfs(depth + 1, i, nextcost, nextstate);
		visited[i] = false;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> cost[i][j];
	memset(mem, -1, sizeof(mem));
	dfs(0, 0, 0, 0);
	cout << mem[(1 << n) - 1][0] << endl;
	return 0;
}