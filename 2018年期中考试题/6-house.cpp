#include <iostream>
using namespace std;

bool judge(int mat[][20], int i, int j, int k, int l)
{
	for (int x = i; x < j; ++x)
		for (int y = k; y < l; ++y)
			if (mat[x][y] != 0)
				return false;
	return true;
}

int main()
{
	int m, n, mat[20][20];
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> mat[i][j];
	int res = 0;
	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j <= m; ++j)
			for (int k = 0; k < n; ++k)
				for (int l = k + 1; l <= n; ++l)
					if (judge(mat, i, j, k, l))
						res = max(res, (j - i) * (l - k));
	cout << res << endl;
	return 0;
}