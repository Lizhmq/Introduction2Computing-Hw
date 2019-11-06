#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	int nums[100];
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; ++i)
			cin >> nums[i];
		sort(nums, nums + n);
		cout << nums[n / 2] << endl;
	}
	return 0;
}