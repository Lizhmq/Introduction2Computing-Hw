#include <iostream>
using namespace std;

int nums[40][10000];
int idxs[40];

int cal(int n)
{
	int res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main()
{

	char c;
	int m, n, k;
	cin >> m >> c >> n >> c >> k;
	for (int i = m + 1; i < n; ++i) {
		int p = cal(i);
		if (p % k == 0) {
			nums[p / k][idxs[p / k]] = i;
			idxs[p / k]++;
		}
	}
	for (int i = 0; i < 40; ++i) {
		for (int j = 0; j < idxs[i]; ++j) {
			if (j > 0)
				cout << ',';
			cout << nums[i][j];
			if (j == idxs[i] - 1)
				cout << endl;
		}
	}
	return 0;
}