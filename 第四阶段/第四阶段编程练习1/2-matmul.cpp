#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int m, n, k;
	int a[100][100], b[100][100], c[100][100];
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				cin >> a[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < k; ++j)
				cin >> b[i][j];
		memset(c, 0, sizeof(c));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < k; ++j)
				for (int l = 0; l < n; ++l)
					c[i][j] += a[i][l] * b[l][j];
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < k - 1; ++j)
				cout << c[i][j] << ' ';
			cout << c[i][k - 1] << endl;
		}
	}
	return 0;
}