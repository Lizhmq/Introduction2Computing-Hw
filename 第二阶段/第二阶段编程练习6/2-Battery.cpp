#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	int nums[1000];
	ios::sync_with_stdio(false);
	while (cin >> n) {
		double sum = 0, res, maxn = -1;
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
			maxn = max(maxn, 1.0 * nums[i]);
			sum += nums[i];
		}
		if (maxn * 2 > sum)
			res = sum - maxn;
		else
			res = sum / 2;
		printf("%.1lf\n", res);
	}
	return 0;
}