#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int gcd(int x, int y) { return x == 0 ? y : gcd(y % x, x); }

int main()
{
	int n;
	int nums[200];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	sort(nums, nums + n);
	bool flag = false;
	for (int i = 0; i < n - 1; ++i) {
		if (nums[i] == 0)
			continue;
		for (int j = i + 1; j < n; ++j) {
			if (gcd(nums[i], nums[j]) == 1) {
				if (!flag) {
					flag = true;
					printf("%d/%d", nums[i], nums[j]);
				} else {
					printf(",%d/%d", nums[i], nums[j]);
				}
			}
		}
	}
	if (!flag)
		cout << "NO";
	cout << endl;
	return 0;
}