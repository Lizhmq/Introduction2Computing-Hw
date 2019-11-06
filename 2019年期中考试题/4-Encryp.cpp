#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int m, n;
	char s[110], fill[220];
	char matrix[11][11];
	bool visited[11][11];
	cin >> m >> n;
	cin.get();
	cin.getline(s, 102);
	int l = strlen(s);
	int idx = 0;
	for (int i = 0; i < l; ++i) {
		int num = s[i] == ' ' ? 0 : s[i] - 'A' + 1;
		fill[idx++] = num / 10 + '0';
		fill[idx++] = num % 10 + '0';
	}
	for (int i = l * 2; i < m * n; ++i)
		fill[idx++] = '0';
	fill[idx] = '\0';
	memset(visited, false, sizeof(visited));
	memset(matrix, 0, sizeof(matrix));
	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };
	int dir = 0, i = 0, j = 0, cnt = 0;
	while (cnt < m * n) {
		matrix[i][j] = fill[cnt++];
		visited[i][j] = true;
		int ii = i + dx[dir], jj = j + dy[dir];
		if (ii >= m || ii < 0 || jj >= n || jj < 0 || visited[ii][jj])
			dir = (dir + 1) % 4;		
		i = i + dx[dir], j = j + dy[dir];
	}
	for (int i = 0; i < m; ++i)
		cout << matrix[i];
	cout << endl;
	return 0;
}