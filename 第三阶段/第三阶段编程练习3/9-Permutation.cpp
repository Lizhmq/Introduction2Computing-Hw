#include <iostream>
#include <cstring>
using namespace std;

void dfs(char s[], int depth, int n, int visited[], int idx[])
{
	if (depth == n) {
		for (int i = 0; i < n; ++i)
			cout << s[idx[i]];
		cout << endl;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			idx[depth] = i;
			dfs(s, depth + 1, n, visited, idx);
			visited[i] = false;
		}
	}
	return;
}

int main()
{
	char s[7];
	int visited[6] = { 0 }, idx[6];
	cin >> s;
	dfs(s, 0, strlen(s), visited, idx);
	return 0;
}