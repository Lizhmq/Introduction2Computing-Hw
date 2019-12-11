#include <iostream>
using namespace std;

int res;

int cal(int mat[][7], int n, int offset[])
{
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		int tmp = 0;
		for (int j = 0; j < n; ++j)
			tmp += mat[j][(i + offset[j]) % n];
		ret = max(ret, tmp);
	}
	return ret;
}

void dfs(int mat[][7], int depth, int n, int offset[])
{
	if (depth == n) {
		res = min(res, cal(mat, n, offset));
		return;
	}
	for (int i = 0; i < n; ++i) {
		offset[depth] = i;
		dfs(mat, depth + 1, n, offset);
	}
	return;
}

int main()
{
	int n, mat[7][7], offset[7];
	while (cin >> n && n > 0) {
		res = 100000;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> mat[i][j];
		dfs(mat, 0, n, offset);
		cout << res << endl;
	}
	return 0;
}