#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (!isalpha(cin.peek())) {
		cin >> n;
		cin.get();	// remove '\n'
		char nums[40];
		memset(nums, '0', sizeof(nums));
		bool neg = n < 0;
		n = n < 0 ? -n : n;	// assume n is not INT_MIN
		int idx = 1;	// preserve nums[0] for '\0'
		while (n) {
			nums[idx++] = n % 2 + '0';
			n /= 2;
		}
		if (neg) {
			for (int i = 1; i < 33; ++i)
				nums[i] = (1 - (nums[i] - '0')) + '0';
			nums[1] += 1;
			for (int i = 1; i < 33; ++i) {
				nums[i + 1] += (nums[i] - '0') / 2;
				nums[i] = (nums[i] - '0') % 2 + '0';
			}
		}
		nums[0] = '\0';
		reverse(nums, nums + 33);
		cout << nums << endl;
	}
	return 0;
}