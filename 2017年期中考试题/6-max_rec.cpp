#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int num[20000];

int main()
{
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	for (int i = 0; i < n; ++i) {
		int minh = num[i];
		for (int j = i; j < n; ++j) {
			minh = min(minh, num[j]);
			res = max(res, minh * (j - i + 1));
		}
	}
	cout << res << endl;
	return 0;
}