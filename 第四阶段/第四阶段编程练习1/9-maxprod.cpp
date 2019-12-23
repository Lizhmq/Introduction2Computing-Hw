#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int nums[100];
	int i = 0;
	while (n >= i + 2) {
		nums[i] = i + 2;
		n -= i + 2;
		i++;
	}
	while (n > 0) {
		for (int j = i - 1; n > 0 && j >= 0; j--, n--)
			nums[j] += 1;
	}
	for (int j = 0; j < i - 1; ++j)
		cout << nums[j] << ' ';
	cout << nums[i - 1] << endl;
	return 0;
}