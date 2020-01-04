#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int K;
	cin >> K;
	for (int h = 0; h < K; ++h) {
		int t, n, tmp;
		double res = 0;
		cin >> n >> t;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			double p = i * (n - i) + (n - i - 1) * (i + 1) + n;
			p = p / n / n;
			double p1 = (1 - pow(1 - 2 * p, 1.0 * t)) / 2;	// 伯努利事件发生奇数次的概率，二项式定理
			double p2 = 1 - p1;
			if (tmp == 1)
				swap(p1, p2);
			res += p1;
		}
		printf("Case #%d: %.4lf\n", h + 1, res);
	}
	return 0;
}