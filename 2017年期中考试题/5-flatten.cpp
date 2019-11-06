#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main()
{
	int m, n, nums[100][100];
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> nums[i][j];
	for (int k = 0; k < m + n - 1; ++k) {
		int i = 0, j = k;
		if (j >= n) {
			j = n - 1;
			i = k - j;
		}
		while (i < m && j >= 0) {
			cout << nums[i][j] << endl;
			i++, j--;
		}
	}
	return 0;
}