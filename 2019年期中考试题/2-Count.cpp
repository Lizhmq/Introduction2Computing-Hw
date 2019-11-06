#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int upper, x;
	cin >> upper >> x;
	int cnt[10] = { 0 };
	for (int i = 1; i <= upper; ++i) {
		int tmp = i;
		while (tmp) {
			cnt[tmp % 10]++;
			tmp /= 10;
		}
	}
	cout << cnt[x] << endl;
	return 0;
}