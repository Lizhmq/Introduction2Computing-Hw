#include <iostream>
using namespace std;

int main()
{
	int nums[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	int res = 0;
	int maxn = nums[0];
	for (int i = 1; i < n; ++i)
		maxn = max(maxn, nums[i]);
	for (int i = 0; i < n; ++i)
		res += maxn == nums[i] ? 0 : nums[i];
	cout << res << endl;
	return 0;
}