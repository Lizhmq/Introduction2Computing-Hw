#include <iostream>
using namespace std;

int main()
{
	char grids[100][100];
	int n, k;
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> grids[i][j];
	cin >> k;
	while (--k) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (grids[i][j] != '@')
					continue;
				for (int k = 0; k < 4; ++k) {
					int ii = i + dx[k];
					int jj = j + dy[k];
					if (ii < 0 || ii >= n || jj < 0 || jj >= n)
						continue;
					if (grids[ii][jj] == '.')
						grids[ii][jj] = '!';
				}
			}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (grids[i][j] == '!')
					grids[i][j] = '@';
	}
	int sum = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			sum += grids[i][j] == '@';
	cout << sum << endl;
	return 0;
}