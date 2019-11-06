#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	int n, num[100][100], mem[100][100];
	int arr[10000], idx = 0;
	int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0}, dir = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> num[i][j];
	memset(mem, 0, sizeof(mem));
	int x = 0, y = 0, cnt = 0;
	while (cnt < n * n) {
		arr[idx++] = num[x][y];
		mem[x][y] = 1;
		int xx = x + dx[dir];
		int yy = y + dy[dir];
		if (xx < 0 || xx >= n || yy < 0 || yy >= n || mem[xx][yy]) {
			dir = (dir + 1) % 4;
			xx = x + dx[dir];
			yy = y + dy[dir];
		}
		x = xx, y = yy;
		cnt++;
	}
	bool flag = false;
	int i = 0, j = n * n - 1;
	for (int t = 0; t < n * n / 2; ++t) {
		if (!flag) {
			cout << arr[t];
			flag = true;
		} else {
			cout << ' ' << arr[t];
		}
		cout << ' ' << arr[n * n - 1 - t];
	}
	if (n % 2 == 1) {
		if (flag)
			cout << ' ';
		cout << arr[n * n / 2];
	}
	cout << endl;
	return 0;
}