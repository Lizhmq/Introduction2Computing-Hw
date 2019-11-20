#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool dfs(int nums[], int depth, int n, int prod, bool got)
{					// got means at least one element has been used
	if (depth == n)
		return got && prod == 1;
	if (dfs(nums, depth + 1, n, prod, got))
		return true;
	if (prod == 0 && nums[depth] == 0)
		return true;
	if (nums[depth] != 0 && prod % nums[depth] == 0)
		return dfs(nums, depth + 1, n, prod / nums[depth], true);
	return false;
}

int main()
{
	char useless[100];
	int prod;
	while (cin >> prod) {
		int n, nums[20];
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> nums[i];
		cout << (dfs(nums, 0, n, prod, false) ? "YES" : "NO") << endl;
	}
	return 0;
}