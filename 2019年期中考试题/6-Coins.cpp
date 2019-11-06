#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int nums[100010], presum[100010];

int main()
{
	int n, k;
	presum[0] = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> nums[i];
		presum[i] = nums[i] + presum[i - 1];
	}
	int minn = presum[n];
	for (int i = n - k; i <= n; ++i)
		minn = min(minn, presum[i] - presum[i - n + k]);
	cout << presum[n] - minn << endl;
	return 0;
}