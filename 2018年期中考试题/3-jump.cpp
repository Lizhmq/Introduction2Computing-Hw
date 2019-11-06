#include <iostream>
using namespace std;

int main()
{
	int nums[30], n;
	bool visited[30] = {false};
	nums[0] = 1;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> nums[i];
	int res = 0, idx = 0;
	while (true) {
		if (idx > n)
			break;
		if (idx < 0)
			idx = 0;
		if (visited[idx]) {
			idx += 1;
			res += 2;
		} else if (nums[idx] == 0) {
			visited[idx] = true;
			res += 2;
			idx += 1;
		} else {
			res += 1;
			visited[idx] = true;
			idx += nums[idx];
		}
	}
	cout << res << endl;
	return 0;
}
