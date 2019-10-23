#include <iostream>
using namespace std;

int main()
{
	int n, k, nums[1000];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	cin >> k;
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - 1 - i; ++j)
			if (nums[j] < nums[j + 1])
				swap(nums[j], nums[j + 1]);
	for (int i = 0; i < k; ++i)
		cout << nums[i] << endl;
	return 0;
}